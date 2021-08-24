// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "Special.h"
#include "MultiGenerate.h"

std::vector<MemoryWrite<int>> Special::writeInt;
std::vector<MemoryWrite<float>> Special::writeFloat;
std::vector<MemoryWrite<Color>> Special::writeColor;
std::vector<MemoryWrite<int>> Special::writeIntVec;
std::vector<MemoryWrite<float>> Special::writeFloatVec;
std::vector<MemoryWrite<Color>> Special::writeColorVec;

void Special::generateReflectionDotPuzzle(std::shared_ptr<Generate> gen, int id1, int id2, std::vector<std::pair<int, int>> symbols, Panel::Symmetry symmetry, bool split)
{
	gen->setFlagOnce(Generate::Config::DisableWrite);
	gen->generate(id1, symbols);
	std::shared_ptr<Panel> puzzle = gen->_panel;
	std::shared_ptr<Panel> flippedPuzzle = std::make_shared<Panel>(id2);
	std::vector<Point> dots;
	for (int x = 0; x < puzzle->_width; x++) {
		for (int y = 0; y < puzzle->_height; y++) {
			Point sp = puzzle->get_sym_point(x, y, symmetry);
			if (puzzle->_grid[x][y] & Decoration::Dot) {
				int symbol = (sp.first & 1) == 1 ? Decoration::Dot_Row : (sp.second & 1) == 1 ? Decoration::Dot_Column : Decoration::Dot_Intersection;
				flippedPuzzle->_grid[sp.first][sp.second] = symbol | IntersectionFlags::DOT_IS_INVISIBLE;
				dots.push_back({ x, y });
			}
			else if (puzzle->_grid[x][y] & Decoration::Gap) {
				int symbol = (sp.first & 1) == 1 ? Decoration::Gap_Row : Decoration::Gap_Column;
				flippedPuzzle->_grid[sp.first][sp.second] = symbol;
			}
			else flippedPuzzle->_grid[sp.first][sp.second] = puzzle->_grid[x][y];
		}
	}
	if (split) {
		int size = static_cast<int>(dots.size());
		while (dots.size() > size / 2 + Random::rand() % 2) {
			Point dot = pop_random(dots);
			Point sp = puzzle->get_sym_point(dot.first, dot.second, symmetry);
			puzzle->_grid[dot.first][dot.second] |= IntersectionFlags::DOT_IS_INVISIBLE;
			flippedPuzzle->_grid[sp.first][sp.second] &= ~IntersectionFlags::DOT_IS_INVISIBLE;
		}
		if (Random::rand() % 2) {
			Point dot = pop_random(dots);
			Point sp = puzzle->get_sym_point(dot.first, dot.second, symmetry);
			flippedPuzzle->_grid[sp.first][sp.second] &= ~IntersectionFlags::DOT_IS_INVISIBLE;
		}
		Color color = flippedPuzzle->_memory->ReadPanelData<Color>(id2, SUCCESS_COLOR_A);
		flippedPuzzle->_memory->WritePanelData<Color>(id2, PATTERN_POINT_COLOR, { color });
	}
	flippedPuzzle->_startpoints.clear();
	for (Point p : puzzle->_startpoints) {
		flippedPuzzle->_startpoints.push_back(puzzle->get_sym_point(p, symmetry));
	}
	flippedPuzzle->_endpoints.clear();
	for (Endpoint p : puzzle->_endpoints) {
		Point sp = puzzle->get_sym_point(p.GetX(), p.GetY(), symmetry);
		flippedPuzzle->_endpoints.push_back(Endpoint(sp.first, sp.second, gen->_panel->get_sym_dir(p.GetDir(), symmetry),
			IntersectionFlags::ENDPOINT | (p.GetDir() == Endpoint::Direction::UP || p.GetDir() == Endpoint::Direction::DOWN ? IntersectionFlags::COLUMN : IntersectionFlags::ROW)));
	}
	if (id1 == 0x00A5B && split) {
		if (checkDotSolvability(puzzle, flippedPuzzle, symmetry)) {
			generateReflectionDotPuzzle(gen, id1, id2, symbols, symmetry, split);
			return;
		}
	}
	gen->write(id1);
	flippedPuzzle->Write(id2);
}

void Special::generateAntiPuzzle(int id)
{
	while (true) {
		generator->setFlagOnce(Generate::Config::DisableWrite);
		generator->generate(id, Decoration::Poly | Decoration::Can_Rotate, 2);
		std::set<Point> open = generator->_gridpos;
		std::vector<int> symbols;
		for (int x = 1; x < generator->_panel->_width; x += 2) {
			for (int y = 1; y < generator->_panel->_height; y += 2) {
				if (generator->get_symbol_type(generator->get(x, y)) == Decoration::Poly) {
					symbols.push_back(generator->get(x, y));
					generator->set(x, y, 0);
					for (Point p : generator->get_region(Point(x, y))) {
						open.erase(p);
					}
				}
			}
		}
		if (open.size() == 0) continue;
		std::set<Point> region = generator->get_region(*open.begin());
		if (region.size() != open.size() || open.size() < symbols.size() + 1) continue;
		for (int s : symbols) {
			Point p = generator->pick_random(open);
			generator->set(p, s | Decoration::Negative);
			open.erase(p);
		}
		generator->set(generator->pick_random(open), Decoration::Poly | 0xffff0000); //Full block
		generator->write(id);
		generator->resetConfig();
		return;
	}
}

void Special::generateColorFilterPuzzle(int id, Point size, const std::vector<std::pair<int, int>>& symbols, const Color& filter)
{
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->setGridSize(size.first, size.second);
	generator->generate(id, symbols);
	std::vector<Color> availableColors = { {0, 0, 0, 1} };
	if (filter.r == 1) {
		for (int i = 0; i < availableColors.size(); i++) {
			Color c = availableColors[i];
			if (c.r == 0) availableColors.push_back({ 1, c.g, c.b, 1 });
		}
	}
	if (filter.g == 1) {
		for (int i = 0; i < availableColors.size(); i++) {
			Color c = availableColors[i];
			if (c.g == 0) availableColors.push_back({ c.r, 1, c.b, 1 });
		}
	}
	if (filter.b == 1) {
		for (int i = 0; i < availableColors.size(); i++) {
			Color c = availableColors[i];
			if (c.b == 0) availableColors.push_back({ c.r, c.g, 1, 1 });
		}
	}
	for (int i = 0; i < availableColors.size(); i++) { //Shuffle
		std::swap(availableColors[i], availableColors[Random::rand() % availableColors.size()]);
	}
	std::vector<Color> symbolColors;
	for (int y = generator->_panel->_height - 2; y>0; y -= 2) {
		for (int x = 1; x < generator->_panel->_width - 1; x += 2) {
			if (generator->get(x, y) == 0) symbolColors.push_back({ 0, 0, 0, 0 });
			else symbolColors.push_back(availableColors[(generator->get(x, y) & 0xf) - 1]);
		}
	}
	bool pass = false;
	while (!pass) {
		//Add random variation in remaining color channel(s)
		for (Color &c : symbolColors) {
			if (c.a == 0) continue;
			if (filter.r == 0) c.r = static_cast<float>(Random::rand() % 2);
			if (filter.g == 0) c.g = static_cast<float>(Random::rand() % 2);
			if (filter.b == 0) c.b = static_cast<float>(Random::rand() % 2);
		}
		//Check for solvability
		std::map<Color, int> colorCounts;
		for (Color &c : symbolColors) {
			colorCounts[c]++;
		}
		for (auto pair : colorCounts) {
			if (pair.second % 2) {
				pass = true;
				break;
			}
		}
	}
	generator->setFlagOnce(Generate::Config::WriteColors);
	generator->write(id);
	WriteArray(id, DECORATION_COLORS, symbolColors);
	generator->resetConfig();
}

void Special::generateSoundDotPuzzle(int id1, int id2, std::vector<int> dotSequence, bool writeSequence) {
	generator->setFlag(Generate::Config::DisableReset);
	generateSoundDotPuzzle(id1, { 5, 5 }, dotSequence, writeSequence);
	generator->write(id2);
	WritePanelData(id2, PATTERN_POINT_COLOR, ReadPanelData<Color>(id2, SUCCESS_COLOR_A));
	generator->resetConfig();
}

void Special::generateSoundDotPuzzle(int id, Point size, std::vector<int> dotSequence, bool writeSequence) {
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->setFlagOnce(Generate::Config::LongPath);
	generator->setGridSize(size.first, size.second);
	if (id == 0x014B2) { //Have to force there to only be one correct sequence
		generator->generate(id, Decoration::Dot_Intersection, static_cast<int>(dotSequence.size() - 1));
		while (generator->get(6, 0) == Decoration::Dot_Intersection || generator->get(8, 2) == Decoration::Dot_Intersection)
			generator->generate(id, Decoration::Dot_Intersection, static_cast<int>(dotSequence.size() - 1));
		if (generator->get(7, 0) == PATH) generator->set(7, 0, Decoration::Dot_Row);
		else generator->set(8, 1, Decoration::Dot_Column);
	}
	else generator->generate(id, Decoration::Dot_Intersection, static_cast<int>(dotSequence.size()));
	Point p = *generator->_starts.begin();
	std::set<Point> path = generator->_path;
	int seqPos = 0;
	while (!generator->_exits.count(p)) {
		path.erase(p);
		int sym = generator->get(p);
		if (sym & Decoration::Dot) {
			generator->set(p, sym | dotSequence[seqPos++]);
		}
		for (Point dir : Generate::_DIRECTIONS1) {
			Point newp = p + dir;
			if (path.count(newp)) {
				p = newp;
				break;
			}
		}
	}
	if (writeSequence) {
		for (int i = 0; i < dotSequence.size(); i++) {
			if (dotSequence[i] == DOT_SMALL) dotSequence[i] = 1;
			if (dotSequence[i] == DOT_MEDIUM) dotSequence[i] = 2;
			if (dotSequence[i] == DOT_LARGE) dotSequence[i] = 3;
		}
		WritePanelData(id, DOT_SEQUENCE_LEN, { static_cast<int>(dotSequence.size()) });
		WriteArray(id, DOT_SEQUENCE, dotSequence, true);
	}
	generator->write(id);
}

void Special::generateSoundDotReflectionPuzzle(int id, Point size, std::vector<int> dotSequence1, std::vector<int> dotSequence2, int numColored, bool writeSequence)
{
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->setFlagOnce(Generate::Config::LongPath);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->setGridSize(size.first, size.second);
	if (id != 0x00AFB) {
		WritePanelData(id, SUCCESS_COLOR_B, ReadPanelData<Color>(id, SUCCESS_COLOR_A));
		generator->setSymbol(Decoration::Start, 0, generator->_height - 1); generator->setSymbol(Decoration::Start, generator->_width - 1, 0);
		generator->setSymbol(Decoration::Exit, 0, 0); generator->setSymbol(Decoration::Exit, generator->_width - 1, generator->_height - 1);
	}
	if (id == 0x00C3F || id == 0x00C41) {
		generator->generate(id, Decoration::Dot_Intersection | Decoration::Color::Blue, static_cast<int>(dotSequence1.size()), Decoration::Dot_Intersection | Decoration::Color::Yellow, static_cast<int>(dotSequence2.size() - 1));
	}
	else if (id == 0x014B2) {
		generator->generate(id, Decoration::Dot_Intersection | Decoration::Color::Blue, static_cast<int>(dotSequence1.size() - 1), Decoration::Dot_Intersection | Decoration::Color::Yellow, static_cast<int>(dotSequence2.size() - 1));
	}
	else if (id == 0x00AFB && writeSequence) {
		while (!generateSoundDotReflectionSpecial(id, size, dotSequence1, dotSequence2, numColored));
		return;
	}
	else generator->generate(id, Decoration::Dot_Intersection | Decoration::Color::Blue, static_cast<int>(dotSequence1.size()), Decoration::Dot_Intersection | Decoration::Color::Yellow, static_cast<int>(dotSequence2.size()));
	std::set<Point> path1 = generator->_path1, path2 = generator->_path2;
	Point p1, p2;
	std::set<Point> dots1, dots2;
	for (Point p : generator->_starts) {
		if (generator->_path1.count(p)) p1 = p;
		if (generator->_path2.count(p)) p2 = p;
	}
	int seqPos = 0;
	while (!generator->_exits.count(p1)) {
		path1.erase(p1);
		int sym = generator->get(p1);
		if (sym & Decoration::Dot) {
			generator->set(p1, sym | dotSequence1[seqPos++]);
			dots1.insert(p1);
		}
		for (Point dir : Generate::_DIRECTIONS1) {
			Point newp = p1 + dir;
			if (path1.count(newp)) {
				p1 = newp;
				break;
			}
		}
	}
	if (id == 0x014B2) {
		generator->set(p1, dotSequence1[seqPos] | Decoration::Dot_Intersection | IntersectionFlags::DOT_IS_ORANGE);
		numColored++;
	}
	seqPos = 0;
	if (id == 0x00C3F || id == 0x00C41 || id == 0x014B2) {
		generator->set(p2, Decoration::Dot_Intersection | IntersectionFlags::DOT_IS_BLUE);
		generator->setFlagOnce(Generate::Config::Write2Color);
		numColored++;
	}
	while (!generator->_exits.count(p2)) {
		path2.erase(p2);
		int sym = generator->get(p2);
		if (sym & Decoration::Dot) {
			generator->set(p2, sym | dotSequence2[seqPos++]);
			if (!generator->_starts.count(p2)) dots2.insert(p2);
		}
		for (Point dir : Generate::_DIRECTIONS1) {
			Point newp = p2 + dir;
			if (path2.count(newp)) {
				p2 = newp;
				break;
			}
		}
	}
	for (int i = static_cast<int>(dotSequence1.size() + dotSequence2.size()); i > numColored; i--) {
		if (i % 2 == 0) { //Want to evenly distribute colors between blue/orange (approximately)
			Point p = pop_random(dots1);
			generator->set(p, generator->get(p) & ~DOT_IS_BLUE); //Remove color
		}
		else {
			Point p = pop_random(dots2);
			generator->set(p, generator->get(p) & ~DOT_IS_ORANGE); //Remove color
		}
	}
	if (writeSequence) {
		for (int i = 0; i < dotSequence1.size(); i++) {
			if (dotSequence1[i] == DOT_SMALL) dotSequence1[i] = 1;
			if (dotSequence1[i] == DOT_MEDIUM) dotSequence1[i] = 2;
			if (dotSequence1[i] == DOT_LARGE) dotSequence1[i] = 3;
		}
		WritePanelData(id, DOT_SEQUENCE_LEN, { static_cast<int>(dotSequence1.size()) });
		WriteArray(id, DOT_SEQUENCE, dotSequence1, true);
		for (int i = 0; i < dotSequence2.size(); i++) {
			if (dotSequence2[i] == DOT_SMALL) dotSequence2[i] = 1;
			if (dotSequence2[i] == DOT_MEDIUM) dotSequence2[i] = 2;
			if (dotSequence2[i] == DOT_LARGE) dotSequence2[i] = 3;
		}
		WritePanelData(id, DOT_SEQUENCE_LEN, { static_cast<int>(dotSequence2.size()) });
		WriteArray(id, DOT_SEQUENCE, dotSequence2, true);
	}
	generator->write(id);
	generator->setSymmetry(Panel::Symmetry::None);
}

bool Special::generateSoundDotReflectionSpecial(int id, Point size, std::vector<int> dotSequence1, std::vector<int> dotSequence2, int numColored) {
	generator->resetConfig();
	generator->resetVars();
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->setFlagOnce(Generate::Config::LongPath);
	generator->setSymmetry(Panel::Symmetry::RotateLeft);
	generator->setGridSize(size.first, size.second);
	std::vector<Point> starts = { { 0, 0 },{ generator->_width - 1, 0 },{ 0, generator->_height - 1 },{ generator->_width - 1, generator->_height - 1 } };
	Point start = pick_random<Point>(starts);
	generator->setSymbol(Decoration::Start, start.first, start.second);
	generator->setSymbol(Decoration::Exit, 6, 0); generator->setSymbol(Decoration::Exit, generator->_width - 1, 6);
	generator->setSymbol(Decoration::Exit, 0, generator->_height - 7); generator->setSymbol(Decoration::Exit, generator->_width - 7, generator->_height - 1);
	generator->generate(id, Decoration::Dot_Intersection | Decoration::Color::Blue, static_cast<int>(dotSequence1.size() - 1), Decoration::Dot_Intersection | Decoration::Color::Yellow, static_cast<int>(dotSequence2.size() - 1));
	std::set<Point> path1 = generator->_path1, path2 = generator->_path2;
	std::set<Point> intersect;
	for (Point p : path1) {
		if (p.first % 2 != 0 || p.second % 2 != 0)
			continue;
		if (path2.count(p)) {
			if (generator->get(p) & Decoration::Dot)
				return false;
			intersect.insert(p);
		}
	}
	Point pshared = pick_random(intersect);
	generator->set(pshared, Decoration::Dot_Intersection);
	Point p1 = start, p2 = generator->get_sym_point(start);
	std::set<Point> dots1, dots2;

	int seqPos = 0;
	while (seqPos < dotSequence1.size()) {
		path1.erase(p1);
		int sym = generator->get(p1);
		if (sym & Decoration::Dot) {
			generator->set(p1, sym | dotSequence1[seqPos++]);
			dots1.insert(p1);
		}
		for (Point dir : Generate::_DIRECTIONS1) {
			Point newp = p1 + dir;
			if (path1.count(newp)) {
				p1 = newp;
				break;
			}
		}
	}
	seqPos = 0;
	while (seqPos < dotSequence2.size()) {
		path2.erase(p2);
		int sym = generator->get(p2);
		if (sym & Decoration::Dot) {
			if ((sym & 0xf000) && ((sym & 0xf000) == IntersectionFlags::DOT_MEDIUM))
				return false;
			if ((sym & 0xf000) && (sym & 0xf000) != dotSequence2[seqPos])
				return false;
			generator->set(p2, sym | dotSequence2[seqPos++]);
			if (!generator->_starts.count(p2)) dots2.insert(p2);
		}
		for (Point dir : Generate::_DIRECTIONS1) {
			Point newp = p2 + dir;
			if (path2.count(newp)) {
				p2 = newp;
				break;
			}
		}
	}

	dots1.erase(pshared);
	dots2.erase(pshared);
	generator->set(pshared, generator->get(pshared) & (~DOT_IS_BLUE | DOT_IS_ORANGE));
	for (int i = static_cast<int>(dotSequence1.size() + dotSequence2.size()) - 2; i > numColored; i--) {
		if (i % 2 == 0) { //Want to evenly distribute colors between blue/orange (approximately)
			Point p = pop_random(dots1);
			generator->set(p, generator->get(p) & ~DOT_IS_BLUE); //Remove color
		}
		else {
			Point p = pop_random(dots2);
			generator->set(p, generator->get(p) & ~DOT_IS_ORANGE); //Remove color
		}
	}
	for (int i = 0; i < dotSequence1.size(); i++) {
		if (dotSequence1[i] == DOT_SMALL) dotSequence1[i] = 1;
		if (dotSequence1[i] == DOT_MEDIUM) dotSequence1[i] = 2;
		if (dotSequence1[i] == DOT_LARGE) dotSequence1[i] = 3;
	}
	WritePanelData(id, DOT_SEQUENCE_LEN, { static_cast<int>(dotSequence1.size()) });
	WriteArray(id, DOT_SEQUENCE, dotSequence1, true);
	for (int i = 0; i < dotSequence2.size(); i++) {
		if (dotSequence2[i] == DOT_SMALL) dotSequence2[i] = 1;
		if (dotSequence2[i] == DOT_MEDIUM) dotSequence2[i] = 2;
		if (dotSequence2[i] == DOT_LARGE) dotSequence2[i] = 3;
	}
	WritePanelData(id, DOT_SEQUENCE_LEN_REFLECTION, { static_cast<int>(dotSequence2.size()) });
	WriteArray(id, DOT_SEQUENCE_REFLECTION, dotSequence2, true);
	generator->_panel->_startpoints = { { 0, 0}, { generator->_width - 1, 0 }, { 0, generator->_height - 1 }, { generator->_width - 1, generator->_height - 1 } };
	generator->write(id);
	generator->setSymmetry(Panel::Symmetry::None);
	return true;
}

void Special::generateRGBStonePuzzleN(int id)
{
	while (true) {
		generator->setFlagOnce(Generate::Config::DisableWrite);
		generator->generate(id);
		int amount = 16;
		std::set<Decoration::Color> used;
		std::vector<Decoration::Color> colors = { Decoration::Black, Decoration::White, Decoration::Red, Decoration::Green, Decoration::Blue, Decoration::Cyan, Decoration::Yellow, Decoration::Magenta };
		while (amount > 0) {
			Decoration::Color c = generator->pick_random(colors);
			if (generator->place_stones(c, 1)) {
				amount--;
				used.insert(c);
			}
		}
		if (used.size() < 5) continue;
		generator->setFlagOnce(Generate::Config::WriteColors);
		generator->write(id);
		return;
	}
}

void Special::generateRGBStarPuzzleN(int id)
{
	while (true) {
		generator->setFlagOnce(Generate::Config::DisableWrite);
		generator->generate(id);
		int amount = 16;
		std::set<Decoration::Color> used;
		std::set<Decoration::Color> colors = { Decoration::Black, Decoration::White, Decoration::Red, Decoration::Green, Decoration::Blue, Decoration::Cyan, Decoration::Yellow, Decoration::Magenta };
		while (amount > 0) {
			Decoration::Color c = generator->pick_random(colors);
			if (generator->place_stars(c, 2)) {
				amount -= 2;
				used.insert(c);
				if (used.size() == 4) colors = used;
			}
		}
		if (used.size() < 4)
			continue;
		generator->setFlagOnce(Generate::Config::WriteColors);
		generator->write(id);
		return;
	}
}

void Special::generateRGBStonePuzzleH(int id) {
	while (true) {
		generator->setFlagOnce(Generate::Config::DisableWrite);
		generator->generate(id);
		int amount = 16;
		std::set<Decoration::Color> used;
		std::vector<Decoration::Color> colors = { Decoration::Black, Decoration::Red, Decoration::Green, Decoration::Blue, Decoration::Magenta, Decoration::Yellow };
		while (amount > 0) {
			Decoration::Color c = generator->pick_random(colors);
			if (generator->place_stones(c, 1)) {
				amount--;
				used.insert(c);
			}
		}
		if (used.size() < 5) continue;
		if (!generator->place_erasers({ Decoration::Color::White }, { Decoration::Stone | pick_random(colors) })) {
			continue;
		}
		Point eraserPos;
		for (int x = 1; x < generator->_panel->_width; x += 2) {
			for (int y = 1; y < generator->_panel->_height; y += 2) {
				if (generator->get_symbol_type(generator->get(x, y)) == Decoration::Eraser) {
					eraserPos = { x, y };
					break;
				}
			}
		}
		int count = 0;
		for (Point dir : generator->_DIRECTIONS2) {
			if (!generator->off_edge(eraserPos + dir) && generator->get(eraserPos + dir) == 0) count++;
		}
		if (count < 2) continue;
		generator->setFlagOnce(Generate::Config::WriteColors);
		generator->write(id);
		return;
	}
}

void Special::generateRGBDotPuzzleH(int id) {
	WritePanelData(id, PATTERN_POINT_COLOR, {1, 0, 0, 1});
	WritePanelData(id, PATTERN_POINT_COLOR_A, { 0, 1, 1, 1 });
	WritePanelData(id, PATTERN_POINT_COLOR_B, { 1, 1, 0, 1 });
	WritePanelData(id, ACTIVE_COLOR, { 0, 1, 1, 1 });
	WritePanelData(id, REFLECTION_PATH_COLOR, { 1, 1, 0, 1 });
	generator->setGridSize(7, 7);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->setSymbol(Decoration::Exit, 0, 14); generator->setSymbol(Decoration::Exit, 14, 0);
	generator->setSymbol(Decoration::Exit, 0, 0); generator->setSymbol(Decoration::Exit, 14, 14);
	generator->generate(id, Decoration::Dot_Intersection | Decoration::Color::Cyan, 2, Decoration::Dot_Intersection | Decoration::Color::Yellow, 4, Decoration::Dot_Intersection, 6,
		Decoration::Triangle | Decoration::Color::Orange, 4, Decoration::Start, 4);
	generator->resetConfig();
}

void Special::generateJungleVault(int id)
{
	//This panel won't render symbols off the grid, so all I can do is move the dots around

	//a: 4 9 16 23, b: 12, c: 1, ab: 3 5 6 10 11 15 17 18 20 21 22, ac: 14, bc: 2 19, all: 7 8 13
	std::vector<std::vector<int>> sols = {
		{ 0, 5, 10, 15, 20, 21, 16, 11, 6, 7, 8, 3, 4, 9, 14, 13, 18, 17, 22, 23, 24, 25 },
		{ 0, 5, 10, 15, 20, 21, 22, 17, 12, 11, 6, 7, 2, 3, 8, 13, 18, 19, 24, 25 },
		{ 0, 1, 2, 7, 8, 13, 14, 19, 24, 25 } };
	std::vector<std::vector<int>> dotPoints1 = { { 4, 9, 16, 23 }, { 2, 19 }, { 2, 19 } };
	std::vector<std::vector<int>> dotPoints2 = { { 7, 8, 13 }, { 3, 5, 6, 10, 11, 15, 17, 18, 20, 21, 22 }, { 14, 1 } };
	generator->initPanel(id);
	generator->clear();
	int sol = Random::rand() % sols.size();
	auto[x1, y1] = generator->_panel->loc_to_xy(generator->pick_random(dotPoints1[sol]));
	auto[x2, y2] = generator->_panel->loc_to_xy(generator->pick_random(dotPoints2[sol]));
	generator->set(x1, y1, Decoration::Dot_Intersection);
	generator->set(x2, y2, Decoration::Dot_Intersection);
	WritePanelData(id, SEQUENCE_LEN, static_cast<int>(sols[sol].size()));
	WriteArray(id, SEQUENCE, sols[sol], true);
	generator->write(id);
}

void Special::generateApplePuzzle(int id, bool changeExit, bool flip)
{
	//Is there a way to move the apples? Might be impossible without changing the game files.
	int numIntersections = ReadPanelData<int>(id, NUM_DOTS);
	std::vector<int> intersectionFlags = ReadArray<int>(id, DOT_FLAGS, numIntersections);
	std::vector<int> sequence = ReadArray<int>(id, SEQUENCE, 6);
	int exit = sequence[5];
	std::vector<int> exits;
	if (changeExit) {
		for (int i = 15; i < 31; i++) {
			if (intersectionFlags[i] == 9) exits.push_back(i);
		}
		int newExit = pop_random(exits);
		intersectionFlags[newExit] = 1;
		intersectionFlags[exit] = 9; //Gets rid of old exit
		for (int i = 5; i > 1; i--) {
			sequence[i] = newExit;
			newExit = (newExit - 1) / 2;
		}
		int numConnections = ReadPanelData<int>(id, NUM_CONNECTIONS);
		std::vector<int> connections_a = ReadArray<int>(id, DOT_CONNECTION_A, numConnections);
		std::vector<int> connections_b = ReadArray<int>(id, DOT_CONNECTION_B, numConnections);
		for (int i = 0; i < numConnections; i++) {
			if (connections_b[i] == exit) {
				connections_a[i] = sequence[4];
				connections_b[i] = sequence[5];
			}
		}
		WriteArray(id, DOT_FLAGS, intersectionFlags);
		WriteArray(id, SEQUENCE, sequence, true);
		WriteArray(id, DOT_CONNECTION_A, connections_a);
		WriteArray(id, DOT_CONNECTION_B, connections_b);
		WritePanelData(id, NEEDS_REDRAW, 1);
	}
	if (flip) {
		std::vector<float> intersections = ReadArray<float>(id, DOT_POSITIONS, numIntersections * 2);
		for (int i = 0; i < intersections.size(); i += 2) {
			intersections[i] = 1 - intersections[i];
		}
		WriteArray(id, DOT_POSITIONS, intersections);
		WritePanelData(id, NEEDS_REDRAW, 1);
	}
}

void Special::generateKeepLaserPuzzle(int id, const std::set<Point>& path1, const std::set<Point>& path2, const std::set<Point>& path3, const std::set<Point>& path4, std::vector<std::pair<int, int>> symbols)
{
	PuzzleSymbols psymbols(symbols);
	generator->resetConfig();
	generator->pathWidth = 0.4f;
	generator->setGridSize(10, 11);
	generator->_starts = { { 0, 2 },{ 20, 10 },{ 8, 14 },{ 0, 22 },{ 20, 22 } };
	generator->_exits = { { 0, 18 },{ 0, 0 },{ 20, 0 },{ 0, 12 } };
	if (psymbols.getNum(Decoration::Triangle) > 0) generator->_exits.insert({ 0, 22 });
	generator->initPanel(id);
	generator->clear();
	std::vector<Point> gaps = { { 17, 20 },{ 16, 19 },{ 20, 17 },{ 15, 14 },{ 15, 16 },{ 18, 13 },{ 20, 13 }, //Yellow Internal Puzzle Walls
	{ 11, 12 }, { 11, 14 }, { 11, 16 }, { 11, 18 }, { 11, 20 }, { 11, 22 }, { 10, 13 }, { 10, 15 }, { 10, 17 }, { 10, 19 }, { 10, 21 }, { 12, 13 }, { 13, 12 }, { 16, 13 }, //Yellow External Puzzle Walls
	{ 10, 11 },{ 12, 11 },{ 14, 11 },{ 16, 11 },{ 18, 11 },{ 11, 0 },{ 11, 2 },{ 11, 4 },{ 11, 8 },{ 11, 10 },{ 14, 1 },{ 16, 1 },{ 18, 1 },{ 20, 1 }, //Pink Puzzle Walls
	{ 2, 1 },{ 4, 1 },{ 6, 1 },{ 8, 1 },{ 0, 11 },{ 2, 11 },{ 4, 11 },{ 6, 11 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 9, 8 },{ 9, 10 },{ 9, 12 }, //Green Puzzle Walls
	{ 0, 13 },{ 2, 13 },{ 4, 13 },{ 6, 13 },{ 9, 14 },{ 9, 16 },{ 9, 20 },{ 9, 22 }, //Blue Puzzle Walls
	};
	std::vector<Point> pathPoints = { { 14, 13 },{ 14, 12 },{ 15, 12 },{ 16, 12 },{ 17, 12 },{ 18, 12 },{ 19, 12 },{ 20, 12 },{ 20, 11 },
	{ 11, 6 },{ 10, 6 },{ 10, 5 },{ 10, 4 },{ 10, 3 },{ 10, 2 },{ 10, 1 },{ 10, 0 },{ 9, 0 },{ 8, 0 },{ 7, 0 },{ 6, 0 },{ 5, 0 },{ 4, 0 },{ 3, 0 },
	{ 2, 0 },{ 1, 0 },{ 0, 0 },{ 0, 1 },{ 8, 11 },{ 8, 12 },{ 8, 13 } };
	std::vector<Point> pathPoints2 = { { 9, 18 },{ 10, 18 } }; //For exiting out the right side of the last puzzle
	std::vector<Point> pathPoints3 = { { 8, 14 },{ 7, 14 },{ 6, 14 },{ 5, 14 },{ 4, 14 },{ 3, 14 },{ 2, 14 },{ 1, 14 },{ 0, 14 },{ 0, 15 },{ 0, 16 },{ 0, 17 } }; //For hard mode
	for (Point p : pathPoints) generator->set_path(p);
	for (Point p : gaps) generator->set(p, p.first % 2 == 0 ? Decoration::Gap_Column : Decoration::Gap_Row);
	for (Point p : path1) generator->set_path(Point(p.first + 12, p.second + 14));
	for (Point p : path2) generator->set_path(Point(p.first + 12, p.second + 2));
	for (Point p : path3) generator->set_path(Point(8 - p.first, 8 - p.second + 2));
	if (psymbols.getNum(Decoration::Triangle) == 0) { //Normal mode
		for (Point p : path4) generator->set_path(Point(p.first, p.second + 14));
		if (path4.count(Point({ 8, 4 }))) for (Point p : pathPoints2) generator->set_path(p);
	}
	else { //Hard mode
		for (Point p : path4) generator->set_path(Point(8 - p.first, 8 - p.second + 14));
		for (Point p : pathPoints3) generator->set_path(p);
	}

	std::vector<std::string> solution; //For debugging only
	for (int y = 0; y < generator->_panel->_height; y++) {
		std::string row;
		for (int x = 0; x < generator->_panel->_width; x++) {
			if (generator->get(x, y) == PATH) {
				row += "xx";
			}
			else row += "    ";
		}
		solution.push_back(row);
	}

	while (!generator->place_all_symbols(psymbols)) {
		for (int x = 0; x < generator->_panel->_width; x++)
			for (int y = 0; y < generator->_panel->_height; y++)
				if (generator->get(x, y) != PATH && (generator->get(x, y) & 0x1fffff) != Decoration::Gap)
					generator->set(x, y, 0);
		generator->_openpos = generator->_gridpos;
		for (int i = 0; i < psymbols.symbols[Decoration::Poly].size(); i++) {
			psymbols.symbols[Decoration::Poly][i].second = Random::rand() % 2 + 2 - (Random::rand() % 5 == 0);
		}
	}

	for (int x = 0; x < generator->_panel->_width; x++)
		for (int y = 0; y < generator->_panel->_height; y++)
			if ((generator->get(x, y) & 0x1fffff) == Decoration::Gap)
				generator->set(x, y, IntersectionFlags::OPEN);
	generator->set(10, 10, IntersectionFlags::GAP);
	generator->set(12, 12, IntersectionFlags::NO_POINT);
	generator->set(10, 12, IntersectionFlags::NO_POINT);
	generator->set(10, 14, IntersectionFlags::NO_POINT);
	generator->set(10, 16, IntersectionFlags::NO_POINT);
	generator->set(10, 18, IntersectionFlags::ENDPOINT);
	generator->set(10, 20, IntersectionFlags::NO_POINT);
	generator->set(10, 22, IntersectionFlags::NO_POINT);

	generator->write(id);
	if (psymbols.getNum(Decoration::Triangle) > 0) (new KeepWatchdog())->start();
}

void Special::generateMountaintop(int id, const std::vector<std::pair<int, int>>& symbolVec)
{
	std::vector<std::vector<Point>> perspectiveU = {
	{ { 0, 3 },{ 1, 2 },{ 1, 4 },{ 2, 1 },{ 2, 3 },{ 3, 2 },{4, 7}, { 6, 1 },{6, 7}, { 7, 0 },{ 7, 2 },{ 7, 4 },{7, 6}, { 8, 1 },{ 8, 3 },{ 8, 5 },{ 9, 2 },{ 9, 4 },{ 9, 6 } },
	{ { 0, 3 },{ 0, 5 },{ 1, 2 },{ 1, 4 },{ 2, 1 },{ 2, 3 },{ 3, 2 },{ 3, 4 },{ 4, 3 },{ 4, 5 },{ 5, 4 },{ 6, 3 },{ 6, 5 },{ 7, 4 },{ 8, 5 },{8, 9},{9, 2},{ 9, 6 } }, 
	{ { 0, 3 },{ 0, 5 },{ 0, 7 },{ 1, 2 },{ 1, 4 },{ 1, 6 },{ 1, 8 },{ 2, 3 },{ 2, 5 },{ 2, 7 },{ 3, 4 },{ 3, 6 },{ 4, 5 },{ 4, 7 },{ 5, 6 },{ 6, 5 },{ 6, 7 },{ 7, 4 },{ 7, 6 },{ 8, 7 },{8, 9},{10, 5} }, 
	{ { 0, 7 },{ 1, 6 },{ 1, 8 },{ 2, 5 },{ 3, 4 },{4, 7}, {6, 7}, { 7, 4 },{ 7, 6 },{ 7, 8 },{ 8, 5 },{ 8, 7 },{ 8, 9 },{ 9, 6 },{ 9, 8 },{ 10, 7 } }, 
	{ {1, 2},{2, 1}, { 2, 5 },{ 4, 3 },{ 4, 5 },{ 6, 3 },{ 6, 5 },{6, 9}, { 7, 4 },{7, 8}, { 8, 3 },{ 8, 5 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 10, 3 },{ 10, 5 },{ 10, 7 } },
	{ {0, 7}, { 1, 4 },{2, 1}, { 2, 3 },{ 2, 5 },{ 3, 4 },{3, 6}, { 4, 3 },{ 5, 2 },{ 6, 1 },{ 6, 3 },{ 7, 0 },{ 7, 2 },{ 7, 4 },{ 8, 1 },{ 8, 3 },{ 8, 5 },{ 9, 4 },{ 9, 6 },{ 10, 3 },{ 10, 5 },{ 10, 7 } },
	};
	if (generator->get_symbol_type(symbolVec[0].first) == Decoration::Triangle) { //Hard mode
		perspectiveU = { { { 1, 2 },{ 1, 4 },{ 3, 0 },{ 3, 2 },{ 3, 4 },{ 3, 6 },{ 5, 8 },{ 6, 7 },{ 7, 0 },{ 7, 2 },{ 7, 4 },{ 8, 1 },{ 8, 3 },{ 8, 5 },{ 8, 9 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 10, 3 },{ 10, 5 },{ 10, 7 } } };
	}
	std::vector<std::vector<Point>> perspectiveL = {
	{ { 0, 3 },{ 0, 5 },{ 1, 2 },{ 1, 4 },{ 2, 1 },{ 2, 3 },{2, 9}, { 3, 2 },{ 5, 2 },{ 6, 1 },{ 6, 3 },{ 7, 0 },{ 7, 2 },{ 7, 4 },{ 8, 3 },{ 8, 5 },{ 9, 4 },{ 9, 6 } }, 
	{ { 0, 3 },{ 0, 5 },{ 1, 2 },{ 1, 4 },{ 2, 1 },{ 2, 3 },{ 3, 0 },{ 3, 2 },{ 4, 1 },{ 4, 3 },{ 5, 2 },{ 5, 4 },{ 6, 3 },{ 6, 5 },{ 7, 4 },{8, 1}, { 8, 5 },{ 9, 6 }, {10, 3} }, 
	{ { 0, 3 },{ 0, 5 },{ 0, 7 },{ 1, 2 },{ 1, 4 },{ 1, 6 },{ 1, 8 },{ 2, 3 },{ 2, 5 },{ 2, 7 },{ 3, 4 },{ 3, 6 },{ 4, 5 },{ 4, 7 },{ 5, 6 },{ 6, 5 },{ 6, 7 },{ 7, 4 },{ 7, 6 },{8, 1}, { 8, 7 }, {10, 5} }, 
	{ { 0, 7 },{ 1, 6 },{ 2, 5 },{2, 9}, { 3, 4 },{4, 7},{5, 8}, { 6, 9 },{ 7, 4 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 8, 7 },{ 8, 9 },{ 9, 8 } }, 
	{ {0, 3},{0, 7},{1, 2},{1, 8}, { 2, 5 },{2, 9}, { 4, 3 },{ 4, 5 },{ 6, 3 },{ 6, 5 },{ 7, 4 },{ 8, 3 },{ 8, 5 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 10, 3 },{ 10, 5 },{ 10, 7 } }, 
	{ { 1, 2 },{ 1, 4 },{ 2, 3 },{ 3, 0 },{ 3, 2 },{ 4, 1 },{ 4, 3 },{4, 5}, { 5, 2 },{5, 6}, {6, 7}, { 7, 4 },{ 8, 3 },{ 8, 5 },{8, 7}, { 9, 2 },{ 9, 4 },{ 9, 6 },{ 10, 3 },{ 10, 5 },{ 10, 7 } }
	};
	std::vector<std::vector<Point>> perspectiveC = {
	{ { 0, 3 },{0, 7}, { 1, 2 },{ 1, 4 },{1, 8}, { 2, 1 },{ 2, 3 },{ 3, 2 },{ 6, 1 },{ 7, 0 },{ 7, 2 },{ 7, 4 },{ 8, 1 },{ 8, 3 },{ 8, 5 },{ 9, 2 },{ 9, 4 },{ 9, 6 } },
	{ { 0, 7 },{ 1, 6 },{ 2, 5 },{ 3, 4 },{4, 7},{5, 2}, {5, 4}, {5, 6}, { 6, 9 },{ 7, 4 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 8, 7 },{ 8, 9 },{ 9, 8 } }
	};

	std::vector<std::shared_ptr<Generate>> gens;
	for (int i = 0; i < 3; i++) gens.push_back(std::make_shared<Generate>());
	for (std::shared_ptr<Generate> g : gens) {
		g->setGridSize(5, 5);
		g->setSymbol(Decoration::Gap, 5, 0);
		g->setSymbol(Decoration::Gap, 5, 10);
		g->setFlag(Generate::Config::PreserveStructure);
		g->setFlag(Generate::ShortPath);
		g->setFlag(Generate::DecorationsOnly);
	}
	gens[0]->_starts = { { 2, 0 } }; gens[1]->_starts = { { 2, 10 } }; gens[2]->_starts = { { 10, 4 },{ 10, 6 } };
	gens[0]->_exits = { { 8, 10 } }; gens[1]->_exits = { { 8, 0 } }; gens[2]->_exits = { { 0, 4 },{ 0, 6 } };
	gens[0]->setObstructions(perspectiveU); gens[1]->setObstructions(perspectiveL); gens[2]->setObstructions(perspectiveC);
	generator->generateMulti(id, gens, symbolVec);
}

void Special::generateMultiPuzzle(std::vector<int> ids, const std::vector<std::vector<std::pair<int, int>>>& symbolVec, bool flip) {
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->generate(ids[0]);
	std::vector<PuzzleSymbols> symbols;
	for (auto sym : symbolVec) symbols.emplace_back(PuzzleSymbols(sym));
	std::vector<Generate> gens;
	for (int i = 0; i < ids.size(); i++) gens.emplace_back(Generate());
	for (int i = 0; i < ids.size(); i++) {
		gens[i].setFlag(Generate::Config::DisableWrite);
		gens[i].setFlag(Generate::WriteColors);
		if (symbols[i].getNum(Decoration::Poly)  - symbols[i].getNum(Decoration::Eraser) > 1) gens[i].setFlag(Generate::RequireCombineShapes);
	}
	while (!generateMultiPuzzle(ids, gens, symbols, generator->_path)) {
		generator->generate(ids[0]);
	}
	for (int i = 0; i < ids.size(); i++) {
		gens[i].write(ids[i]);
		generator->incrementProgress();
		if (symbolVec[0][0].first == (Decoration::Triangle | Decoration::Color::Orange)) { //Hard mode
			int numIntersections = ReadPanelData<int>(ids[i], NUM_DOTS);
			std::vector<float> intersections = ReadArray<float>(ids[i], DOT_POSITIONS, numIntersections * 2);
			for (int j = 0; j < intersections.size(); j += 2) {
				float x = intersections[j], y = intersections[j + 1];
				if (i == 1) { intersections[j] = y; intersections[j + 1] = x; }
				if (i == 2) { intersections[j + 1] = 1 - y; }
				if (i == 3) { intersections[j] = 1 - y; intersections[j + 1] = x; }
				if (i == 4) { intersections[j] = 1 - x; }
				if (i == 5) { intersections[j] = 1 - x; intersections[j + 1] = 1 - y; }
			}
			WriteArray(ids[i], DOT_POSITIONS, intersections);
		}
	}
	generator->resetConfig();
	generator->resetVars();
}

bool Special::generateMultiPuzzle(std::vector<int> ids, std::vector<Generate>& gens, const std::vector<PuzzleSymbols>& symbols, const std::set<Point>& path) {
	for (int i = 0; i < ids.size(); i++) {
		gens[i]._custom_grid.clear();
		gens[i].setPath(path);
		int fails = 0;
		while (!gens[i].generate(ids[i], symbols[i])) {
			if (fails++ > 20)
				return false;
		}
	}
	std::vector<std::string> solution; //For debugging only
	for (int y = 0; y < 11; y++) {
		std::string row;
		for (int x = 0; x < 11; x++) {
			if (path.count(Point(x, y))) {
				row += "xx";
			}
			else row += "    ";
		}
		solution.push_back(row);
	}
	return true;
}

void Special::generate2Bridge(int id1, int id2)
{
	std::vector<std::shared_ptr<Generate>> gens;
	for (int i = 0; i < 3; i++) gens.push_back(std::make_shared<Generate>());
	for (std::shared_ptr<Generate> g : gens) {
		g->setFlag(Generate::Config::DisableWrite);
		g->setFlag(Generate::Config::DisableReset);
		g->setFlag(Generate::Config::DecorationsOnly);
		g->setFlag(Generate::Config::ShortPath);
		g->setFlag(Generate::Config::WriteColors);
	}
	while (!generate2Bridge(id1, id2, gens));
	gens[1]->write(id1);
	gens[1]->write(id2);
	generator->incrementProgress();
}

bool Special::generate2Bridge(int id1, int id2, std::vector<std::shared_ptr<Generate>> gens)
{
	for (int i = 0; i < gens.size(); i++) {
		gens[i]->_custom_grid.clear();
		gens[i]->setPath(std::set<Point>());
		std::vector<Point> walls = { { 12, 1 },{ 12, 3 },{ 3, 8 },{ 9, 8 } };
		for (Point p : walls) gens[i]->setSymbol(Decoration::Gap, p.first, p.second);
		if (i % 2 == 0) {
			gens[i]->setObstructions({ { 5, 8 },{ 6, 7 },{ 7, 8 } });
		}
		else {
			gens[i]->setObstructions({ { 5, 0 },{ 6, 1 },{ 7, 0 } });
		}
	}

	int steps = 2;

	gens[0]->_exits = { { 12, 8 } };
	gens[1]->_exits = { { 0, 0 } };

	PuzzleSymbols symbols({ {Decoration::Poly | Decoration::Can_Rotate | Decoration::Color::Yellow, 1}, {Decoration::Star | Decoration::Color::Yellow, 1} });
	int fails = 0;
	while (!gens[0]->generate(id1, symbols)) {
		if (fails++ > 20)
			return false;
	}

	gens[1]->setPath(gens[0]->_path);
	gens[1]->customPath.clear();
	gens[1]->_custom_grid = gens[0]->_panel->_grid;
	symbols = PuzzleSymbols({ { Decoration::Poly | Decoration::Can_Rotate | Decoration::Color::Yellow, 1 },{ Decoration::Star | Decoration::Color::Yellow, 3 } });
	fails = 0;
	while (!gens[1]->generate(id2, symbols)) {
		if (fails++ > 20) {
			return false;
		}
	}

	if (gens[0]->get(11, 1) != 0 || gens[1]->get(11, 1) != 0 || gens[1]->get(11, 3) != 0 || gens[1]->get(11, 3) != 0)
		return false;
	
	//Make sure both shapes weren't blocked off by the same path
	int shapeCount = 0;
	for (int x = 1; x < gens[1]->_panel->_width; x += 2) {
		for (int y = 1; y < gens[1]->_panel->_height; y += 2) {
			if (gens[1]->get_symbol_type(gens[1]->get(x, y)) == Decoration::Poly && gens[1]->get_region(Point(x, y)).size() == gens[0]->get_region(Point(x, y)).size())
				if (++shapeCount == 2) return false;
		}
	}

	for (int x = 1; x < gens[1]->_panel->_width; x += 2) {
		for (int y = 1; y < gens[1]->_panel->_height; y += 2) {
			if (gens[1]->get_symbol_type(gens[1]->get(x, y)) == Decoration::Star) {
				if (!gens[1]->get_region(Point(x, y)).count({ 9, 7 }))
					continue;
				gens[1]->set(x, y, Decoration::Eraser | Decoration::Color::White);
				return true;
			}
		}
	}

	return false;
}

void Special::generate2BridgeH(int id1, int id2)
{
	std::vector<std::shared_ptr<Generate>> gens;
	for (int i = 0; i < 3; i++) gens.push_back(std::make_shared<Generate>());
	for (std::shared_ptr<Generate> g : gens) {
		g->setFlag(Generate::Config::DisableWrite);
		g->setFlag(Generate::Config::DisableReset);
		g->setFlag(Generate::Config::DecorationsOnly);
		g->setFlag(Generate::Config::ShortPath);
		g->setFlag(Generate::Config::WriteColors);
	}
	while (!generate2BridgeH(id1, id2, gens));
	
	
	gens[0]->write(id1);
	gens[0]->write(id2);
	generator->incrementProgress();

	int numIntersections = ReadPanelData<int>(id1, NUM_DOTS);
	std::vector<int> intersectionFlags = ReadArray<int>(id1, DOT_FLAGS, numIntersections);
	std::vector<int> intersectionFlags2 = ReadArray<int>(id2, DOT_FLAGS, numIntersections);
	for (int x = 0; x < gens[0]->_panel->_width; x += 2) {
		for (int y = 0; y < gens[0]->_panel->_height; y += 2) {
			if (gens[0]->get(x, y) == Decoration::Dot_Intersection) {
				intersectionFlags[gens[0]->_panel->xy_to_loc(x, y)] = Decoration::Dot_Intersection;
				intersectionFlags2[gens[0]->_panel->xy_to_loc(x, y)] = Decoration::Dot_Intersection;
			}
			else {
				intersectionFlags[gens[0]->_panel->xy_to_loc(x, y)] &= ~Decoration::Dot;
				intersectionFlags2[gens[0]->_panel->xy_to_loc(x, y)] &= ~Decoration::Dot;
			}
		}
	}
	WriteArray(id1, DOT_FLAGS, intersectionFlags);
	WriteArray(id2, DOT_FLAGS, intersectionFlags2);
	WritePanelData(id1, NEEDS_REDRAW, 1);
	WritePanelData(id2, NEEDS_REDRAW, 1);
}

bool Special::generate2BridgeH(int id1, int id2, std::vector<std::shared_ptr<Generate>> gens)
{
	for (int i = 0; i < gens.size(); i++) {
		gens[i]->_custom_grid.clear();
		gens[i]->setPath(std::set<Point>());
		std::vector<Point> walls = { { 12, 1 },{ 12, 3 },{ 3, 8 },{ 9, 8 } };
		for (Point p : walls) gens[i]->setSymbol(Decoration::Gap, p.first, p.second);
		if (i == 0) {
			gens[i]->setObstructions({ { 3, 0 },{ 3, 2 },{ 3, 4 },{4, 5}, {5, 6}, {6, 7}, {8, 7}, {9, 0}, {9, 2}, {9, 4}, {10, 5}, {12, 5} });
		}
		else {
			gens[i]->setObstructions({ {1, 4}, { 1, 6 },{ 1, 8 }, {4, 1}, {6, 7}, {7, 8} });
		}
	}

	gens[0]->_exits = { { 12, 8 } };
	gens[1]->_exits = { { 0, 0 } };

	gens[0]->generate(id1);
	gens[1]->setPath(gens[0]->_path);
	gens[1]->customPath.clear();
	gens[1]->_custom_grid = gens[0]->_panel->_grid;
	gens[1]->generate(id2);
	std::vector<Point> points = { {12, 2}, { 11, 2 }, { 10, 2 }, { 10, 3 }, { 10, 4 }, { 9, 4 }, { 8, 4 }, { 7, 4 }, { 6, 4 } };
	for (int i = 0; i < points.size(); i++) {
		if (gens[1]->get(points[i]) == PATH) break;
		gens[1]->set_path(points[i]);
		if (i == points.size() - 1) return false;
	}
	int state = 0;
	for (int i = 8; i >= 0; i--) {
		if (state == 0) {
			if (gens[1]->get(i, 2) == PATH) state++;
		}
		else if (state == 1) {
			if (gens[1]->get(i, 2) != PATH) {
				state++;
				gens[1]->set_path({ i, 2 });
			}
		}
		else if (state == 2) {
			if (gens[1]->get(i, 2) == PATH && gens[0]->get(i, 2) != PATH) break;
			if (gens[1]->get(i, 2) == PATH && gens[0]->get(i, 2) == PATH) return false;
			gens[1]->set_path({ i, 2 });
		}
	}
	state = 0;
	for (int i = 12; i >= 0; i--) {
		if (state == 0) {
			if (gens[1]->get(i, 6) == PATH) state++;
		}
		else if (state == 1) {
			if (gens[1]->get(i, 6) != PATH) {
				state++;
				gens[1]->set_path({ i, 6 });
				gens[0]->set(i + 1, 6, Decoration::Dot_Intersection);
			}
		}
		else if (state == 2) {
			if (gens[1]->get(i, 6) == PATH && gens[0]->get(i, 6) != PATH) break;
			if (gens[1]->get(i, 6) == PATH && gens[0]->get(i, 6) == PATH) return false;
			gens[1]->set_path({ i, 6 });
		}
	}

	int count = 0;
	std::set<Point> open = gens[0]->_gridpos;
	while (open.size() > 0) {
		Point pos = *(open.begin());
		std::set<Point> region = gens[1]->get_region(pos);
		if (region.size() == 1 || region.size() > 6) return false;
		int symbol = gens[0]->make_shape_symbol(region, false, false);
		if (!symbol) return false;
		gens[0]->set(pick_random(region), symbol | Decoration::Color::Yellow);
		for (Point p : region) open.erase(p);
		count++;
	}
	return count == 6;
}

bool checkShape(const std::set<Point>& shape, int direction) {
	//Make sure it is not off the grid
	for (Point p : shape) if (p.first < 0 || p.first > 7 || p.second < 0 || p.second > 7)
		return false;
	//Make sure it is drawable
	std::vector<Point> points1, points2;
	if (direction == 0) {
		points1 = { { 1, 7 },{ 3, 7 },{ 5, 7 },{ 7, 7 },{ 7, 5 },{ 7, 3 },{ 7, 1 } };
		points2 = { { 1, 7 },{ 1, 5 },{ 1, 3 },{ 1, 1 },{ 3, 1 },{ 5, 1 },{ 7, 1 } };
	}
	else {
		points1 = { { 7, 7 },{ 5, 7 },{ 3, 7 },{ 1, 7 },{ 1, 5 },{ 1, 3 },{ 1, 1 } };
		points2 = { { 7, 7 },{ 7, 5 },{ 7, 3 },{ 7, 1 },{ 5, 1 },{ 3, 1 },{ 1, 1 } };
	}
	int count = 0;
	bool consecutive = false;
	for (Point p : points1) {
		if (shape.count(p)) {
			if (!consecutive) {
				count++;
				consecutive = true;
			}
		}
		else consecutive = false;
	}
	if (count == 1)
		return true;
	count = 0;
	consecutive = false;
	for (Point p : points2) {
		if (shape.count(p)) {
			if (!consecutive) {
				count++;
				consecutive = true;
			}
		}
		else consecutive = false;
	}
	if (count == 1)
		return true;
	return false;
}

void Special::generateMountainFloor(const std::vector<int>& ids, int idfloor)
{
	generator->resetConfig();
	std::vector<Point> floorPos = { { 3, 3 },{ 7, 3 },{ 3, 7 },{ 7, 7 } };
	generator->openPos = std::set<Point>(floorPos.begin(), floorPos.end());
	generator->setFlag(Generate::Config::DisableWrite);
	//Make sure no duplicated symbols
	std::set<int> sym;
	do {
		generator->generate(idfloor, Decoration::Poly, 4);
		sym.clear();
		for (Point p : floorPos) sym.insert(generator->get(p));
	} while (sym.size() < 4);

	int rotateIndex = Random::rand() % 4;
	for (int i = 0; i < 4; i++) {
		int symbol = generator->get(floorPos[i]);
		//Convert to shape
		Shape shape;
		for (int j = 0; j < 16; j++) {
			if (symbol & (1 << (j + 16))) {
				shape.emplace(Point((j % 4) * 2 + 1, 8 - ((j / 4) * 2 + 1)));
			}
		}
		//Translate randomly
		Shape newShape;
		do {
			Point shift = Point((Random::rand() % 4) * 2, -(Random::rand() % 4) * 2);
			newShape.clear();
			for (Point p : shape) newShape.insert(p + shift);
		} while (!checkShape(newShape, i % 2));
		if (i == rotateIndex) {
			symbol = generator->make_shape_symbol(newShape, true, false);
			if (symbol == 0) {
				symbol = generator->get(floorPos[i]);
				rotateIndex++;
			}
		}

		Generate gen;
		for (Point p : newShape) {
			for (Point dir : Generate::_DIRECTIONS2) {
				if (!newShape.count(p + dir)) {
					gen.setSymbol(PATH, p.first + dir.first / 2, p.second + dir.second / 2);
				}
			}
		}
		gen.setPath({ {0, 0} }); //Just to stop it from trying to make a path
		gen.setFlag(Generate::Config::DecorationsOnly);
		gen.setFlag(Generate::Config::DisableWrite);
		gen.generate(ids[i], Decoration::Poly | (i == rotateIndex ? Decoration::Can_Rotate : 0), 1, Decoration::Eraser | Decoration::Color::Green, 1);
		std::set<Point> covered;
		int decoyShape;
		for (int x = 1; x <= 7; x += 2)
			for (int y = 1; y <= 7; y += 2)
				if (gen.get(x, y) != 0) {
					covered.emplace(Point(x, y));
					if (gen.get_symbol_type(gen.get(x, y)) == Decoration::Poly) decoyShape = gen.get(x, y);
				}
		for (Point p : covered) newShape.erase(p);
		if (newShape.size() == 0 || decoyShape == symbol) {
			i--;
			continue;
		}
		Point pos = pick_random(newShape);
		gen.setVal(symbol, pos.first, pos.second);
		gen.write(ids[i]);
	}
	generator->incrementProgress();
	generator->resetVars();
	generator->resetConfig();
}

void Special::generateMountainFloorH(const std::vector<int>& ids, int idfloor)
{
	generator->resetConfig();
	std::vector<Point> floorPos = { { 3, 3 },{ 7, 3 },{ 3, 7 },{ 7, 7 } };
	generator->openPos = std::set<Point>(floorPos.begin(), floorPos.end());
	generator->setFlag(Generate::Config::DisableWrite);
	generator->setFlag(Generate::Config::MountainFloorH);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->setSymbol(Decoration::Start, 0, 10); generator->setSymbol(Decoration::Start, 10, 0);
	generator->setSymbol(Decoration::Exit, 0, 0); generator->setSymbol(Decoration::Exit, 10, 10);
	//Make sure no duplicated symbols
	std::set<int> sym;
	do {
		generator->generate(idfloor, Decoration::Poly, 6);
		sym.clear();
		for (Point p : floorPos) sym.insert(generator->get(p));
	} while (sym.size() < 4);

	int combine = 0;
	for (int i = 0; i < 4; i++) {
		int symbol = generator->get(floorPos[i]);
		//Convert to shape
		Shape shape;
		for (int j = 0; j < 16; j++) {
			if (symbol & (1 << (j + 16))) {
				shape.emplace(Point((j % 4) * 2 + 1, 8 - ((j / 4) * 2 + 1)));
			}
		}
		//Translate randomly
		Shape newShape;
		int fails = 0;
		do {
			if (fails++ == 50) {
				generateMountainFloorH(ids, idfloor);
				return;
			}
			Point shift = Point((Random::rand() % 4) * 2, -(Random::rand() % 4) * 2);
			newShape.clear();
			for (Point p : shape) newShape.insert(p + shift);
		} while (!checkShape(newShape, i % 2));

		Generate gen;
		for (Point p : newShape) {
			for (Point dir : Generate::_DIRECTIONS2) {
				if (!newShape.count(p + dir)) {
					gen.setSymbol(PATH, p.first + dir.first / 2, p.second + dir.second / 2);
				}
			}
		}
		gen.setPath({ { 0, 0 } }); //Just to stop it from trying to make a path
		gen.setFlag(Generate::Config::DecorationsOnly);
		gen.setFlag(Generate::Config::DisableWrite);
		gen.setFlag(Generate::Config::MountainFloorH);
		gen.setFlag(Generate::Config::DisableCancelShapes);
		PuzzleSymbols symbols({ { Decoration::Poly, 2 },{ Decoration::Eraser | Decoration::Color::Green, 1 } });
		if (newShape.size() > 5) {
			if (combine == 0) symbols = PuzzleSymbols({ { Decoration::Poly, 3 },{ Decoration::Eraser | Decoration::Color::Green, 1 } });
			if (combine == 1) symbols = PuzzleSymbols({ { Decoration::Poly, 3 },{ Decoration::Poly | Decoration::Negative | Decoration::Color::Cyan, 1 } });
			combine++;
		}
		fails = 0;
		while (!gen.generate(ids[i], symbols)) {
			if (fails++ > 50) {
				generateMountainFloorH(ids, idfloor);
				return;
			}
		}
		//Check that the symbols made it into the shape
		int count = 0;
		for (Point p : newShape) {
			if (gen.get_symbol_type(gen.get(p)) == Decoration::Poly) count++;
			if (gen.get_symbol_type(gen.get(p)) == Decoration::Eraser) count--;
		}
		if (count != (newShape.size() > 5 ? combine == 2 ? 4 : 2 : 1)) {
			i--;
			if (newShape.size() > 5) combine--;
			continue;
		}
		//Check that the symbols aren't the same
		std::set<int> symbolSet;
		for (Point p : gen._gridpos) {
			if (gen.get_symbol_type(gen.get(p)) == Decoration::Poly) symbolSet.insert(gen.get(p));
		}
		if (symbolSet.size() <= 1) {
			i--;
			if (newShape.size() > 5) combine--;
			continue;
		}
		gen.write(ids[i]);
	}
	if (combine != 2) {
		generateMountainFloorH(ids, idfloor);
		return;
	}
	for (Point p : floorPos) generator->set(p, Decoration::Poly);
	generator->write(idfloor);
	generator->resetConfig();
}

void Special::generatePivotPanel(int id, Point gridSize, const std::vector<std::pair<int, int>>& symbolVec) {
	int width = gridSize.first * 2 + 1, height = gridSize.second * 2 + 1;
	std::vector<std::shared_ptr<Generate>> gens;
	for (int i = 0; i < 3; i++) gens.push_back(std::make_shared<Generate>());
	for (std::shared_ptr<Generate> gen : gens) {
		gen->seed(Random::rand());
		gen->setSymbol(Decoration::Start, width / 2, height - 1);
		gen->setGridSize(gridSize.first, gridSize.second);
		gen->setFlag(Generate::Config::DisableWrite);
	}
	gens[0]->setSymbol(Decoration::Exit, 0, height / 2);
	gens[1]->setSymbol(Decoration::Exit, width - 1, height / 2);
	gens[2]->setSymbol(Decoration::Exit, width / 2, 0);
	generator->generateMulti(id, gens, symbolVec);
	gens[0]->_panel->_endpoints.clear();
	gens[0]->_panel->SetGridSymbol(0, height / 2, Decoration::Exit, Decoration::Color::None);
	gens[0]->_panel->SetGridSymbol(width - 1, height / 2, Decoration::Exit, Decoration::Color::None);
	gens[0]->_panel->SetGridSymbol(width / 2, 0, Decoration::Exit, Decoration::Color::None);
	gens[0]->setFlag(Generate::Config::TreehouseColors);
	gens[0]->write(id);
	int style = ReadPanelData<int>(id, STYLE_FLAGS);
	WritePanelData(id, STYLE_FLAGS, { style | Panel::Style::IS_PIVOTABLE });
}

void Special::modifyGate(int id)
{
	int numIntersections = ReadPanelData<int>(id, NUM_DOTS);
	std::vector<float> intersections = ReadArray<float>(id, DOT_POSITIONS, numIntersections * 2);
	std::vector<int> intersectionFlags = ReadArray<int>(id, DOT_FLAGS, numIntersections);
	if (intersectionFlags[24] == 0) return;
	int numConnections = ReadPanelData<int>(id, NUM_CONNECTIONS);
	std::vector<int> connections_a = ReadArray<int>(id, DOT_CONNECTION_A, numConnections);
	std::vector<int> connections_b = ReadArray<int>(id, DOT_CONNECTION_B, numConnections);
	int style = ReadPanelData<int>(id, STYLE_FLAGS);
	intersectionFlags[6] |= Decoration::Start;
	intersectionFlags[18] |= Decoration::Start;
	intersectionFlags[11] = Decoration::Dot_Intersection;
	intersectionFlags[24] = 0;
	intersectionFlags.push_back(0x400001);
	intersections.push_back(0.5f);
	intersections.push_back(1 - intersections[51]);
	connections_a.push_back(24);
	connections_b.push_back(numIntersections);
	std::vector<int> symData;
	for (int i = 0; i < numIntersections + 1; i++) {
		bool pushed = false;
		for (int j = 0; j < numIntersections + 1; j++) {
			if (std::round(intersections[i * 2] * 30) == std::round(30 - intersections[j * 2] * 30) &&
				std::round(intersections[i * 2 + 1] * 30) == std::round(30 - intersections[j * 2 + 1] * 30)) {
				symData.push_back(j);
				pushed = true;
				break;
			}
		}
		if (!pushed) symData.push_back(0);
	}
	WriteArray(id, DOT_FLAGS, intersectionFlags);
	WriteArray(id, DOT_POSITIONS, intersections);
	WriteArray(id, DOT_CONNECTION_A, connections_a);
	WriteArray(id, DOT_CONNECTION_B, connections_b);
	WritePanelData(id, NUM_DOTS, numIntersections + 1);
	WritePanelData(id, NUM_CONNECTIONS, numConnections + 1);
	WriteArray(id, REFLECTION_DATA, symData);
	Color successColor = ReadPanelData<Color>(id, SUCCESS_COLOR_A);
	WritePanelData(id, SUCCESS_COLOR_B, successColor);
	WritePanelData(id, PATTERN_POINT_COLOR, { 0.1f, 0.1f, 0.1f, 1 });
	WritePanelData(id, STYLE_FLAGS, style | Panel::Style::HAS_DOTS);
	WritePanelData(id, NEEDS_REDRAW, 1);
}

void Special::addDecoyExits(std::shared_ptr<Generate> gen, int amount) {
	while (amount > 0) {
		Point pos;
		switch (Random::rand() % 4) {
		case 0: pos = Point(0, Random::rand() % gen->_height); break;
		case 1: pos = Point(gen->_width - 1, Random::rand() % gen->_height); break;
		case 2: pos = Point(Random::rand() % gen->_width, 0); break;
		case 3: pos = Point(Random::rand() % gen->_width, gen->_height - 1); break;
		}
		if (pos.first % 2) pos.first--;
		if (pos.second % 2) pos.second--;
		if (gen->_exits.count(pos) || gen->_exits.count(gen->get_sym_point(pos)))
			continue;
		gen->_panel->SetGridSymbol(pos.first, pos.second, Decoration::Exit, Decoration::Color::None);
		gen->_exits.insert(pos);
		amount--;
	}
}

void Special::initSSGrid(std::shared_ptr<Generate> gen) {
	gen->setSymbol(Decoration::Start, 0, 0);  gen->setSymbol(Decoration::Start, 6, 0), gen->setSymbol(Decoration::Start, 8, 0), gen->setSymbol(Decoration::Start, 14, 0);
	gen->setSymbol(Decoration::Start, 0, 6);  gen->setSymbol(Decoration::Start, 6, 6), gen->setSymbol(Decoration::Start, 8, 6), gen->setSymbol(Decoration::Start, 14, 6);
	gen->setSymbol(Decoration::Start, 0, 8);  gen->setSymbol(Decoration::Start, 6, 8), gen->setSymbol(Decoration::Start, 8, 8), gen->setSymbol(Decoration::Start, 14, 8);
	gen->setSymbol(Decoration::Start, 0, 14);  gen->setSymbol(Decoration::Start, 6, 14), gen->setSymbol(Decoration::Start, 8, 14), gen->setSymbol(Decoration::Start, 14, 14);
	gen->setSymbol(Decoration::Exit, 2, 0);  gen->setSymbol(Decoration::Exit, 4, 0), gen->setSymbol(Decoration::Exit, 10, 0), gen->setSymbol(Decoration::Exit, 12, 0);
	gen->setSymbol(Decoration::Exit, 2, 14);  gen->setSymbol(Decoration::Exit, 4, 14), gen->setSymbol(Decoration::Exit, 10, 14), gen->setSymbol(Decoration::Exit, 12, 14);
	gen->setSymbol(Decoration::Exit, 0, 2);  gen->setSymbol(Decoration::Exit, 0, 4), gen->setSymbol(Decoration::Exit, 0, 10), gen->setSymbol(Decoration::Exit, 0, 12);
	gen->setSymbol(Decoration::Exit, 14, 2);  gen->setSymbol(Decoration::Exit, 14, 4), gen->setSymbol(Decoration::Exit, 14, 10), gen->setSymbol(Decoration::Exit, 14, 12);
}

void Special::initRotateGrid(std::shared_ptr<Generate> gen)
{
	gen->setSymbol(Decoration::Start, 4, 0);  gen->setSymbol(Decoration::Start, 10, 4), gen->setSymbol(Decoration::Start, 6, 10), gen->setSymbol(Decoration::Start, 0, 6);
	gen->setSymbol(Decoration::Exit, 6, 0);  gen->setSymbol(Decoration::Exit, 10, 6), gen->setSymbol(Decoration::Exit, 4, 10), gen->setSymbol(Decoration::Exit, 0, 4);
}

void Special::initPillarSymmetry(std::shared_ptr<Generate> gen, int id, Panel::Symmetry symmetry)
{
	gen->setSymmetry(symmetry);
	switch (symmetry) {
	case Panel::Symmetry::PillarParallel:
		gen->setSymbol(Decoration::Start, 0, gen->_height - 1);  gen->setSymbol(Decoration::Start, 6, gen->_height - 1), gen->setSymbol(Decoration::Exit, 0, 0);  gen->setSymbol(Decoration::Exit, 6, 0); break;
	case Panel::Symmetry::PillarVertical:
		gen->setSymbol(Decoration::Start, 2, gen->_height - 1);  gen->setSymbol(Decoration::Start, 4, gen->_height - 1), gen->setSymbol(Decoration::Exit, 2, 0);  gen->setSymbol(Decoration::Exit, 4, 0); break;
	case Panel::Symmetry::PillarHorizontal:
		gen->setSymbol(Decoration::Start, 0, gen->_height - 1);  gen->setSymbol(Decoration::Exit, 6, gen->_height - 1), gen->setSymbol(Decoration::Exit, 0, 0);  gen->setSymbol(Decoration::Start, 6, 0); break;
	case Panel::Symmetry::PillarRotational:
		gen->setSymbol(Decoration::Start, 0, gen->_height - 1);  gen->setSymbol(Decoration::Exit, 6, gen->_height - 1), gen->setSymbol(Decoration::Exit, 0, 0);  gen->setSymbol(Decoration::Start, 6, 0); break;
	}
	WritePanelData(id, SUCCESS_COLOR_B, { ReadPanelData<Color>(id, SUCCESS_COLOR_A) });
}

void Special::generateSymmetryGate(int id)
{
	generator->resetConfig();
	generator->setFlag(Generate::Config::DisableWrite);
	generator->setFlag(Generate::Config::WriteInvisible);
	generator->setSymmetry(Panel::Symmetry::RotateRight);
	generator->setSymbol(Decoration::Start, 0, 0);
	generator->setSymbol(Decoration::Start, 0, 8);
	generator->setSymbol(Decoration::Start, 8, 0);
	generator->setSymbol(Decoration::Start, 8, 8);
	generator->setSymbol(Decoration::Exit, 4, 0);
	generator->setSymbol(Decoration::Exit, 4, 8);
	generator->setSymbol(Decoration::Exit, 0, 4);
	generator->setSymbol(Decoration::Exit, 8, 4);
	generator->generate(id, Decoration::Triangle | Decoration::Color::Yellow, 4);
	std::vector<Point> breakPos = { {0, 3}, {2, 3}, {4, 3}, {6, 3}, {8, 3}, {0, 5}, {2, 5}, {4, 5}, {6, 5}, {8, 5} };
	for (Point p : breakPos) generator->set(p, IntersectionFlags::COLUMN | 0x40000);
	breakPos = { { 3, 0 },{ 3, 2 },{ 3, 4 },{ 3, 6 },{ 3, 8 },{ 5, 0 },{ 5, 2 },{ 5, 4 },{ 5, 6 },{ 5, 8 } };
	for (Point p : breakPos) generator->set(p, IntersectionFlags::ROW | 0x40000);
	//Expand the grid a little to prevent the collision detection from glitching out
	generator->_panel->minx = 0.08f;
	generator->_panel->maxx = 0.92f;
	generator->_panel->miny = 0.08f;
	generator->_panel->maxy = 0.92f;
	generator->write(id);
	int numIntersections = ReadPanelData<int>(id, NUM_DOTS);
	std::vector<float> intersections = ReadArray<float>(id, DOT_POSITIONS, numIntersections * 2);
	std::vector<int> symData;
	for (int i = 0; i < numIntersections; i++) {
		bool pushed = false;
		for (int j = 0; j < numIntersections; j++) {
			int precision = 30;
			if (std::round(intersections[i * 2] * precision) == std::round(precision - intersections[j * 2 + 1] * precision) &&
				std::round(intersections[i * 2 + 1] * precision) == std::round(intersections[j * 2] * precision)) {
				symData.push_back(j);
				pushed = true;
				break;
			}
		}
		if (!pushed)
			symData.push_back(0);
	}
	WriteArray(id, REFLECTION_DATA, symData);
}

bool Special::checkDotSolvability(std::shared_ptr<Panel> panel1, std::shared_ptr<Panel> panel2, Panel::Symmetry correctSym) {
	std::vector<Panel::Symmetry> sym = { Panel::Symmetry::FlipXY, Panel::Symmetry::FlipNegXY, Panel::Symmetry::RotateLeft, Panel::Symmetry::RotateRight };
	for (Panel::Symmetry s : sym) {
		if (s == correctSym) continue;
		bool found = false;
		//Check for three dots at a point
		for (int x = 0; x < panel1->_width; x += 2) {
			for (int y = 0; y < panel1->_height; y += 2) {
				int count = 0;
				for (Point dir : Generate::_DIRECTIONS1) {
					Point p = { x + dir.first, y + dir.second };
					Point sp = panel1->get_sym_point(p, s);
					if (p.first < 0 || p.second < 0 || p.first >= panel1->_width || p.second >= panel1->_height) continue;
					if (((panel1->_grid[p.first][p.second] & Decoration::Dot) && !(panel1->_grid[p.first][p.second] & IntersectionFlags::DOT_IS_INVISIBLE)) ||
						((panel2->_grid[sp.first][sp.second] & Decoration::Dot) && !(panel2->_grid[sp.first][sp.second] & IntersectionFlags::DOT_IS_INVISIBLE))) {
						if (++count == 3) {
							found = true;
							break;
						}
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		//Check for four dots in a circle
		for (int x = 1; x < panel1->_width; x += 2) {
			for (int y = 1; y < panel1->_height; y += 2) {
				int count = 0;
				for (Point dir : Generate::_DIRECTIONS1) {
					Point p = { x + dir.first, y + dir.second };
					Point sp = panel1->get_sym_point(p, s);
					if (((panel1->_grid[p.first][p.second] & Decoration::Dot) && !(panel1->_grid[p.first][p.second] & IntersectionFlags::DOT_IS_INVISIBLE)) ||
						((panel2->_grid[sp.first][sp.second] & Decoration::Dot) && !(panel2->_grid[sp.first][sp.second] & IntersectionFlags::DOT_IS_INVISIBLE))) {
						if (++count == 4) {
							found = true;
							break;
						}
					}
				}
				if (found) break;
			}
			if (found) break;
		}
		if (!found) return true;
	}
	return false;
}

void Special::createArrowPuzzle(int id, int x, int y, int dir, int ticks, const std::vector<Point>& gaps)
{
	generator->initPanel(id);
	generator->clear();
	generator->set(x, y, Decoration::Arrow | (ticks << 12) | (dir << 16));
	for (Point p : gaps) {
		generator->set(p, p.first % 2 ? Decoration::Gap_Row : Decoration::Gap_Column);
	}
	generator->write(id);
	(new ArrowWatchdog(id))->start();
}

void Special::createArrowSecretDoor(int id)
{
	generator->backgroundColor = { 0, 0, 0, 1 };
	generator->arrowColor = { 1, 0.6f, 0, 1 };
	generator->successColor = { 1, 0.6f, 0, 1 };
	generator->initPanel(id);
	generator->clear();
	generator->set(1, 1, Decoration::Arrow | (3 << 12) | (4 << 16));
	generator->set(1, 5, Decoration::Arrow | (3 << 12) | (2 << 16));
	generator->set(1, 9, Decoration::Arrow | (3 << 12) | (5 << 16));
	generator->set(9, 1, Decoration::Arrow | (3 << 12) | (7 << 16));
	generator->set(9, 5, Decoration::Arrow | (3 << 12) | (3 << 16));
	generator->set(9, 9, Decoration::Arrow | (3 << 12) | (6 << 16));
	generator->write(id);
	(new ArrowWatchdog(id))->start();
}

void Special::generateCenterPerspective(int id, const std::vector<std::pair<int, int>>& symbolVec, int symbolType)
{
	std::vector<std::vector<Point>> obstructions = { { { 5, 0 },{ 5, 2 },{ 5, 4 } },{ { 5, 6 },{ 5, 8 },{ 5, 10 } },{ { 0, 5 },{ 2, 5 },{ 4, 5 } },{ { 6, 5 },{ 8, 5 },{ 10, 5 } } };
	generator->setObstructions(obstructions);
	do {
		generator->setFlagOnce(Generate::Config::DisableWrite);
		generator->generate(id, symbolVec);
	} while ((generator->get(5, 5) & 0xFF00) != symbolType);
	generator->write(id);
}

void Special::drawSeedAndDifficulty(int id, int seed, bool hard)
{
	std::vector<float> normalPos = { /*N*/ 8, 28, 8, 12, 19, 28, 19, 12, /*O*/ 25, 12, 31, 12, 31, 28, 25, 28,
		/*R*/ 38, 12, 45, 17, 38, 21, 38, 28, 45, 28, /*M*/ 51, 28, 51, 12, 56, 19, 61, 12, 61, 28,
		/*A*/ 68, 28, 72, 12, 76, 28, 70, 22, 74, 22, /*L*/ 83, 12, 83, 28, 91, 28 };
	std::vector<int> normalConnectA = { /*N*/ 0, 1, 2, /*O*/ 4, 5, 6, 7, /*R*/ 8, 9, 10, 10, 10, /*M*/ 13, 14, 15, 16,
		/*A*/ 18, 19, 21, /*L*/ 23, 24 };
	std::vector<int> normalConnectB = { /*N*/ 1, 2, 3, /*O*/ 5, 6, 7, 4, /*R*/ 9, 10, 8, 11, 12, /*M*/ 14, 15, 16, 17,
		/*A*/ 19, 20, 22, /*L*/ 24, 25 };

	std::vector<float> expertPos = { /*E*/ 17, 11, 8, 11, 8, 27, 17, 27, 8, 19, 17, 19, /*X*/ 23, 11, 30, 27, 30, 11, 23, 27,
		/*P*/ 37, 11, 44, 16, 37, 20, 37, 27, /*E*/ 59, 11, 50, 11, 50, 27, 59, 27, 50, 19, 59, 19,
		/*R*/ 66, 11, 73, 16, 66, 20, 66, 27, 73, 27, /*T*/ 84, 11, 84, 27, 79, 11, 89, 11 };
	std::vector<int> expertConnectA = { /*E*/ 0, 1, 2, 4, /*X*/ 6, 8, /*P*/ 10, 11, 12, 12, /*E*/ 14, 15, 16, 18,
		/*R*/ 20, 21, 22, 22, 22, /*T*/ 25, 27 };
	std::vector<int> expertConnectB = { /*E*/ 1, 2, 3, 5, /*X*/ 7, 9, /*P*/ 11, 12, 10, 13, /*E*/ 15, 16, 17, 19,
		/*R*/ 21, 22, 20, 23, 24, /*T*/ 26, 28 };

	std::vector<float> randomPos = { /*R*/ 9, 71, 16, 76, 9, 80, 9, 87, 16, 87, /*A*/ 22, 87, 26, 72, 30, 87, 25, 82, 28, 82,
		/*N*/ 36, 87, 36, 71, 47, 87, 47, 71, /*D*/ 53, 71, 53, 87, 58, 87, 62, 79, 58, 71, /*O*/ 67, 71, 67, 87, 73, 87, 73, 71,
		/*M*/ 79, 87, 79, 71, 84, 78, 89, 71, 89, 87 };
	std::vector<int> randomConnectA = { /*R*/ 0, 1, 2, 2, 2, /*A*/ 5, 6, 8, /*N*/ 10, 11, 12, /*D*/ 14, 15, 16, 17, 18,
		/*O*/ 19, 20, 21, 22, /*M*/ 23, 24, 25, 26 };
	std::vector<int> randomConnectB = { /*R*/ 1, 2, 0, 3, 4, /*A*/ 6, 7, 9, /*N*/ 11, 12, 13, /*D*/ 15, 16, 17, 18, 14,
		/*O*/ 20, 21, 22, 19, /*M*/ 24, 25, 26, 27 };

	std::vector<std::vector<float>> seedPos = { /*0*/ { 0, 0, 9, 0, 9, 16, 0, 16 }, /*1*/ { 2, 5, 7, 0, 7, 16 },
		/*2*/ { 0, 0, 9, 0, 0, 8, 9, 8, 0, 16, 9, 16 }, /*3*/ { }, /*4*/ { 9, 8, 0, 8, 9, 0, 9, 16 }, /*5*/ { },
		/*6*/ { }, /*7*/ { 0, 0, 9, 0, 9, 6, 4, 11, 4, 16, }, /*8*/ { }, /*9*/ { } };
	seedPos[3] = seedPos[5] = seedPos[6] = seedPos[8] = seedPos[9] = seedPos[2];
	std::vector<std::vector<int>> seedConnectA = { /*0*/ { 0, 1, 2, 3, 0 }, /*1*/ {0, 1}, /*2*/ {0, 1, 2, 2, 4},
		/*3*/ { 0, 1, 2, 3, 4 }, /*4*/ { 0, 1, 2 }, /*5*/ { 0, 0, 2, 3, 4 }, /*6*/ { 0, 0, 2, 3, 4 }, /*7*/ { 0, 1, 2, 3 },
		/*8*/ { 0, 0, 2, 1, 4 }, /*9*/{ 0, 0, 2, 1, 4 } };
	std::vector<std::vector<int>> seedConnectB = { /*0*/ { 1, 2, 3, 0, 2 }, /*1*/ {1, 2}, /*2*/ {1, 3, 3, 4, 5},
		/*3*/ { 1, 3, 3, 5, 5 }, /*4*/ { 1, 2, 3 }, /*5*/ { 1, 2, 3, 5, 5 }, /*6*/ { 1, 4, 3, 5, 5 }, /*7*/ { 1, 2, 3, 4 },
		/*8*/ { 1, 4, 3, 5, 5 }, /*9*/{ 1, 2, 3, 5, 5 } };

	std::vector<float> intersections = hard ? expertPos : normalPos;
	std::vector<int> connectionsA = hard ? expertConnectA : normalConnectA;
	std::vector<int> connectionsB = hard ? expertConnectB : normalConnectB;

	if (seed <= 0) {
		int offset = static_cast<int>(intersections.size() / 2);
		for (int i : randomConnectA)
			connectionsA.push_back(i + offset);
		for (int i : randomConnectB)
			connectionsB.push_back(i + offset);
		for (float f : randomPos)
			intersections.push_back(f);
	}
	else {
		for (int x = 82; x >= 5; x -= 15) {
			int digit = seed % 10;
			int offset = static_cast<int>(intersections.size() / 2);
			for (int i : seedConnectA[digit])
				connectionsA.push_back(i + offset);
			for (int i : seedConnectB[digit])
				connectionsB.push_back(i + offset);
			for (int i = 0; i < seedPos[digit].size(); i += 2) {
				intersections.push_back(seedPos[digit][i] + x);
				intersections.push_back(seedPos[digit][i + 1] + 70);
			}
			seed /= 10;
		}
	}

	std::vector<int> intersectionFlags;
	for (int i = 0; i < intersections.size(); i++) {
		intersections[i] /= 100.0f;
		if (i % 2 == 0) {
			intersectionFlags.push_back(0);
			intersections[i] += 0.01f;
		}
		else intersections[i] = 1 - intersections[i];
	}
	
	//Add the straight line
	intersections.push_back(0.1f); intersections.push_back(0.5f); intersections.push_back(0.9f); intersections.push_back(0.5f);
	intersectionFlags.push_back(Decoration::Start); intersectionFlags.push_back(Decoration::Exit);
	connectionsA.push_back(static_cast<int>(intersectionFlags.size()) - 2); connectionsB.push_back(static_cast<int>(intersectionFlags.size()) - 1);

	Panel panel;
	panel._memory->WritePanelData<float>(id, PATH_WIDTH_SCALE, { 0.6f });
	panel._memory->WritePanelData<int>(id, NUM_DOTS, { static_cast<int>(intersectionFlags.size()) });
	panel._memory->WriteArray<float>(id, DOT_POSITIONS, intersections);
	panel._memory->WriteArray<int>(id, DOT_FLAGS, intersectionFlags);
	panel._memory->WritePanelData<int>(id, NUM_CONNECTIONS, { static_cast<int>(connectionsA.size()) });
	panel._memory->WriteArray<int>(id, DOT_CONNECTION_A, connectionsA);
	panel._memory->WriteArray<int>(id, DOT_CONNECTION_B, connectionsB);
	panel._memory->WritePanelData<int>(id, NEEDS_REDRAW, { 1 });
}

void Special::drawGoodLuckPanel(int id)
{
	std::vector<float> intersections = { /*G*/ 32, 7, 22, 7, 22, 22, 32, 22, 32, 15, 29, 15, /*O*/ 39, 7, 39, 22, 47, 22, 47, 7,
		/*O*/ 54, 7, 62, 7, 62, 22, 54, 22, /*D*/ 69, 7, 74, 7, 77, 14.5, 74, 22, 69, 22, /*L*/ 22, 79, 22, 94, 31, 94,
		/*U*/ 38, 79, 38, 94, 46, 94, 46, 79, /*C*/ 60, 79, 55, 79, 52, 86.5, 55, 94, 60, 94, /*K*/ 67, 79, 67, 94, 74, 79, 69, 86.5, 74, 94,
		/*!*/ 80, 79, 80, 89, 80, 94, /*SIGMA*/ 66, 39, 66, 32, 32, 32, 51, 51, 32, 69, 66, 69, 66, 62 };
	std::vector<int> connectionsA = { /*G*/ 0, 1, 2, 3, 4, /*O*/ 6, 7, 8, 9, /*O*/ 10, 11, 12, 13, /*D*/ 14, 15, 16, 17, 18,
		/*L*/ 19, 20, /*U*/ 22, 23, 24, /*C*/ 26, 27, 28, 29, /*K*/ 31, 33, 34, /*!*/ 36, /*SIGMA*/ 39, 40, 41, 42, 43, 44 };
	std::vector<int> connectionsB = { /*G*/ 1, 2, 3, 4, 5, /*O*/ 7, 8, 9, 6, /*O*/ 11, 12, 13, 10, /*D*/ 15, 16, 17, 18, 14,
		/*L*/ 20, 21, /*U*/ 23, 24, 25, /*C*/ 27, 28, 29, 30, /*K*/ 32, 34, 35, /*!*/ 37, /*SIGMA*/ 40, 41, 42, 43, 44, 45 };

	//std::vector<float> intersections = { /*G*/ 32, 7, 22, 7, 22, 22, 32, 22, 32, 15, 29, 15, /*O*/ 39, 7, 39, 22, 47, 22, 47, 7,
	//	/*O*/ 54, 7, 62, 7, 62, 22, 54, 22, /*D*/ 69, 7, 74, 7, 77, 14.5, 74, 22, 69, 22, /*L*/ 22, 79, 22, 94, 31, 94,
	//	/*U*/ 38, 79, 38, 94, 46, 94, 46, 79, /*C*/ 60, 79, 55, 79, 52, 86.5, 55, 94, 60, 94, /*K*/ 67, 79, 67, 94, 74, 79, 69, 86.5, 74, 94,
	//	/*!*/ 80, 79, 80, 89, 80, 94, /*SIGMA*/ 39, 45};
	//std::vector<int> connectionsA = { /*G*/ 0, 1, 2, 3, 4, /*O*/ 6, 7, 8, 9, /*O*/ 10, 11, 12, 13, /*D*/ 14, 15, 16, 17, 18,
	//	/*L*/ 19, 20, /*U*/ 22, 23, 24, /*C*/ 26, 27, 28, 29, /*K*/ 31, 33, 34, /*!*/ 36, /*SIGMA*/ 39 };
	//std::vector<int> connectionsB = { /*G*/ 1, 2, 3, 4, 5, /*O*/ 7, 8, 9, 6, /*O*/ 11, 12, 13, 10, /*D*/ 15, 16, 17, 18, 14,
	//	/*L*/ 20, 21, /*U*/ 23, 24, 25, /*C*/ 27, 28, 29, 30, /*K*/ 32, 34, 35, /*!*/ 37, /*SIGMA*/ 45 };

	std::vector<int> intersectionFlags;
	for (int i = 0; i < intersections.size(); i++) {
		intersections[i] /= 100.0f;
		if (i % 2 == 0) intersectionFlags.push_back(0);
		else intersections[i] = 1 - intersections[i];
	}
	intersectionFlags[39] = Decoration::Start; intersectionFlags[45] = Decoration::Exit;

	Panel panel;
	panel._memory->WritePanelData<float>(id, PATH_WIDTH_SCALE, { 0.6f });
	panel._memory->WritePanelData<int>(id, NUM_DOTS, { static_cast<int>(intersectionFlags.size()) });
	panel._memory->WriteArray<float>(id, DOT_POSITIONS, intersections);
	panel._memory->WriteArray<int>(id, DOT_FLAGS, intersectionFlags);
	panel._memory->WritePanelData<int>(id, NUM_CONNECTIONS, { static_cast<int>(connectionsA.size()) });
	panel._memory->WriteArray<int>(id, DOT_CONNECTION_A, connectionsA);
	panel._memory->WriteArray<int>(id, DOT_CONNECTION_B, connectionsB);
	panel._memory->WritePanelData<int>(id, NEEDS_REDRAW, { 1 });
}

int Special::findGlobals() {
	Panel panel;
	int address = 0;
	for (int i = 0x620000; i < 0x660000; i += 4) {
		Memory::GLOBALS = i;
		try {
			if ((address = panel._memory->ReadPanelData<int>(0x17E52, STYLE_FLAGS, 1)[0]) == 0x0000A040) {
				return i;
			}
		}
		catch (std::exception) {}
	}
	for (int i = 0x600000; i < 0x620000; i += 4) {
		Memory::GLOBALS = i;
		try {
			if ((address = panel._memory->ReadPanelData<int>(0x17E52, STYLE_FLAGS, 1)[0]) == 0x0000A040) {
				return i;
			}
		}
		catch (std::exception) {}
	}
	return 0;
}


void Special::makeFullStonesPuzzle(int id, int width, int height, int black_stones, int white_stones) {
	for (int i = 0; i < black_stones; i++) {
		/* generator->WriteColors
		generator->setSymbol(Decoration::Stone, Random::rand()% width, Random::rand() % height); */
	}
	generator->write(id);
}

//For testing/debugging purposes only
void Special::test() {

}

