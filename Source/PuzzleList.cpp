// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "PuzzleList.h"
#include "Watchdog.h"

void PuzzleList::GenerateAllN()
{
	generator->setLoadingData(336);
	CopyTargetsN();
	GenerateTutorialN();
	GenerateSymmetryN();
	GenerateQuarryN();
	GenerateBunkerN();
	GenerateSwampN();
	GenerateTreehouseN();
	GenerateTownN();
	GenerateVaultsN();
	GenerateTrianglePanelsN();
	GenerateOrchardN();
	GenerateDesertN();
	GenerateKeepN();
	GenerateJungleN();
	GenerateMountainN();
	GenerateCavesN();
	SetWindowText(_handle, L"Done!");
	(new ArrowWatchdog(0x0056E))->start(); //Easy way to close the randomizer when the game is done
	//GenerateShadowsN(); //Can't randomize
	//GenerateMonasteryN(); //Can't randomize
}

void PuzzleList::GenerateAllH()
{
	generator->setLoadingData(349);
	CopyTargetsH();
	GenerateTutorialH();
	GenerateSymmetryH();
	GenerateQuarryH();
	GenerateBunkerH();
	GenerateSwampH();
	GenerateTreehouseH();
	GenerateTownH();
	GenerateVaultsH();
	GenerateTrianglePanelsH();
	GenerateOrchardH();
	GenerateKeepH();
	GenerateMountainH();
	GenerateCavesH();
	GenerateDesertH();
	SetWindowText(_handle, L"Done!");
}

void PuzzleList::GenerateAllP() {
	generator->setLoadingData(400);
	CopyTargetsP();
	GenerateTutorialP();
	GenerateSymmetryP();
	GenerateQuarryP();
	GenerateBunkerP();
	GenerateSwampP();
	GenerateTreehouseP();
	GenerateTownP();
	GenerateVaultsP();
	GenerateTrianglePanelsP();
	GenerateOrchardP();
	GenerateKeepP();
	GenerateMountainP();
	GenerateCavesP();
	GenerateDesertP();
	SetWindowText(_handle, L"Done!");
}

void PuzzleList::CopyTargetsN()
{
	/*
	* Target pool for future
	* Tutorial Discard
	* Tutorial Vault
	* Sym Discard
	* Desert Discard
	* Desert Vault
	* Mill Control Room 2
	* Treehouse Purple Bridge 1 Last Panel
	* Treehouse Purple Bridge 2 Last Panel
	* Treehouse Green Bridge Last Panel
	* Treehouse Green Bridge Discard
	* Treehouse Laser Discard
	* Shipwreck Discard
	* Shipwreck Vault
	* Theater Discard
	* Town Orange Crate
	* Town Star Door
	* Town RGB
	* Town Rooftop Discard
	* Jungle Vault
	* Bunker Entry Door
	* Swamp Tutorial Set
	* Swamp Red Shortcut
	* Swamp Purple Shortcut
	* Swamp Final Shortcut
	* Mountainside Discard
	* Mountainside Vault
	* UTM Panels in General
	*/

	Special::copyTarget(0x0C373, 0x033D4); // Tutorial Patio Floor -> Tutorial Vault
	Special::copyTarget(0x033D4, 0x04CA4); // Tutorial Vault -> Tutorial Optional Door 2
	Special::copyTarget(0x17CFB, 0x0A171); // Tutorial Discard -> Tutorial Optional Door 1
	Special::copyTarget(0x17D01, 0x19650); // Town Crate Discard -> Shadows Laser
	Special::copyTarget(0x00021, 0x28A0D); // Stones Tutorial -> Town Church Star Door
	Special::copyTarget(0x00A5B, 0x28A79); // Sym Laser Yellow 3 -> Lower Town Stairs
	Special::copyTarget(0x17D6C, 0x28B39); // Treehouse First Purple 5 -> Town Red Hexagonal Panel
	Special::copyTarget(0x28A0D, 0x28A69); // Town Church Stars -> Town Lattice
	Special::copyTarget(0x17C71, 0x17CA4); // Town Rooftop Discard -> Monastary Laser
	Special::copyTarget(0x17D27, 0x17CAB); // Keep Discard Panel -> Jungle Pop-up Wall
	Special::copyTarget(0x17F9B, 0x17CAB); // Jungle Discard -> Jungle Pop-up Wall
	Special::copyTarget(0x032FF, 0x17C2E); // Orchard 5 -> Bunker Entry Door
	Special::copyTarget(0x17C2E, 0x09DE0); // Bunker Entry Door -> Bunker Laser
	Special::copyTarget(0x00061, 0x09E85); // Dots Tutorial -> Town UTM Shortcut
 
	Special::setPower(0x28B39, true); // Town Red Hex Panel
	Special::setPower(0x17CA4, true); // Monastary Laser
	Special::setPower(0x17CAB, true); // Jungle Pop-up Wall

	Special::clearTarget(0x28A69); // Town Lattice
	Special::clearTarget(0x0360E); // Keep Front Laser

	//To fix issues caused by previous versions of simga's. Don't know if it still applies now. Don't want to find out.
	Special::setPower(0x009AB, true); //Swamp underwater
	Special::setPower(0x28998, true); //Town Yellow Door
}

void PuzzleList::CopyTargetsH()
{
	Special::setPower(0x0005D, true);
	Special::setPower(0x0005E, true);
	Special::setPower(0x0005F, true);
	Special::setPower(0x00060, true);
	Special::setPower(0x00061, true);
	Special::copyTarget(0x0005D, 0x28B39);//Town Red Hexagonal Panel
	Special::copyTarget(0x0005E, 0x03616);//Jungle Laser
	Special::copyTarget(0x0005F, 0x19650);//Shadows Laser
	Special::copyTarget(0x00060, 0x17CA4);//Monastary Laser
	Special::copyTarget(0x00061, 0x03608);//Desert Laser
}

void PuzzleList::CopyTargetsP() {
	Special::copyTarget(0x033D4, 0x04CA4); // Tutorial Vault -> Tutorial Optional Door 2
	Special::copyTarget(0x17CFB, 0x0A171); // Tutorial Discard -> Tutorial Optinal Door 1
	Special::copyTarget(0x17D01, 0x19650); // Town Crate Discard -> Shadows Laser
	Special::copyTarget(0x00021, 0x28A0D); // Stones Tutorial -> Town Church Star Door
	Special::copyTarget(0x28A0D, 0x28A69); // Town Church Stars -> Town Lattice
	Special::copyTarget(0x17D27, 0x03713); // Keep Discard Panel -> Monastary Shortcut
	Special::copyTarget(0x17C71, 0x17CA4); // Town Rooftop Discard -> Monastary Laser
	Special::copyTarget(0x17F9B, 0x17CAB); // Jungle Discard -> Jungle Pop-up wall
	Special::copyTarget(0x00061, 0x17C2E); // Dots Tutorial -> Bunker Entry Door
	Special::copyTarget(0x17C2E, 0x09DE0); // Bunker Entry Door -> Bunker Laser

	Special::setPower(0x28B39, true); // Town Red Hex Panel
	Special::setPower(0x3369D, true); // Lower Elevator Control
	Special::setPower(0x17CA4, true); // Monastary Laser
	Special::setPower(0x17CAB, true); // Jungle Pop-up Wall

	Special::clearTarget(0x28A69); // Town Lattice
	Special::clearTarget(0x0360E); // Keep Front Laser

	//To fix issues caused by previous versions of simga's. Don't know if it still applies now. Don't want to find out.
	Special::setPower(0x009AB, true); //Swamp underwater
	Special::setPower(0x28998, true); //Town Yellow Door
}

//Normal Mode

void PuzzleList::GenerateTutorialN()
{
	generator->setLoadingData(L"Tutorial", 23);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, false);
	//Special::drawGoodLuckPanel(0x00182);
	//generator->generate(0x00182, Decoration::Gap, 1);

	//Mazes
	generator->generate(0x00293, Decoration::Gap, 15);
	generator->generate(0x00295, Decoration::Gap, 35);
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x002C2, Decoration::Gap, 95);

	//2 starts maze
	generator->generate(0x0A3B2, Decoration::Gap, 30);

	//2 exits maze
	generator->generateMaze(0x0A3B5);

	//Tutorial Floor
	//generator->setFlagOnce(Generate::Config::PreserveStructure);
	//generator->setSymbol(Decoration::Gap, 0, 10);
	//generator->generate(0x0C373, Decoration::Dot, 2);

	//Secret back area
	generator->generate(0x0A171, Decoration::Dot_Intersection, 25, Decoration::Gap, 1);
	generator->generate(0x04CA4, Decoration::Dot_Intersection, 25, Decoration::Gap, 2);

	//Dots Tutorial
	generator->setFlag(Generate::Config::FullGaps);
	generator->generate(0x0005D, Decoration::Dot, 2);
	generator->setFlag(Generate::Config::PreserveStructure);
	generator->generate(0x0005E, Decoration::Dot, 5);
	generator->generate(0x0005F, Decoration::Dot, 5);
	generator->generate(0x00060, Decoration::Dot, 6);
	generator->generate(0x00061, Decoration::Dot, 6);

	//Stones Tutorial
	generator->resetConfig();

	//These 4 need short path to work
	generator->setFlag(Generate::Config::ShortPath);
	generator->generate(0x018AF, Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);
	generator->generate(0x0001B, Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);
	generator->generate(0x012C9, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 1);
	generator->generate(0x0001C, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 1);

	generator->resetConfig();
	generator->generate(0x0001D, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x0001E, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x0001F, Decoration::Stone | Decoration::Color::Black, 10, Decoration::Stone | Decoration::Color::White, 5);
	generator->generate(0x00020, Decoration::Stone | Decoration::Color::Black, 10, Decoration::Stone | Decoration::Color::White, 5);
	generator->generate(0x00021, Decoration::Stone | Decoration::Color::Black, 7, Decoration::Stone | Decoration::Color::White, 5);
}

void PuzzleList::GenerateSymmetryN()
{
	generator->setLoadingData(L"Symmetry", 30);
	generator->resetConfig();
	//Back Wall
	//generator->setFlag(Generate::Config::StartEdgeOnly);
	generator->setSymmetry(Panel::Symmetry::Vertical);
	generator->generate(0x00086, Decoration::Gap, 4);
	generator->generate(0x00087, Decoration::Gap, 4);
	generator->generate(0x00059, Decoration::Gap, 10);
	generator->generate(0x00062, Decoration::Gap, 15);
	generator->generate(0x0005C, Decoration::Gap, 45);

	//Kiln Rotational Set
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x0008D, Decoration::Gap, 4);
	generator->generate(0x00081, Decoration::Gap, 4);
	generator->generate(0x00083, Decoration::Gap, 7);

	//Melting Set
	generator->setFlag(Generate::Config::DisableReset);
	generator->generate(0x00084, Decoration::Gap, 15);
	generator->write(0x00082);
	generator->write(0x0343A);

	//Black Dots
	generator->resetConfig();
	generator->setSymmetry(Panel::Symmetry::Horizontal);
	generator->generate(0x00022, Decoration::Dot, 6);
	generator->generate(0x00023, Decoration::Dot, 3);
	generator->generate(0x00024, Decoration::Dot, 7);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x00025, Decoration::Dot, 7);
	generator->generate(0x00026, Decoration::Dot, 6);

	//Colored Dots
	generator->setSymmetry(Panel::Symmetry::Vertical);
	generator->generate(0x0007C, Decoration::Dot | Decoration::Color::Blue, 3, Decoration::Dot | Decoration::Color::Yellow, 3);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x0007E, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00075, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 2);

	generator->resetConfig();
	generator->setSymmetry(Panel::Symmetry::Rotational);
	//TODO: Find out why dots overlap here
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x00073, Decoration::Dot | Decoration::Color::Blue, 3, Decoration::Dot | Decoration::Color::Yellow, 3, Decoration::Dot, 2);

	generator->generate(0x00077, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1, Decoration::Dot, 1);
	generator->generate(0x00079, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 2, Decoration::Dot, 4);

	//Fading Lines
	generator->generate(0x00065, Decoration::Dot | Decoration::Color::Blue, 4, Decoration::Dot | Decoration::Color::Yellow, 2);
	generator->generate(0x0006D, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 4);
	generator->generate(0x00072, Decoration::Dot | Decoration::Color::Blue, 3, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->setSymmetry(Panel::Symmetry::Vertical);
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x0006F, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x00070, Decoration::Dot | Decoration::Color::Blue, 1, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00071, Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 1);
	generator->generate(0x00076, Decoration::Dot | Decoration::Color::Yellow, 3);

	//Doors
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::FullGaps);
	generator->generate(0x000B0, Decoration::Gap, 1, Decoration::Dot, 4);
	
	//TODO: Make a custom gen function that makes this not skip all of sym occasinally
	/*generator->blockPos = { {0,0},{1,0},{2,0},{3,0},{4,0},{5,0},{6,0},{7,0},{8,0}, {0,2},{1,2},{2,2},{3,2},{4,2},{5,2},{6,2},{7,2},{8,2}, 
	{0,6},{1,6},{2,6},{3,6},{4,6},{5,6},{6,6},{7,6},{8,6}, {0,8},{1,8},{2,8},{3,8},{4,8},{5,8},{6,8},{7,8},{8,8}, {0,1},{2,1},{4,1},{6,1},{8,1},
	{0,7},{2,7},{4,7},{6,7},{8,7} };*/
	/*generator->blockPos = { {0,0},{0,1},{0,2},{0,3},{0,4},{0,5},{0,6},{0,7},{0,8}, {2,0},{2,1},{2,2},{2,3},{2,4},{2,5},{2,6},{2,7},{2,8},
	{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7},{6,8}, {8,0},{8,1},{8,2},{8,3},{8,4},{8,5},{8,6},{8,7},{8,8}, {1,0},{1,2},{1,4},{1,6},{1,8},
	{7,0},{7,2},{7,4},{7,6},{7,8} };*/
	//generator->openPos = { {0,4},{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4}, {0,3},{2,3},{4,3},{6,3},{8,3}, {0,5},{2,5},{4,5},{6,5},{8,5} };
	/*generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x1C349, Decoration::Dot, 2);*/

	//Laser Blue and Yellow
	//These puzzles are kind of weird in that looks like a fullGap/regular break hybrid, and so I decided to keep the structure.
	generator->resetConfig();
	generator->setFlag(Generate::Config::PreserveStructure);
	specialCase->generateReflectionDotPuzzle(generator, 0x00A52, 0x00A61, { {Decoration::Dot, 5 },
		  {Decoration::Gap, 4} }, Panel::Symmetry::Vertical, false);
	generator->setFlagOnce(Generate::Config::ShortPath);
	specialCase->generateReflectionDotPuzzle(generator, 0x00A57, 0x00A64, { {Decoration::Dot, 6 },
		  {Decoration::Gap, 1} }, Panel::Symmetry::Vertical, false);
	specialCase->generateReflectionDotPuzzle(generator, 0x00A5B, 0x00A68, { {Decoration::Dot, 8 },
		  }, Panel::Symmetry::Rotational, false);
}

void PuzzleList::GenerateOrchardN()
{
	generator->resetConfig();
	specialCase->generateApplePuzzle(0x00143, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x0003B, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x00055, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x032F7, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x032FF, true, Random::rand() % 2 == 0);
}

void PuzzleList::GenerateDesertN()
{
	generator->resetConfig();
	Randomizer().RandomizeDesert();
}

void PuzzleList::GenerateQuarryN()
{
	generator->setLoadingData(L"Quarry", 39);
	generator->resetConfig();

	//Entry Gates
	generator->generate(0x09E57, Decoration::Stone | Decoration::Color::Black, 11, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x17C09, Decoration::Poly, 2);

	//Mill Entry Doors
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x01E5A, Decoration::Stone | Decoration::Color::Black, 12, Decoration::Stone | Decoration::Color::White, 3);

	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x01E59, Decoration::Dot, 10);

	//Mill Lower Row
	generator->generate(0x00E0C, Decoration::Eraser | Decoration::Color::Green, 1, Decoration::Dot, 1);
	generator->generate(0x01489, Decoration::Eraser | Decoration::Color::Green, 1, Decoration::Dot, 4);
	generator->generate(0x0148A, Decoration::Eraser | Decoration::Color::Green, 1, Decoration::Dot, 8);
	
	//This one needs false parity to work because it's 4x4 and the math is off.
	generator->setFlagOnce(Generate::Config::FalseParity);
	generator->generate(0x014D9, Decoration::Eraser | Decoration::Color::Green, 1, Decoration::Dot, 16);

	generator->generate(0x014E7, Decoration::Dot, 7);
	generator->generate(0x014E8, Decoration::Eraser | Decoration::Color::Green, 1, Decoration::Dot, 7);

	//Mill Upper Row
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x00557, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Black, 2,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x005F1, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 2,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x00620, Decoration::Stone | Decoration::Color::White, 7, Decoration::Stone | Decoration::Color::Black, 1,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x009F5, Decoration::Stone | Decoration::Color::White, 6, Decoration::Stone | Decoration::Color::Black, 2,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x0146C, Decoration::Stone | Decoration::Color::White, 8, Decoration::Stone | Decoration::Color::Black, 4,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x3C12D, Decoration::Stone | Decoration::Color::White, 7, Decoration::Stone | Decoration::Color::Black, 5,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x03686, Decoration::Stone | Decoration::Color::White, 11, Decoration::Stone | Decoration::Color::Black, 1,
		Decoration::Stone | Decoration::Color::Red, 1, Decoration::Stone | Decoration::Color::Cyan, 1, Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x014E9, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 3,
		Decoration::Stone | Decoration::Color::Red, 3, Decoration::Eraser | Decoration::Color::Green, 1);

	//Control Room Panels
	generator->generate(0x0367C, Decoration::Stone | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::Black, 7, Decoration::Dot, 4,
		Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x3C125, Decoration::Stone | Decoration::Color::White, 7, Decoration::Stone | Decoration::Color::Black, 7, Decoration::Dot, 8,
		Decoration::Eraser | Decoration::Color::Purple, 1);

	//Stairs
	generator->generate(0x03677, Decoration::Stone | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::Black, 4,
		Decoration::Eraser | Decoration::Color::Purple, 1);

	//Activate the Boathouse Ramp Panels
	generator->generate(0x034D4, Decoration::Star | Decoration::White, 10, Decoration::Star | Decoration::Black, 6);
	generator->generate(0x021D5, Decoration::Poly, 1, Decoration::Poly | Decoration::Can_Rotate, 1, Decoration::Gap, 3);
	
	//Boathouse Lower Row
	generator->resetConfig();
	generator->generate(0x021B3, Decoration::Poly, 3, Decoration::Eraser | Decoration::Color::Purple, 1);
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x021B4, Decoration::Poly, 3, Decoration::Eraser | Decoration::Color::Purple, 1);
	generator->generate(0x021B0, Decoration::Poly, 2, Decoration::Eraser | Decoration::Color::Purple, 1);

	//This didn't work so I removed a poly
	/*generator->setFlagOnce(Generate::Config::ShortPath);*/
	generator->generate(0x021AF, Decoration::Poly, 3, Decoration::Eraser | Decoration::Color::Purple, 1);

	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x021AE, Decoration::Poly, 3, Decoration::Eraser | Decoration::Color::Purple, 1);

	//Boathouse Upper Row
	//Stars
	generator->generate(0x021B5, Decoration::Star | Decoration::Color::Green, 3, Decoration::Eraser | Decoration::Color::Magenta, 1, 
		Decoration::Gap, 2);
	generator->generate(0x021B6, Decoration::Star | Decoration::Color::Magenta, 3, Decoration::Eraser | Decoration::Color::Magenta, 1, 
		Decoration::Gap, 2);
	generator->generate(0x021B7, Decoration::Star | Decoration::Color::Green, 4, Decoration::Star | Decoration::Color::Orange, 5, 
		Decoration::Eraser | Decoration::Color::Magenta, 1);
	generator->generate(0x021BB, Decoration::Star | Decoration::Color::Magenta, 4, Decoration::Star | Decoration::Color::Orange, 5,
		Decoration::Eraser | Decoration::Color::Magenta, 1);
	generator->generate(0x09DB5, Decoration::Star | Decoration::Color::Magenta, 1, Decoration::Star | Decoration::Color::Green, 1, 
		Decoration::Eraser | Decoration::Color::Magenta, 1, Decoration::Eraser | Decoration::Color::Green, 1);
	generator->generate(0x09DB1, Decoration::Star | Decoration::Color::Orange, 9, Decoration::Eraser | Decoration::Color::Orange, 1);
	generator->generate(0x3C124, Decoration::Star | Decoration::Color::Orange, 9, Decoration::Eraser | Decoration::Color::Orange, 1);

	//Stars + Shapes
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x09DB3, Decoration::Star | Decoration::Color::White, 5, Decoration::Poly | Decoration::Color::Green, 2, 
		Decoration::Eraser | Decoration::Color::Black, 1);
	generator->generate(0x09DB4, Decoration::Star | Decoration::Color::White, 4, Decoration::Poly | Decoration::Color::Green, 2, 
		Decoration::Eraser | Decoration::Color::Black, 1);
	generator->generate(0x0A3CB, Decoration::Star | Decoration::Color::Black, 1, Decoration::Poly | Decoration::Color::Green, 3, 
		Decoration::Eraser | Decoration::Color::Cyan, 1);
	generator->generate(0x0A3CC, Decoration::Star | Decoration::Color::Black, 3, Decoration::Poly | Decoration::Color::Green, 3, 
		Decoration::Eraser | Decoration::Color::Cyan, 1);
	generator->generate(0x0A3D0, Decoration::Star | Decoration::Color::Black, 4, Decoration::Poly | Decoration::Color::Green, 3, 
		Decoration::Eraser | Decoration::Color::Cyan, 1);
}

void PuzzleList::GenerateTreehouseN()
{
	generator->setLoadingData(L"Treehouse", 57);
	generator->resetConfig();

	//The first 2 green bridge panels
	generator->setFlag(Generate::Config::WriteColors);
	generator->generate(0x17E4D, Decoration::Star | Decoration::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 2, Decoration::Gap, 1);
	generator->generate(0x17E4F, Decoration::Star | Decoration::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 2);

	//Credits to Mr_ParK3r2 for coding the rest of treehouse.
	generator->resetConfig();
	generator->generate(0x288C, Decoration::Star | Decoration::Color::Orange, 2);
	generator->generate(0x02886, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Gap, 1);
	generator->generate(0x0A182, Decoration::Star | Decoration::Color::Orange, 8);
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17D72, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Gap, 5);
	generator->generate(0x17D8F, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Gap, 8);
	generator->generate(0x17D74, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Gap, 1);
	generator->generate(0x17DAC, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Gap, 1);
	generator->generate(0x17D9E, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Gap, 9);
	generator->generate(0x17DB9, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Gap, 7);
	generator->generate(0x17D9C, Decoration::Star | Decoration::Color::Orange, 6);
	generator->generate(0x17DC2, Decoration::Star | Decoration::Color::Orange, 6);
	generator->generate(0x17DC4, Decoration::Star | Decoration::Color::Orange, 8);
	//YELLOW BRIDGE DONE
	generator->generate(0x17D88, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Gap, 1);
	generator->generate(0x17DB4, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Gap, 1);
	generator->generate(0x17D8C, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Star | Decoration::Color::Magenta, 2);
	generator->setGridSize(4,4);
	generator->setObstructions({ { 1, 2 },{ 1, 4 },{ 7, 2 },{ 7, 4 },{ 2, 1 },{ 4, 1 },{ 6, 1 } });
	generator->generate(0x17CE3, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Star | Decoration::Color::Magenta, 4, Decoration::Gap, 2);
	generator->resetConfig();
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17DCD, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Star | Decoration::Color::Magenta, 4);
	generator->generate(0x17DB2, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Star | Decoration::Color::Magenta, 6);
	generator->generate(0x17DCC, Decoration::Star | Decoration::Color::Orange, 6, Decoration::Star | Decoration::Color::Magenta, 6);
	generator->generate(0x17DCA, Decoration::Star | Decoration::Color::Orange, 8, Decoration::Star | Decoration::Color::Magenta, 4);
	generator->generate(0x17D8E, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Star | Decoration::Color::Green, 2, Decoration::Gap, 2);
	//generator->setObstructions({ {3,2},{3,4},{4,1},{5,2},{5,4} });
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x17DB7, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Star | Decoration::Color::Magenta, 4, Decoration::Star | Decoration::Color::Green, 4, Decoration::Gap, 2);
	generator->generate(0x17DB1, Decoration::Star | Decoration::Color::Orange, 6, Decoration::Star | Decoration::Color::Magenta, 4, Decoration::Star | Decoration::Color::Green, 2);
	generator->generate(0x17DA2, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Star | Decoration::Color::Magenta, 4, Decoration::Star | Decoration::Color::Green, 4);
	//RIGHT BRIDGE DONE
	generator->generate(0x17D9B, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Black, 1);
	generator->generate(0x17D99, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 2);
	generator->generate(0x17DAA, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 2);
	generator->generate(0x17D97, Decoration::Star | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::Black, 2);
	generator->generate(0x17BDF, Decoration::Star | Decoration::Color::Green, 4, Decoration::Stone | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::Magenta, 2);
	generator->setFlag(Generate::Config::DisableReset);
	generator->generate(0x17D91, Decoration::Star | Decoration::Color::Magenta, 6, Decoration::Stone | Decoration::Color::Orange, 4, Decoration::Stone | Decoration::Color::Green, 4);
	generator->place_gaps(2);
	generator->write(0x17DC6);
	//PURPLE BRIDGE 2
	generator->resetConfig();
	generator->generate(0x17DB3, Decoration::Star | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x17DB5, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x17DB6, Decoration::Star | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x17DC0, Decoration::Star | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->generate(0x17DD7, Decoration::Star | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);
	
	generator->setFlag(Generate::Config::WriteColors);
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17DD9, Decoration::Star | Decoration::Color::Magenta, 1, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Green, 1, Decoration::Stone | Decoration::Color::Magenta, 1);
	generator->generate(0x17DB8, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Green, 1, Decoration::Stone | Decoration::Color::Magenta, 1);
	generator->generate(0x17DDC, Decoration::Star | Decoration::Color::Magenta, 1, Decoration::Stone | Decoration::Color::Magenta, 1, Decoration::Stone | Decoration::Color::Green, 3);
	
	generator->setObstructions({ { 1, 2 },{ 1, 4 },{ 9, 2 },{ 9, 4 },{ 2, 1 },{ 4, 1 },{ 6, 1 },{ 8, 1 } });
	generator->generate(0x17DD1, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Stone | Decoration::Color::Magenta, 4, Decoration::Stone | Decoration::Color::Green, 4);
	generator->resetConfig();
	generator->setFlag(Generate::Config::WriteColors);
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17DDE, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Stone | Decoration::Color::Magenta, 1, Decoration::Stone | Decoration::Color::Green, 2);
	generator->generate(0x17DE3, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Star | Decoration::Color::Green, 2, Decoration::Stone | Decoration::Color::Magenta, 1, Decoration::Stone | Decoration::Color::Green, 1);
	generator->generate(0x17DEC, Decoration::Star | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::Black, 3);
	generator->generate(0x17DAE, Decoration::Star | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::Black, 2);
	generator->generate(0x17DB0, Decoration::Star | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 5, Decoration::Stone | Decoration::Color::Black, 1);
	generator->generate(0x17DDB, Decoration::Star | Decoration::Color::White, 4, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Black, 3);
	//LEFT BRIDGE
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x17DC8, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Dot, 5);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x17DC7, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Dot, 5);
	generator->resetConfig();
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17CE4, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Dot, 4);
	generator->generate(0x17D2D, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Dot, 4);
	generator->generate(0x17D6C, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Dot, 8);
	//PURPLE BRIDGE
	generator->setFlag(Generate::Config::WriteColors);
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x17E3C, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 2);
	generator->setObstructions({ {1,2},{1,4},{2,1},{4,1},{6,1},{8,1},{9,2},{9,4} });
	generator->setFlagOnce(Generate::Config::BigShapes);
	generator->generate(0x17E52, Decoration::Star | Decoration::Color::Magenta, 6, Decoration::Poly | Decoration::Can_Rotate | Decoration::Color::Orange, 1);
	generator->generate(0x17E5B, Decoration::Star | Decoration::Color::Magenta, 3, Decoration::Poly | Decoration::Color::Orange, 2, Decoration::Poly | Decoration::Color::Magenta, 1);
	generator->generate(0x17E5F, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Poly | Decoration::Color::Orange | Decoration::Can_Rotate, 2, Decoration::Poly | Decoration::Negative | Decoration::Color::Blue, 1);
	generator->generate(0x17E61, Decoration::Star | Decoration::Color::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 3, Decoration::Star | Decoration::Color::Green, 2);
	generator->setFlag(Generate::Config::WriteColors);
	generator->generate(0x17E4D, Decoration::Star | Decoration::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 2, Decoration::Gap, 1);
	generator->generate(0x17E4F, Decoration::Star | Decoration::Magenta, 2, Decoration::Poly | Decoration::Color::Orange, 2);
	//GREEN BRIDGE
}

void PuzzleList::GenerateKeepN()
{
	generator->setLoadingData(L"Keep", 5);
	generator->resetConfig();
	//Yellow
	//I couldn't do this one myself, So I dedcided to just leave it at sigma's.
	generator->setSymbol(Decoration::Gap_Column, 8, 3);
	generator->setSymbol(Decoration::Gap_Column, 4, 5);
	generator->setSymbol(Decoration::Gap_Row, 3, 0);
	generator->setSymbol(Decoration::Gap_Row, 3, 2);
	generator->setSymbol(Decoration::Gap_Row, 5, 6);
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->setObstructions({ { 1, 4 },{ 2, 3 },{ 5, 4 },{ 5, 8 } });
	generator->generate(0x033EA);
	std::set<Point> path1 = generator->_path;
	std::vector<std::vector<Point>> sets = { { { 7, 8 },{ 8, 7 },{ 7, 6 },{ 6, 7 } },{ { 6, 5 },{ 7, 4 },{ 8, 5 } },{ { 7, 0 },{ 7, 2 },{ 6, 1 },{ 8, 1 },{ 5, 2 } },
	{ { 2, 7 },{ 4, 7 },{ 3, 8 },{ 3, 6 },{ 1, 6 } },{ { 0, 1 },{ 1, 0 },{ 2, 1 },{ 1, 2 } } };
	for (std::vector<Point> set : sets) {
		Point p = pick_random(set);
		while (!path1.count(p)) p = pick_random(set);
		generator->set(p, p.first % 2 == 0 ? Decoration::Dot_Column : Decoration::Dot_Row);
	}
	generator->write(0x033EA);

	//Purple
	generator->resetConfig();
	generator->setObstructions({ { 3, 2 } , { 8, 5 } });
	generator->generate(0x01BE9, Decoration::Stone | Decoration::Black, 4, Decoration::Stone | Decoration::White, 4);

	//Green
	generator->resetConfig();
	generator->setObstructions({ { 5, 8 } });
	generator->generate(0x01CD3, Decoration::Poly, 2);

	//Blue
	generator->resetConfig();
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x01D3F, Decoration::Poly | Decoration::Can_Rotate, 2);

	//Keep Back Laser
	generator->resetConfig();
	generator->generate(0x03317, Decoration::Dot, 2, Decoration::Gap, 5, Decoration::Stone | Decoration::Color::Black, 4, 
		Decoration::Stone | Decoration::Color::White, 4, Decoration::Poly | Decoration::Can_Rotate, 2, Decoration::Poly, 2);
}

void PuzzleList::GenerateTownN()
{
	generator->setLoadingData(L"Town", 20);
	generator->resetConfig();

	//Full Dots + Poly
	generator->generate(0x2899C, Decoration::Dot_Intersection, 25, Decoration::Poly | Decoration::Can_Rotate, 1);
	generator->generate(0x28A33, Decoration::Dot_Intersection, 25, Decoration::Poly | Decoration::Can_Rotate, 1, Decoration::Poly, 1);
	generator->generate(0x28ABF, Decoration::Dot_Intersection, 25, Decoration::Poly | Decoration::Can_Rotate, 1, Decoration::Poly, 2);
	generator->generate(0x28AC0, Decoration::Dot_Intersection, 25, Decoration::Poly | Decoration::Can_Rotate, 2);
	generator->generate(0x28AC1, Decoration::Dot_Intersection, 25, Decoration::Poly | Decoration::Can_Rotate, 2);

	//Full Dots Eraser Panel
	generator->generate(0x28AD9, Decoration::Dot_Intersection, 25, Decoration::Eraser | Decoration::White, 1, Decoration::Poly, 1);

	//Cinema Puzzles
	generator->setFlag(Generate::Config::PreserveStructure);
	generator->generate(0x17F89, Decoration::Gap, 2, Decoration::Stone | Decoration::Black, 11, Decoration::Stone | Decoration::White, 4);

	generator->resetConfig();
	generator->setFlag(Generate::Config::FixBackground);
	generator->setFlagOnce(Generate::Config::CombineErasers);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->generate(0x0A168, Decoration::Gap, 2, Decoration::Stone | Decoration::Black, 12, Decoration::Stone | Decoration::White, 4, 
		Decoration::Eraser | Decoration::White, 2);
	//These didn't work, so I removed the panel structure.
	generator->generate(0x33AB2, Decoration::Gap, 2, Decoration::Stone | Decoration::Black, 4, Decoration::Poly, 4);

	//Orange Crate
	generator->resetConfig();
	generator->generate(0x0A0C8, Decoration::Stone | Decoration::Black, 1, Decoration::Stone | Decoration::White, 3, Decoration::Poly, 4);

	//Blue Sym
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x28AC7, Decoration::Stone | Decoration::Black, 2, Decoration::Stone | Decoration::White, 3);
	generator->generate(0x28AC8, Decoration::Stone | Decoration::Black, 2, Decoration::Stone | Decoration::White, 3);
	generator->generate(0x28ACA, Decoration::Stone | Decoration::Black, 3, Decoration::Stone | Decoration::White, 3);
	generator->generate(0x28ACB, Decoration::Stone | Decoration::Black, 4, Decoration::Stone | Decoration::White, 4, Decoration::Dot, 1);
	generator->generate(0x28ACC, Decoration::Stone | Decoration::Black, 4, Decoration::Stone | Decoration::White, 4, Decoration::Dot, 1);

	//Yellow Door
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x28998, Decoration::Poly | Decoration::Can_Rotate, 5, Decoration::Star | Decoration::Color::White, 6);

	//Soundproof Room
	specialCase->generateSoundDotPuzzle(0x034E3, { 4, 4 }, {DOT_SMALL, DOT_MEDIUM, DOT_LARGE, DOT_LARGE}, false);

	//RGB area puzzles
	generator->resetConfig();
	generator->generate(0x03C0C, Decoration::Stone | Decoration::Black, 3, Decoration::Stone | Decoration::White, 4, Decoration::Stone | Decoration::Red, 1, 
		Decoration::Stone | Decoration::Green, 3, Decoration::Stone | Decoration::Cyan, 1, Decoration::Stone | Decoration::Magenta, 1, 
		Decoration::Stone | Decoration::Yellow, 3);
	generator->generate(0x03C08, Decoration::Star | Decoration::Color::Black, 4, Decoration::Star | Decoration::Color::White, 4, 
		Decoration::Star | Decoration::Color::Red, 4, Decoration::Star | Decoration::Color::Magenta, 4);

	//Church Stars //TODO: Figure out what on earth is going on here
	specialCase->generateColorFilterPuzzle(0x28A0D, { 4, 4 }, { std::make_pair<int, int>(Decoration::Star | 1, 6),
		std::make_pair<int,int>(Decoration::Star | 2, 6), std::make_pair<int,int>(Decoration::Star | 3, 4) }, { 1, 1, 0, 0 });
}

void PuzzleList::GenerateBunkerN()
{
	generator->resetConfig();
	generator->generate(0x17C2E, Decoration::Stone | Decoration::Color::White, 2, Decoration::Stone | Decoration::Color::Black, 2);

	//TODO: Attempt to randomize the rest of bunker by changing the color of the alreadly-placed stones. Placing objects on squares is impossible, but edges are ok.
	//generator->generate(0x09F7D, Decoration::Gap, 1);
}

void PuzzleList::GenerateJungleN()
{
	generator->setLoadingData(L"Jungle", 6);
	generator->resetConfig();

	//Jungle Wall //TODO: Figure out how to work with gaps for first dot puzzle
	/*generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->generate(0x0026D, Decoration::Gap, 1);*/
	specialCase->generateSoundDotPuzzle(0x0026D, { 2, 2 }, { DOT_SMALL, DOT_LARGE }, true);
	/*generator->place_gaps(1);*/
	specialCase->generateSoundDotPuzzle(0x0026E, { 2, 2 }, { DOT_SMALL, DOT_LARGE }, true);
	specialCase->generateSoundDotPuzzle(0x0026F, { 4, 4 }, { DOT_MEDIUM, DOT_MEDIUM, DOT_SMALL, DOT_MEDIUM, DOT_LARGE }, false);
	specialCase->generateSoundDotPuzzle(0x00C3F, { 4, 4 }, { DOT_SMALL, DOT_MEDIUM, DOT_SMALL, DOT_LARGE }, true);
	specialCase->generateSoundDotPuzzle(0x00C41, { 4, 4 }, { DOT_SMALL, DOT_SMALL, DOT_LARGE, DOT_MEDIUM, DOT_LARGE }, true);
	if (Random::rand() % 2) specialCase->generateSoundDotPuzzle(0x014B2, { 4, 4 }, { DOT_SMALL, DOT_LARGE, DOT_SMALL, DOT_LARGE, DOT_MEDIUM }, true);
	else specialCase->generateSoundDotPuzzle(0x014B2, { 4, 4 }, { DOT_LARGE, DOT_MEDIUM, DOT_SMALL, DOT_LARGE, DOT_SMALL }, true);
}

void PuzzleList::GenerateSwampN()
{
	generator->setLoadingData(L"Swamp", 49);
	generator->resetConfig();

	//Tutorial
	generator->setFlag(Generate::Config::SmallShapes);
	generator->generate(0x00469, Decoration::Poly, 1);
	generator->generate(0x00472, Decoration::Poly, 1);
	generator->generate(0x00262, Decoration::Poly, 1);
	generator->generate(0x00474, Decoration::Poly, 1);
	generator->resetConfig();

	generator->generate(0x00553, Decoration::Poly, 1, Decoration::Gap, 3);
	generator->generate(0x0056F, Decoration::Poly, 1, Decoration::Gap, 6);

	generator->setFlag(Generate::Config::SmallShapes);
	//These two didn't work so I made it bigger
	generator->setGridSize(2,3);
	//generator->setFlag(Generate::Config::ShortPath);
	generator->generate(0x00390, Decoration::Poly, 2, Decoration::Gap, 2);
	generator->generate(0x010CA, Decoration::Poly, 2, Decoration::Gap, 1);

	generator->resetConfig();
	generator->setFlag(Generate::Config::SmallShapes);
	generator->generate(0x00983, Decoration::Poly, 2);

	generator->resetConfig();
	generator->generate(0x00984, Decoration::Poly, 2);
	generator->generate(0x00986, Decoration::Poly, 2);
	generator->generate(0x00985, Decoration::Poly, 2);
	generator->generate(0x00987, Decoration::Poly, 2);
	generator->generate(0x181A9, Decoration::Poly, 2);

	//Red Panels
	generator->resetConfig();
	generator->generate(0x00982, Decoration::Poly, 3, Decoration::Gap, 1);
	generator->generate(0x0097F, Decoration::Poly, 3, Decoration::Gap, 1);
	generator->generate(0x0098F, Decoration::Poly, 3);
	generator->generate(0x00990, Decoration::Poly, 4);

	//Red Shortcut Panels //TODO: Custom gen for vanilla-like behavior.
	generator->resetConfig();
	//generator->setFlag(Generate::Config::DisableReset);
	generator->generate(0x17C0E, Decoration::Poly, 3);
	//generator->setGridSize(5,5);
	//generator->write(0x17C0D);
	generator->generate(0x17C0D, Decoration::Poly, 3);

	//Disconnected Shapes
	generator->resetConfig();
	generator->setFlag(Generate::Config::DisconnectShapes);
	generator->generate(0x00999, Decoration::Poly, 2);
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x0099D, Decoration::Poly, 2);
	generator->generate(0x009A0, Decoration::Poly, 3);
	generator->generate(0x009A1, Decoration::Poly, 3);

	//Rotating Shapes
	generator->resetConfig();
	generator->generate(0x00007, Decoration::Poly | Decoration::Can_Rotate, 1);
	generator->generate(0x00008, Decoration::Poly | Decoration::Can_Rotate, 1);
	generator->generate(0x00009, Decoration::Poly | Decoration::Can_Rotate, 2, Decoration::Gap, 2);
	generator->generate(0x0000A, Decoration::Poly | Decoration::Can_Rotate, 1, Decoration::Gap, 6);
	
	//5x5 Rotating Shapes
	generator->resetConfig();
	generator->generate(0x003B2, Decoration::Poly | Decoration::Can_Rotate, 3, Decoration::Gap, 4);

	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	generator->generate(0x00A1E, Decoration::Poly | Decoration::Can_Rotate, 3);

	generator->setFlagOnce(Generate::Config::BigShapes);
	generator->generate(0x00C2E, Decoration::Poly | Decoration::Can_Rotate, 2, Decoration::Poly, 1, Decoration::Gap, 4);

	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	generator->generate(0x00E3A, Decoration::Poly | Decoration::Can_Rotate, 3, Decoration::Poly, 1);
	 
	//Optional Tetris
	generator->resetConfig();
	generator->generate(0x009A6, Decoration::Poly, 7);
	
	//Negative Shapes 1
	generator->resetConfig();
	generator->generate(0x009AB, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x009AD, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x009AE, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x009AF, Decoration::Poly, 4, Decoration::Poly | Decoration::Negative, 1);
	generator->setFlagOnce(Generate::Config::BigShapes);
	generator->generate(0x00006, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 1);

	//Negative Shapes 2
	generator->resetConfig();
	generator->generate(0x00002, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x00004, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 2);
	generator->generate(0x00005, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x013E6, Decoration::Poly, 3, Decoration::Poly | Decoration::Negative, 1);
	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	generator->setFlagOnce(Generate::Config::BigShapes);
	generator->generate(0x00596, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 2);

	//Negative Shapes 3
	generator->resetConfig();
	generator->generate(0x00001, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 1);
	generator->generate(0x014D2, Decoration::Poly, 1, Decoration::Poly | Decoration::Negative, 2);
	generator->generate(0x014D4, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 3);
	generator->generate(0x014D1, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 4, Decoration::Gap, 2);

	//Exit Shortcuts
	generator->resetConfig();
	generator->generate(0x17C05, Decoration::Poly | Decoration::Can_Rotate, 1);

	generator->setFlagOnce(Generate::Config::BigShapes);
	generator->generate(0x17C02, Decoration::Poly, 1, Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative, 1);
}

void PuzzleList::GenerateMountainN()
{
	std::wstring text = L"Mountain Perspective";
	SetWindowText(_handle, text.c_str());
	specialCase->generateMountaintop(0x17C34, { { Decoration::Stone | Decoration::Color::Black, 2 },{ Decoration::Stone | Decoration::Color::White, 2, }, });

	generator->setLoadingData(L"Mountain", 39);
	generator->resetConfig();

	//Purple Bridge //TODO: Custom gen to allow for tetris piece
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	std::set<Point> bpoints1 = { { 6, 3 },{ 5, 4 },{ 7, 4 } };
	std::set<Point> bpoints2 = { { 6, 5 },{ 5, 6 },{ 6, 7 },{ 7, 6 } };
	std::set<Point> bpoints3 = { { 3, 6 },{ 4, 7 } };
	if (Random::rand() % 2 == 0) generator->hitPoints = { generator->pick_random(bpoints1), generator->pick_random(bpoints2), generator->pick_random(bpoints3) };
	else generator->hitPoints = { generator->pick_random(bpoints3), generator->pick_random(bpoints2), generator->pick_random(bpoints1) };
	generator->setObstructions({ { 4, 1 },{ 6, 1 },{ 8, 1 } });
	generator->blockPos = { { 1, 1 },{ 11, 1 },{ 1, 11 },{ 11, 11 } };
	generator->setSymbol(Decoration::Gap_Row, 3, 4);
	generator->generate(0x09E39, Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);

	//Orange
	generator->resetConfig();
	generator->generate(0x09E73, Decoration::Dot, 2, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 3);
	generator->generate(0x09E75, Decoration::Dot, 5, Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);
	generator->generate(0x09E78, Decoration::Poly, 1, Decoration::Dot, 1);
	generator->generate(0x09E79, Decoration::Poly | Decoration::Can_Rotate, 2, Decoration::Poly, 1, Decoration::Gap, 2);
	generator->generate(0x09E6C, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 3,
		Decoration::Star | Decoration::Color::Purple, 2, Decoration::Gap, 4);
	generator->generate(0x09E6F, Decoration::Poly, 2, Decoration::Dot, 1);
	generator->generate(0x09E6B, Decoration::Dot, 4);

	//Green
	generator->generate(0x09E7A, Decoration::Dot, 1, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 3);
	generator->generate(0x09E71, Decoration::Dot, 2, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 2);
	generator->generate(0x09E72, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 2, Decoration::Poly, 1);
	generator->generate(0x09E69, Decoration::Dot, 2, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 3);
	generator->generate(0x09E7B, Decoration::Dot, 2, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 3);

	//Purple
	generator->generate(0x09EAD, Decoration::Poly, 2, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 2);
	generator->generate(0x09EAF, Decoration::Poly, 2, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 2);

	//Blue
	generator->setObstructions({ { 4, 3 },{ 5, 4 },{ 5, 6 },{ 5, 8 },{ 5, 10 },{ 6, 9 },{ 7, 10 } });
	generator->generate(0x33AF5, Decoration::Stone | Decoration::Color::Black, 5, Decoration::Stone | Decoration::Color::White, 3);
	if (Random::rand() % 2 == 0) generator->setObstructions({ { 5, 4 },{ 5, 6 },{ 5, 8 },{ 5, 10 },{ 9, 4 },{ 9, 6 },{ 9, 8 },{ 9, 10 },{ 7, 0 },{ 7, 2 } });
	else generator->setObstructions({ { 3, 4 },{ 3, 6 },{ 3, 8 },{ 3, 10 },{ 7, 4 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 5, 0 },{ 5, 2 },{ 9, 0 },{ 9, 2 } });
	generator->generate(0x33AF7, Decoration::Stone | Decoration::Color::Black, 6, Decoration::Stone | Decoration::Color::White, 6);
	generator->setObstructions({ { 0, 1 },{ 0, 3 },{ 0, 5 },{ 0, 7 },{ 9, 4 },{ 1, 4 },{ 1, 6 },{ 1, 8 },{ 2, 7 },{ 2, 9 },{ 3, 8 },{ 3, 10 },{ 4, 9 },{ 5, 8 },{ 5, 10 },
		{ 6, 7 },{ 6, 9 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 8, 5 },{ 8, 7 },{ 8, 9 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 9, 8 },{ 10, 1 },{ 10, 3 },{ 10, 5 } });
	generator->generate(0x09F6E, Decoration::Dot, 5);

	//Dual Bridge Panels
	generator->resetConfig();
	generator->setFlag(Generate::Config::DecorationsOnly);
	generator->setFlag(Generate::Config::ShortPath);
	generator->setFlag(Generate::Config::DisableReset);
	generator->blockPos = { {1,9},{3,9},{5,9},{7,9},{9,9},{11,9},{1,7},{3,7},{5,7},{7,7},{9,7},{11,7} };
	generator->generate(0x09E86, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Stone | Decoration::Color::Black, 1, 
		Decoration::Stone | Decoration::Color::White, 1);
	generator->write(0x09ED8);

	//Rainbow
	generator->resetConfig();
	generator->setFlag(Generate::Config::WriteColors);
	generator->generate(0x09FD3, Decoration::Stone | Decoration::Color::Magenta, 3, Decoration::Stone | Decoration::Color::Green, 3);
	generator->generate(0x09FD4, Decoration::Stone | Decoration::Color::Magenta, 4, Decoration::Stone | Decoration::Color::Green, 3);
	generator->generate(0x09FD6, Decoration::Stone | Decoration::Color::Cyan, 2, Decoration::Stone | Decoration::Color::Yellow, 3,
		Decoration::Star | Decoration::Color::Cyan, 1, Decoration::Star | Decoration::Color::Yellow, 1);
	generator->generate(0x09FD7, { { Decoration::Stone | Decoration::Color::Cyan, 2 },{ Decoration::Stone | Decoration::Color::Magenta, 3 },
		{ Decoration::Star | Decoration::Color::Cyan, 1 },{ Decoration::Star | Decoration::Color::Magenta, 1 },
		{ Decoration::Poly | Decoration::Color::Cyan, 1 } });

	generator->blockPos = { {1,3},{1,7},{1,9},{3,1},{3,5},{3,7},{3,9},{5,1},{5,9},{7,3},{7,7},{9,3},{9,7} };
	generator->generate(0x09FD8, Decoration::Stone | Decoration::Color::Magenta, 3, Decoration::Stone | Decoration::Color::Cyan, 4, 
		Decoration::Stone | Decoration::Color::Yellow, 5);

	//Multipanel
	generator->resetConfig();
	specialCase->generateMultiPuzzle({ 0x09FCC, 0x09FCE, 0x09FCF, 0x09FD0, 0x09FD1, 0x09FD2 }, {
		{ { Decoration::Dot_Intersection, 1 } },
		{ { Decoration::Stone | Decoration::Color::Black, 1 },{ Decoration::Stone | Decoration::Color::White, 1 } },
		{ { Decoration::Poly, 2 } },
		{ { Decoration::Star | Decoration::Color::Magenta, 2 },{ Decoration::Star | Decoration::Color::Green, 2 } },
		{ { Decoration::Stone | Decoration::Color::White, 3 },{ Decoration::Stone | Decoration::Color::Black, 1 } },
		{ { Decoration::Poly, 1 } } }, false);


	//Metapuzzle
	//TODO: Hijack
	specialCase->generateMountainFloor({ 0x09EFF, 0x09F01, 0x09FC1, 0x09F8E }, 0x09FDA);

	//Pillar Room
	generator->resetConfig();
	generator->generate(0x0383D, Decoration::Dot_Intersection, 18, Decoration::Gap, 2);
	generator->setFlag(Generate::Config::WriteColors);
	generator->setFlag(Generate::Config::DecorationsOnly);
	generator->generate(0x0383A, Decoration::Star | Decoration::Color::Orange, 6);
	generator->generate(0x0383F, Decoration::Stone | Decoration::Color::Black, 6, Decoration::Stone | Decoration::Color::White, 4);
	generator->removeFlag(Generate::Config::DecorationsOnly);
	generator->generate(0x09E56, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Dot, 3, Decoration::Gap, 2);
	generator->removeFlag(Generate::Config::WriteColors);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x03859, Decoration::Poly, 2);
	generator->generate(0x09E5A, Decoration::Dot_Intersection, 30, Decoration::Gap, 7);
	generator->setFlagOnce(Generate::Config::WriteColors);
	generator->setSymmetry(Panel::Symmetry::PillarRotational);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x339BB, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::Black, 3,
		Decoration::Stone | Decoration::Color::White, 3);
	generator->setSymmetry(Panel::Symmetry::PillarParallel);
	generator->generate(0x33961, Decoration::Dot, 6);
}

void PuzzleList::GenerateCavesN()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();

	//Entrances
	generator->generate(0x17FA2, Decoration::Triangle3 | Decoration::Color::Orange, 5);
	generator->generate(0x00FF8, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4,
		Decoration::Gap, 1);

	//Blue Symmetry/Tetris
	generator->generate(0x01A0D, Decoration::Poly, 4);
	generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x018A0, Decoration::Poly, 4);
	generator->setFlag(Generate::Config::DisconnectShapes);
	generator->generate(0x009A4, Decoration::Poly, 3);
	generator->generate(0x00A72, Decoration::Poly, 2, Decoration::Poly | Decoration::Negative, 1);

	//Right Near
	generator->resetConfig();
	generator->setFlag(Generate::Config::SmallShapes);
	generator->generate(0x00190, Decoration::Poly, 2, Decoration::Gap, 1);
	generator->generate(0x00558, Decoration::Poly, 2, Decoration::Gap, 1);
	generator->generate(0x00567, Decoration::Poly, 2, Decoration::Gap, 1);
	generator->generate(0x006FE, Decoration::Poly, 2, Decoration::Gap, 1);

	//Left
	generator->generate(0x008B8, Decoration::Poly, 2, Decoration::Gap, 2);
	generator->generate(0x00973, Decoration::Poly, 2, Decoration::Gap, 2);
	generator->generate(0x0097B, Decoration::Poly, 2, Decoration::Gap, 1);
	generator->generate(0x0097D, Decoration::Poly, 2, Decoration::Gap, 2);
	generator->generate(0x0097E, Decoration::Poly, 2, Decoration::Gap, 2);

	generator->resetConfig();
	generator->generate(0x00994, Decoration::Poly, 4, Decoration::Gap, 1);
	generator->generate(0x334D5, Decoration::Poly, 4, Decoration::Gap, 1);
	generator->generate(0x00995, Decoration::Poly, 4, Decoration::Gap, 4);
	generator->generate(0x00996, Decoration::Poly, 3, Decoration::Gap, 4);
	generator->generate(0x00998, Decoration::Poly, 3, Decoration::Gap, 4);
	
	//First alcove
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	generator->generate(0x32962, Decoration::Poly | Decoration::Can_Rotate, 3, Decoration::Poly, 1, Decoration::Gap, 1);
	generator->setFlagOnce(Generate::Config::WriteColors);
	generator->setFlagOnce(Generate::Config::TreehouseLayout);
	generator->generate(0x32966, Decoration::Star | Decoration::Color::Orange, 2, Decoration::Stone | Decoration::Color::Black, 4, 
		Decoration::Stone | Decoration::Color::White, 6);
	generator->setFlagOnce(Generate::Config::WriteColors);
	generator->generate(0x01A31, Decoration::Stone | Decoration::Color::Cyan, 14, Decoration::Stone | Decoration::Color::Yellow, 17);
	generator->setFlagOnce(Generate::Config::AlternateColors);
	generator->generate(0x00B71, Decoration::Stone | Decoration::Color::Black, 3, Decoration::Stone | Decoration::Color::White, 3,
		Decoration::Star | Decoration::Color::Black, 2, Decoration::Eraser | Decoration::Color::White, 1);

	//Perspective
	generator->resetConfig();
	generator->setFlag(Generate::Config::DecorationsOnly);
	std::vector<std::vector<Point>> obstructions = { { { 5, 0 },{ 5, 2 },{ 5, 4 } },{ { 5, 6 },{ 5, 8 },{ 5, 10 } },{ { 0, 5 },{ 2, 5 },{ 4, 5 } },{ { 6, 5 },{ 8, 5 },{ 10, 5 } } };
	generator->setObstructions(obstructions);
	generator->blockPos = { { 5, 5 } };
	generator->setFlag(Generate::Config::SmallShapes);
	generator->generate(0x288EA, Decoration::Poly | Decoration::Can_Rotate, 4);
	generator->setObstructions(obstructions);
	generator->blockPos = { { 5, 5 } };
	generator->generate(0x288FC, Decoration::Poly, 1, Decoration::Poly | Decoration::Can_Rotate, 1,
		Decoration::Stone | Decoration::Color::Black, 1, Decoration::Stone | Decoration::Color::White, 1);
	generator->setObstructions(obstructions);
	generator->blockPos = { { 5, 5 } };
	generator->generate(0x289E7, Decoration::Stone | Decoration::Color::Black, 4, Decoration::Stone | Decoration::Color::White, 4);
	generator->setObstructions(obstructions);
	generator->blockPos = { { 5, 5 } };
	generator->generate(0x288AA, Decoration::Poly, 1, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 2);

	//Full Dots
	// TODO: Custom gen function to not break things.
	generator->resetConfig();
	//generator->setFlagOnce(Generate::Config::DisableDotIntersection);
	//generator->setFlagOnce(Generate::Config::LongestPath);
	//generator->blockPos = { {7,0}, {1,8}, {0,7}, {8,1} };
	generator->generate(0x0A16B, Decoration::Dot_Intersection, 25, Decoration::Start, 1);
	/*generator->setSymbol(Decoration::Dot_Column, 0 + (Random::rand()%5)*2, 1 + (Random::rand() % 4 ) * 2);
	generator->setSymbol(Decoration::Dot_Row, 1 + (Random::rand() % 4) * 2, 0 + (Random::rand() % 5) * 2);*/
	generator->generate(0x0A2CE, Decoration::Dot_Intersection, 25, Decoration::Start, 1);
	/*generator->setSymbol(Decoration::Dot_Column, 0 + (Random::rand() % 5) * 2, 1 + (Random::rand() % 4) * 2);
	generator->setSymbol(Decoration::Dot_Row, 1 + (Random::rand() % 4) * 2, 0 + (Random::rand() % 5) * 2);*/
	generator->generate(0x0A2D7, Decoration::Dot_Intersection, 25, Decoration::Start, 1);
	/*generator->setSymbol(Decoration::Dot_Column, 0 + (Random::rand() % 5) * 2, 1 + (Random::rand() % 4) * 2);
	generator->setSymbol(Decoration::Dot_Column, 0 + (Random::rand() % 5) * 2, 1 + (Random::rand() % 4) * 2);
	generator->setSymbol(Decoration::Dot_Row, 1 + (Random::rand() % 4) * 2, 0 + (Random::rand() % 5) * 2);*/
	generator->generate(0x0A2DD, Decoration::Dot_Intersection, 25, Decoration::Start, 1);
	/*generator->setSymbol(Decoration::Dot_Column, 0 + (Random::rand() % 5) * 2, 1 + (Random::rand() % 4) * 2);*/
	generator->generate(0x0A2EA, Decoration::Dot_Intersection, 25, Decoration::Start, 1);
	generator->resetConfig();
	generator->generate(0x17FB9, Decoration::Dot, 6);
	

	//Invisible Dots
	generator->resetConfig();
	generator->generate(0x0008F, Decoration::Dot, 1);
	generator->generate(0x0006B, Decoration::Dot, 2);
	generator->generate(0x0008B, Decoration::Dot, 4);
	generator->generate(0x0008C, Decoration::Dot, 4);
	generator->generate(0x0008A, Decoration::Dot, 6);
	generator->generate(0x00089, Decoration::Dot, 4);

	generator->resetConfig();
	generator->setFlag(Generate::Config::DisableReset);
	generator->generate(0x0006A, Decoration::Dot, 7);
	generator->place_gaps(2);
	generator->write(0x0006C);

	generator->resetConfig();
	generator->generate(0x00027, Decoration::Dot, 6);
	generator->generate(0x00028, Decoration::Dot, 5);
	generator->generate(0x00029, Decoration::Dot, 6);

	//Triangle Exit
	generator->resetConfig();
	generator->generate(0x17CF2, Decoration::Triangle1 | Decoration::Color::Orange, 4, Decoration::Gap, 2);
	//Stars Exit
	generator->generate(0x021D7, Decoration::Star | Decoration::Color::Cyan, 4, Decoration::Star | Decoration::Color::Yellow, 4, Decoration::Gap, 7);

	//Challenge Pillar
	generator->blockPos = { {1,1},{3,1},{5,1},{7,1},{9,1},{11,1}, {1,5},{3,5},{5,5},{7,5},{9,5},{11,5}, {1,9},{3,9},{5,9},{7,9},{9,9},{11,9} };
	generator->generate(0x09DD5, Decoration::Triangle | Decoration::Color::Orange, 18);
	
	//Challenge Entrance
	generator->resetConfig();
	generator->generate(0x0A16E, Decoration::Poly | Decoration::Color::Green, 4, Decoration::Star | Decoration::Color::Green, 3);
	//Theater Exit
	generator->generate(0x039B4, Decoration::Triangle2 | Decoration::Color::Orange, 3, Decoration::Triangle1 | Decoration::Color::Orange, 4);
	//Town Exit
	generator->generate(0x09E85, Decoration::Triangle1 | Decoration::Color::Orange, 7, Decoration::Triangle2 | Decoration::Color::Orange, 7, 
		Decoration::Triangle3 | Decoration::Color::Orange, 1);
}

void PuzzleList::GenerateVaultsN()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	//Tutorial Vault
	generator->generate(0x033D4, Decoration::Start, 4, Decoration::Dot, 8, Decoration::Stone | Decoration::Color::Black, 7, 
		Decoration::Stone | Decoration::Color::White, 7);

	//Desert Vault
	generator->generate(0x0CC7B, Decoration::Dot_Intersection, 49, Decoration::Poly, 1, Decoration::Poly | Decoration::Can_Rotate, 1, 
		Decoration::Poly | Decoration::Negative, 3);

	//Shipwreck Vault
	specialCase->generateSoundDotReflectionPuzzle(0x00AFB, { 6, 6 }, { DOT_MEDIUM, DOT_LARGE, DOT_MEDIUM, DOT_SMALL }, { DOT_LARGE, DOT_SMALL, DOT_MEDIUM }, 5, false);

	//Mountain Vault
	generator->resetConfig();
	generator->setSymmetry(Panel::Symmetry::Rotational);
	generator->generate(0x002A6, Decoration::Stone | Decoration::Color::White, 1, Decoration::Stone | Decoration::Color::Black, 2,
		Decoration::Dot | Decoration::Color::Blue, 2, Decoration::Dot | Decoration::Color::Yellow, 2);

	//Jungle Vault
	//TODO: Remove a dot
	generator->resetConfig();
	specialCase->generateJungleVault(0x15ADD, false);
}

void PuzzleList::GenerateTrianglePanelsN()
{
	generator->setLoadingData(L"Triangles", 13);
	generator->resetConfig();

	//Tutorial Discard
	generator->generate(0x17CFB, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 5);

	//Sym Discard
	generator->generate(0x3C12B, Decoration::Triangle2 | Decoration::Color::Orange, 1, Decoration::Gap, 4);

	//Desert Discard
	generator->generate(0x17CE7, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 2);

	//Quarry Discard
	generator->generate(0x17CF0, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 4);

	//Treehouse Laser Discard
	generator->generate(0x17FA0, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 6);

	//Treehouse Green Bridge Discard
	generator->generate(0x17FA9, Decoration::Triangle2 | Decoration::Color::Orange, 1, Decoration::Gap, 6);

	//Keep Discard
	generator->generate(0x17D27, Decoration::Triangle2 | Decoration::Color::Orange, 1, Decoration::Gap, 5);

	//Shipwreck Discard
	generator->generate(0x17D28, Decoration::Triangle2 | Decoration::Color::Orange, 1, Decoration::Gap, 4);

	//Town Rooftop Discard
	generator->generate(0x17C71, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 7);

	//Town Orange Crate Discard
	generator->generate(0x17D01, Decoration::Triangle2 | Decoration::Color::Orange, 1, Decoration::Gap, 4);

	//Theater Discard
	generator->generate(0x17CF7, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 5);

	//Jungle Discard
	generator->generate(0x17F9B, Decoration::Triangle1 | Decoration::Color::Orange, 1);

	//Mountainside Discard
	generator->generate(0x17C42, Decoration::Triangle1 | Decoration::Color::Orange, 1, Decoration::Gap, 7);
}

//--------------------------HARD MODE-----------------------------

void PuzzleList::GenerateTutorialH()
{
	generator->setLoadingData(L"Tutorial", 21);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, true);
	//Special::drawGoodLuckPanel(0x00182);
	//Mazes
	generator->generate(0x00293);
	generator->generate(0x00295);
	generator->generate(0x002C2);
	//2 starts maze
	generator->generate(0x0A3B2);
	//2 exits maze
	generator->generate(0x0A3B5);
	//Exit Gate
	//generator->generate(0x03629);
	//Pillar + Patio
	generator->generate(0x0C335);
	generator->generate(0x0C373);
	//Secret back area
	generator->generate(0x0A171);
	generator->generate(0x04CA4);
	//Dots Tutorial
	generator->generate(0x0005D);
	generator->generate(0x0005E);
	generator->generate(0x0005F);
	generator->generate(0x00060);
	generator->generate(0x00061);
	//Stones Tutorial
	generator->generate(0x018AF);
	generator->generate(0x0001B);
	generator->generate(0x012C9);
	generator->generate(0x0001C);
	generator->generate(0x0001D);
	generator->generate(0x0001E);
	generator->generate(0x0001F);
	generator->generate(0x00020);
	generator->generate(0x00021);
}

void PuzzleList::GenerateSymmetryH()
{
	generator->setLoadingData(L"Symmetry", 34);
	generator->resetConfig();

	//Back Wall
	generator->generate(0x00086);
	generator->generate(0x00087);
	generator->generate(0x00059);
	generator->generate(0x00062);
	generator->generate(0x0005C);

	//Kiln 1-3
	generator->generate(0x0008D);
	generator->generate(0x00081);
	generator->generate(0x00083);

	//Melting 1-3
	generator->generate(0x00084);
	generator->generate(0x00082);
	generator->generate(0x0343A);

	//Symmetry Island Door
	generator->generate(0x000B0);

	//Black Dots
	generator->generate(0x00022);
	generator->generate(0x00023);
	generator->generate(0x00024);
	generator->generate(0x00025);
	generator->generate(0x00026);

	//B/Y Dots
	generator->generate(0x0007C);
	generator->generate(0x0007E);
	generator->generate(0x00075);
	generator->generate(0x00073);
	generator->generate(0x00077);
	generator->generate(0x00079);

	//Fading Lines Set
	generator->generate(0x00065);
	generator->generate(0x0006D);
	generator->generate(0x00072);

	//This one doesn't work, so shortPath is used.
	generator->setFlagOnce(Generate::Config::ShortPath);
	generator->generate(0x0006F);

	generator->generate(0x00070);
	generator->generate(0x00071);
	generator->generate(0x00076);

	//Symmetry Island Door 2
	generator->generate(0x1C349);

	//Dot Reflection Dual Panels (before laser)
	//generator->setFlag(Generate::Config::PreserveStructure);
	generator->setFlag(Generate::Config::DecorationsOnly);
	generator->generate(0x00A61);
	generator->generate(0x00A64);
	generator->generate(0x00A68);
	generator->generate(0x00A52);
	generator->generate(0x00A57);
	generator->generate(0x00A5B);
}

void PuzzleList::GenerateQuarryH()
{
	generator->setLoadingData(L"Quarry", 40);
	generator->resetConfig();
	//Entry Gates
	generator->generate(0x09E57);
	generator->generate(0x17C09);
	//Mill Entry Door
	generator->generate(0x01E5A);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	//generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x01E59);
	//Lower Row
	generator->generate(0x00E0C);
	generator->generate(0x01489);
	generator->generate(0x0148A);
	generator->generate(0x014D9);
	generator->generate(0x014E7);
	generator->generate(0x014E8);
	//Upper Row
	generator->generate(0x00557);
	generator->generate(0x005F1);
	generator->generate(0x00620);
	generator->generate(0x009F5);
	generator->generate(0x0146C);
	generator->generate(0x3C12D);
	generator->generate(0x03686);
	generator->generate(0x014E9);
	//Control Room
	generator->generate(0x0367C);
	generator->generate(0x3C125);
	//Stairs
	generator->generate(0x03677);
	//Boathouse Ramp Activation
	generator->generate(0x034D4);
	generator->generate(0x021D5);
	//Boathouse Ramp and Hook
	generator->generate(0x03852);
	generator->generate(0x03858);
	generator->generate(0x275FA);
	//Boathouse Right Side
	generator->generate(0x021B3);
	generator->generate(0x021B4);
	generator->generate(0x021B0);
	generator->generate(0x021AF);
	generator->generate(0x021AE);
	//Boathouse Left Side Towards Shadows
	generator->generate(0x021B5);
	generator->generate(0x021B6);
	generator->generate(0x021B7);
	generator->generate(0x021BB);
	generator->generate(0x09DB5);
	generator->generate(0x09DB1);
	generator->generate(0x3C124);
	generator->generate(0x09DB3);
	generator->generate(0x09DB4);
	//Boathouse Left Side Towards Desert
	generator->generate(0x0A3CB);
	generator->generate(0x0A3CC);
	generator->generate(0x0A3D0);
	//Laser Puzzle
	generator->generate(0x03612);
}

void PuzzleList::GenerateBunkerH()
{
	// I wonder how many people will try these normally lmao
	generator->generate(0x09D9F);
	generator->generate(0x09DA1);
	generator->generate(0x09DA2);
	generator->generate(0x09DAF);
	//generator->generate(0x0A079);
	generator->generate(0x17C2E);
	generator->generate(0x0A010);
	generator->generate(0x0A01B);
	generator->generate(0x0A01F);
	generator->generate(0x09F7D);
	generator->generate(0x09FDC);
	generator->generate(0x09FF7);
	generator->generate(0x09F82);
	generator->generate(0x09FF8);
	generator->generate(0x17E63);
	generator->generate(0x17E67);
}

void PuzzleList::GenerateSwampH()
{
	generator->setLoadingData(L"Swamp", 55);
	generator->resetConfig();
	generator->generate(0x0056E);
	//First row tutorial
	generator->generate(0x00469);
	generator->generate(0x00472);
	generator->generate(0x00262);
	generator->generate(0x00474);
	generator->generate(0x00553);
	generator->generate(0x0056F);
	//Second Row tutorial
	generator->generate(0x00390);
	generator->generate(0x010CA);
	generator->generate(0x00983);
	generator->generate(0x00984);
	generator->generate(0x00986);
	generator->generate(0x00985);
	generator->generate(0x00987);
	generator->generate(0x181A9);
	//Modify bridge
	generator->generate(0x00609);
	generator->generate(0x18488);
	//Red Panels
	generator->generate(0x00982);
	generator->generate(0x0097F);
	generator->generate(0x0098F);
	generator->generate(0x00990);
	//Red Shortcut
	generator->generate(0x17C0D);
	generator->generate(0x17C0E);
	//Disconnected Shapes
	generator->generate(0x00999);
	generator->generate(0x0099D);
	generator->generate(0x009A0);
	generator->generate(0x009A1);
	//Modify rotating bridge
	generator->generate(0x181F5);
	//Stuff After rotating bridge I guess?
	generator->generate(0x00007);
	generator->generate(0x00008);
	generator->generate(0x00009);
	generator->generate(0x0000A);
	generator->generate(0x003B2);
	generator->generate(0x00A1E);
	generator->generate(0x00C2E);
	generator->generate(0x00E3A);
	//Optional Tetris
	generator->generate(0x009A6);
	//Negative Shapes 1
	generator->generate(0x009AB);
	generator->generate(0x009AD);
	generator->generate(0x009AE);
	generator->generate(0x009AF);
	generator->generate(0x00006);
	//Negative Shapes 2
	generator->generate(0x00002);
	generator->generate(0x00004);
	generator->generate(0x00005);
	generator->generate(0x013E6);
	generator->generate(0x00596);
	//Negative Shapes 3
	generator->generate(0x00001);
	generator->generate(0x014D2);
	generator->generate(0x014D4);
	generator->generate(0x014D1);
	//Modify Swamp Island
	//generator->generate(0x17C0A);
	//generator->generate(0x17E07);
	//Exit Shortcut
	generator->generate(0x17C05);
	generator->generate(0x17C02);
	//Flood Gate
	generator->generate(0x17E2B);
}

void PuzzleList::GenerateTreehouseH()
{
	generator->setLoadingData(L"Treehouse", 58);
	generator->resetConfig();
	//Doors
	generator->generate(0x0288C);
	generator->generate(0x02886);
	generator->generate(0x0A182);
	//Yellow Bridge
	generator->setFlag(Generate::Config::TreehouseLayout);
	generator->generate(0x17D72);
	generator->generate(0x17D8F);
	generator->generate(0x17D74);
	generator->generate(0x17DAC);
	generator->generate(0x17D9E);
	generator->generate(0x17DB9);
	generator->generate(0x17D9C);
	generator->generate(0x17DC2);
	generator->generate(0x17DC4);
	//Pink Bridge 1
	generator->generate(0x17DC8);
	generator->generate(0x17DC7);
	generator->generate(0x17CE4);
	generator->generate(0x17D2D);
	generator->generate(0x17D6C);
	//Pink Bridge 2
	generator->generate(0x17D9B);
	generator->generate(0x17D99);
	generator->generate(0x17DAA);
	generator->generate(0x17D97);
	generator->generate(0x17BDF);
	generator->generate(0x17D91);
	generator->generate(0x17DC6);
	//Orange Bridge 1	
	generator->generate(0x17DB3);
	generator->generate(0x17DB5);
	generator->generate(0x17DB6);
	generator->generate(0x17DC0);
	generator->generate(0x17DD7);
	generator->generate(0x17DD9);
	generator->generate(0x17DB8);
	generator->generate(0x17DDC);
	generator->generate(0x17DD1);
	generator->generate(0x17DDE);
	generator->generate(0x17DE3);
	generator->generate(0x17DEC);
	generator->generate(0x17DAE);
	generator->generate(0x17DB0);
	generator->generate(0x17DDB);
	//Orange Bridge 2
	generator->generate(0x17D88);
	generator->generate(0x17DB4);
	generator->generate(0x17D8C);
	generator->generate(0x17CE3);
	generator->generate(0x17DCD);
	generator->generate(0x17DB2);
	generator->generate(0x17DCC);
	generator->generate(0x17DCA);
	generator->generate(0x17D8E);
	generator->generate(0x17DB7);
	generator->generate(0x17DB1);
	generator->generate(0x17DA2);
	//Green Bridge
	generator->generate(0x17E3C);
	generator->generate(0x17E4D);
	generator->generate(0x17E4F);
	generator->generate(0x17E52);
	generator->generate(0x17E5B);
	generator->generate(0x17E5F);
	generator->generate(0x17E61);
	//Drawbridge
	generator->resetConfig();
	generator->generate(0x037FF);
}

void PuzzleList::GenerateTownH()
{
	generator->setLoadingData(L"Town", 21);
	generator->resetConfig();
	//Full Dots + Triangles
	generator->generate(0x2899C);
	generator->generate(0x28A33);
	generator->generate(0x28ABF);
	generator->generate(0x28AC0);
	generator->generate(0x28AC1);
	generator->generate(0x28AD9);

	//generator->generate(0x2896A);

	//Blue Symmetry
	generator->generate(0x28AC7);
	generator->generate(0x28AC8);
	generator->generate(0x28ACA);
	generator->generate(0x28ACB);
	generator->generate(0x28ACC);
	//Glass Door
	generator->generate(0x28998);
	//Church Star Door
	generator->generate(0x28A0D);	//3-color Room
	//Modify switch to remove green
	generator->generate(0x334D8);
	generator->generate(0x03C0C);
	generator->generate(0x03C08);
	//Orange Crate
	generator->generate(0x0A0C8);
	//Windmill Puzzles
	generator->generate(0x17D02);
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x17F5F);*/
	//Theater Puzzles
	generator->generate(0x17F89);
	generator->generate(0x0A168);
	generator->generate(0x33AB2);
}

void PuzzleList::GenerateVaultsH()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	//Tutorial Vault
	generator->generate(0x033D4);
	//Desert Vault
	generator->generate(0x0CC7B);
	//Symmetry Vault
	generator->generate(0x002A6);
	//Jungle Vault
	specialCase->generateJungleVault(0x15ADD, true);
}

void PuzzleList::GenerateTrianglePanelsH()
{
	generator->setLoadingData(L"Arrows", 14);
	generator->resetConfig();
	generator->generate(0x17CFB);
	generator->generate(0x3C12B);
	generator->generate(0x17CE7);
	generator->generate(0x17CF0);
	generator->generate(0x17C71);
	generator->generate(0x17CF7);
	generator->generate(0x17D01);
	generator->generate(0x17F9B);
	generator->generate(0x17D27);
	generator->generate(0x17D28);
	generator->generate(0x17FA9);
	generator->generate(0x17FA0);
	generator->generate(0x17C42);
	generator->generate(0x17F93);
	generator->resetConfig();
}

void PuzzleList::GenerateMountainH()
{
	std::wstring text = L"Mountain Perspective";
	generator->resetConfig();
	specialCase->generateMountaintop(0x17C34, { { Decoration::Stone | Decoration::Color::Black, 1 } });
	generator->setLoadingData(L"Mountain", 39);
	//Purple Bridge
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09E39);
	//Orange Row
	generator->generate(0x09E73);
	generator->generate(0x09E75);
	generator->generate(0x09E78);
	generator->generate(0x09E79);
	generator->generate(0x09E6C);
	generator->generate(0x09E6F);
	generator->generate(0x09E6B);
	//Green Row
	generator->generate(0x09E7A);
	generator->generate(0x09E71);
	generator->generate(0x09E72);
	generator->generate(0x09E69);
	generator->generate(0x09E7B);
	//Purple Panels
	generator->generate(0x09EAD);
	generator->generate(0x09EAF);
	//Blue Row
	generator->generate(0x33AF5);
	generator->generate(0x33AF7);
	generator->generate(0x09F6E);
	//Level 2 Bridges
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09E86);
	generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09ED8);
	//Rainbow Row
	generator->generate(0x09FD3);
	generator->generate(0x09FD4);
	generator->generate(0x09FD6);
	generator->generate(0x09FD7);
	generator->generate(0x09FD8);
	//Multipnael
	generator->generate(0x09FCC);
	generator->generate(0x09FCE);
	generator->generate(0x09FCF);
	generator->generate(0x09FD0);
	generator->generate(0x09FD1);
	generator->generate(0x09FD2);
	//Elevator
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x09EEB);*/
	//Pillar Puzzles
	generator->generate(0x0383D);
	generator->generate(0x0383A);
	generator->generate(0x0383F);
	generator->generate(0x09E56);
	generator->generate(0x03859);
	generator->generate(0x09E5A);
	generator->setSymmetry(Panel::Symmetry::PillarRotational);
	generator->generate(0x339BB);
	generator->resetConfig();
	generator->setSymmetry(Panel::Symmetry::PillarParallel);
	generator->generate(0x33961);
}

void PuzzleList::GenerateCavesH()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();
	generator->generate(0x17FA2);
	//Arrow Puzzles
	generator->generate(0x00FF8);
	generator->generate(0x01A0D);
	generator->generate(0x018A0);
	generator->generate(0x009A4);
	generator->generate(0x00A72);
	generator->generate(0x00190);
	generator->generate(0x00558);
	generator->generate(0x00567);
	generator->generate(0x006FE);
	generator->generate(0x008B8);
	generator->generate(0x00973);
	generator->generate(0x0097B);
	generator->generate(0x0097D);
	generator->generate(0x0097E);
	generator->generate(0x00994);
	generator->generate(0x334D5);
	generator->generate(0x00995);
	generator->generate(0x00996);
	generator->generate(0x00998);
	//First alcove
	generator->generate(0x32962);
	generator->generate(0x32966);
	generator->generate(0x01A31);
	generator->generate(0x00B71);
	//Perspective
	generator->generate(0x288EA);
	generator->generate(0x288FC);
	generator->generate(0x289E7);
	generator->generate(0x288AA);
	//Full Dots + Arrows
	generator->generate(0x0A16B);
	generator->generate(0x0A2CE);
	generator->generate(0x0A2D7);
	generator->generate(0x0A2DD);
	generator->generate(0x0A2EA);
	generator->generate(0x17FB9);
	//Invisible Symbols
	generator->generate(0x0008F);
	generator->generate(0x0006B);
	generator->generate(0x0008B);
	generator->generate(0x0008C);
	generator->generate(0x0008A);
	generator->generate(0x00089);
	generator->generate(0x0006A);
	generator->generate(0x0006C);
	generator->generate(0x00027);
	generator->generate(0x00028);
	generator->generate(0x00029);
	//Arrows Exit
	generator->generate(0x17CF2);
	//Stars Exit
	generator->generate(0x021D7);
	//Elevators
	generator->generate(0x335AB);
	generator->generate(0x3369D);
	generator->generate(0x335AC);
	//Arrow Pillar
	generator->generate(0x09DD5);
	//Challenge Entrance
	generator->generate(0x0A16E);
	//Theater Exit
	generator->generate(0x039B4);
	//Town Exit
	generator->generate(0x09E85);
}

void PuzzleList::GenerateOrchardH()
{

}

void PuzzleList::GenerateKeepH()
{
	generator->setLoadingData(L"Keep", 5);
	generator->resetConfig();
	generator->generate(0x033EA);
	generator->generate(0x01BE9);
	generator->generate(0x01CD3);
	generator->generate(0x01D3F);
	generator->generate(0x03317);
	
	//specialCase->clearTarget(0x0360E); //Must solve pressure plate side
}

void PuzzleList::GenerateDesertH() {
	generator->setLoadingData(L"Desert", 69);
	generator->resetConfig();
	/*generator->setFlagOnce(Generate::Config::PreserveStructure);
	generator->setFlagOnce(Generate::Config::DecorationsOnly);
	generator->generate(0x00698);*/
}

//-------------------------------------Puzzle Pack Mode

void PuzzleList::GenerateRandomPuzzle(int id, int size) 
{
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	std::string typeList [] = { "Decoration::Gap", "Decoration::Dot", "Decoration::Triangle", "Decoration::Arrow", "Decoration::Poly", "Decoration::Star", 
		"Gaps and Dots", "Everything Minus Arrow and Sym" };
	//int typeChoice = Random::rand() % sizeof(typeList);
	int typeChoice = Random::rand() % 8;
	//int typeChoice = 4;
	switch (typeChoice) {
	case 0:
		generator->setGridSize(panelSize, panelSize);
		GenerateSingleMonoColorTypePuzzle(id, Decoration::Gap, 2, panelSize);
		break;
	case 1:
		GenerateSingleMonoColorTypePuzzle(id,Decoration::Dot, 2, panelSize);
		break;
	case 2:
		GenerateSingleMonoColorTypePuzzle(id, Decoration::Triangle, 2, panelSize);
		break;
	case 3:
		GenerateSingleMonoColorTypePuzzle(id, Decoration::Arrow, 2, panelSize);
		break;
	case 4:
		GenerateSingleMonoColorTypePuzzle(id, Decoration::Poly, 5, panelSize);
		break;
	case 5:
		GenerateMonoStarPuzzle(id, panelSize);
		break;
	case 6:
		GenerateGapsAndDots(id, panelSize);
		break;
	case 7:
		if (panelSize >= 4) 
		{
			GenerateEverythingMinusArrowAndSymPanel(id, 4, 2);
		}
		else 
		{
			GenerateEverythingMinusArrowAndSymPanel(id, 3, 1);
		}
		
		break;
	}

	/*generator->generate(id, symbolList[0] | Decoration::Color::Black, Random::rand() % 4, symbolList[0] | Decoration::Color::White, Random::rand() % 4,
		symbolList[1] | Decoration::Color::Black, Random::rand() % 4, symbolList[1] | Decoration::Color::White, Random::rand() % 4);*/
	//GenerateGapsAndDots(id);
}

//Works for Gaps (but I wouldn't recommend it), Dots, Poly, Triangle, and Arrows
//Min sparseness values:
//Gaps, Dots, Triangles, and Arrows: 2, Poly: 4 for easy, 5 for hard, Arrow: 
void PuzzleList::GenerateSingleMonoColorTypePuzzle(int id, int type, int sparseness, int size) 
{
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0) 
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->generate(id, type, (panelSize * panelSize) / sparseness);
}

//Max size: 8
void PuzzleList::GenerateMonoStarPuzzle(int id, int size)
{
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 6) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	int countList [] = { 4, 8, 12, 14, 16, 18 };
	generator->setSymmetry(Panel::Symmetry::None);
	generator->generate(id, Decoration::Star | Decoration::Color::Black, countList[panelSize-3]);
}
	

void PuzzleList::GenerateGapsAndDots(int id, int size)
{
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0) {
		panelSize = (Random::rand() % 9) + 3;
	}
	//int size = 11;
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	//generator->generate(id, Decoration::Dot, Random::rand() % ((size*size)/2), Decoration::Gap, Random::rand() % ((size * size) / 2));
	generator->setSymmetry(Panel::Symmetry::None);
	generator->generate(id, Decoration::Dot, (panelSize * panelSize)/2, Decoration::Gap, (panelSize * panelSize)/2);
}

//1 mult min of size 3. 2 mult min of size 4, mult max of 2
void PuzzleList::GenerateEverythingMinusArrowAndSymPanel(int id, int size, int multiplier) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0 && multiplier == 2) 
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	else if (panelSize == 0) 
	{
		panelSize = 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setFlag(Generate::Config::CombineErasers);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->generate(id, Decoration::Gap, 1 * multiplier, Decoration::Dot, 1 * multiplier, Decoration::Stone | Decoration::Color::Black, 1 * multiplier,
		Decoration::Eraser | Decoration::Color::Black, 1 * multiplier, Decoration::Poly | Decoration::Color::Black, 1 * multiplier,
		Decoration::Poly | Decoration::Negative | Decoration::Color::Black, 1 * multiplier, Decoration::Star | Decoration::Black, 1 * multiplier,
		Decoration::Triangle | Decoration::Color::Black, 1 * multiplier);
}


//FlipNegXY, Horizontal, ParallelH, and ParallelHFlip size min for 1 mult: 3. FlipXY size min for 1 mult: 5.
void PuzzleList::GenerateEverythingMinusArrowPanel(int id, int size, int multiplier) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0) {
		panelSize = (Random::rand() % 9) + 3;
	}
	//int symChoice = Random::rand() % 15;
	int symChoice = 5;
	switch (symChoice) 
	{
		case 0:
			generator->setSymmetry(Panel::Symmetry::FlipNegXY);
			break;
		case 1:
			generator->setSymmetry(Panel::Symmetry::FlipXY);
			break;
		case 2:
			generator->setSymmetry(Panel::Symmetry::Horizontal);
			break;
		case 3:
			generator->setSymmetry(Panel::Symmetry::ParallelH);
			break;
		case 4:
			generator->setSymmetry(Panel::Symmetry::ParallelHFlip);
			break;
		case 5:
			generator->setSymmetry(Panel::Symmetry::ParallelV);
			break;
		case 6:
			generator->setSymmetry(Panel::Symmetry::ParallelVFlip);
			break;
		case 7:
			generator->setSymmetry(Panel::Symmetry::PillarHorizontal);
			break;
		case 8:
			generator->setSymmetry(Panel::Symmetry::PillarParallel);
			break;
		case 9:
			generator->setSymmetry(Panel::Symmetry::PillarRotational);
			break;
		case 10:
			generator->setSymmetry(Panel::Symmetry::PillarVertical);
			break;
		case 11:
			generator->setSymmetry(Panel::Symmetry::RotateLeft);
			break;
		case 12:
			generator->setSymmetry(Panel::Symmetry::RotateRight);
			break;
		case 13:
			generator->setSymmetry(Panel::Symmetry::Rotational);
			break;
		case 14:
			generator->setSymmetry(Panel::Symmetry::Vertical);
			/*generator->setSymbol(Decoration::Start, 0, panelSize * 2);
			generator->setSymbol(Decoration::Start, panelSize * 2, panelSize * 2);*/
			
			break;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->generate(id, Decoration::Gap, 1 * multiplier, Decoration::Dot, 1 * multiplier, Decoration::Stone | Decoration::Color::Black, 1 * multiplier,
		Decoration::Eraser | Decoration::Color::Black, 1 * multiplier, Decoration::Poly | Decoration::Color::Black, 1 * multiplier,
		Decoration::Poly | Decoration::Negative | Decoration::Color::Black, 1 * multiplier, Decoration::Star | Decoration::Black, 1 * multiplier,
		Decoration::Triangle | Decoration::Color::Black, 1 * multiplier, Decoration::Start, 1, Decoration::Exit, 1);
}

//Currently just a showcase of the different types.
void PuzzleList::GenerateTutorialP()
{
	generator->setLoadingData(L"Tutorial", 20);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, false);
	//generator->generate(0x00182, Decoration::Gap, 1);
	//GenerateRandomPuzzle(0x00293, 4);
	GenerateRandomPuzzle(0x00293, 4);
	GenerateRandomPuzzle(0x00295, 4);
	GenerateRandomPuzzle(0x002C2, 4);
	GenerateRandomPuzzle(0x0A3B2, 4);
	//Reason: Control Panel
	//GenerateRandomPuzzle(0x0A3B5, 4);
	GenerateRandomPuzzle(0x0A171, 4);
	GenerateRandomPuzzle(0x04CA4, 4);
	GenerateRandomPuzzle(0x0005D, 4);
	GenerateRandomPuzzle(0x0005E, 4);
	GenerateRandomPuzzle(0x0005F, 4);
	GenerateRandomPuzzle(0x00060, 4);
	GenerateRandomPuzzle(0x00061, 4);
	GenerateRandomPuzzle(0x018AF, 4);
	GenerateRandomPuzzle(0x0001B, 4);
	GenerateRandomPuzzle(0x012C9, 4);
	GenerateRandomPuzzle(0x0001C, 4);
	GenerateRandomPuzzle(0x0001D, 4);
	GenerateRandomPuzzle(0x0001E, 4);
	GenerateRandomPuzzle(0x0001F, 4);
	GenerateRandomPuzzle(0x00020, 4);
	GenerateRandomPuzzle(0x00021, 4);
}

void PuzzleList::GenerateSymmetryP()
{
	generator->setLoadingData(L"Symmetry", 30);
	generator->resetConfig();
	
}

void PuzzleList::GenerateOrchardP()
{
	generator->resetConfig();
	generator->setLoadingData(L"Orchard", 5);
}

void PuzzleList::GenerateDesertP()
{
	generator->resetConfig();
	Randomizer().RandomizeDesert();
}

void PuzzleList::GenerateQuarryP()
{
	generator->setLoadingData(L"Quarry", 39);
	generator->resetConfig();

	
}

void PuzzleList::GenerateTreehouseP()
{
	generator->setLoadingData(L"Treehouse", 57);
	generator->resetConfig();

	
}

void PuzzleList::GenerateKeepP()
{
	generator->setLoadingData(L"Keep", 5);
	generator->resetConfig();
	
}

void PuzzleList::GenerateTownP()
{
	generator->setLoadingData(L"Town", 20);
	generator->resetConfig();

}

void PuzzleList::GenerateBunkerP()
{
	generator->setLoadingData(L"Bunker", 1);
	generator->resetConfig();
	
}

void PuzzleList::GenerateJungleP()
{
	generator->setLoadingData(L"Jungle", 6);
	generator->resetConfig();


}

void PuzzleList::GenerateSwampP()
{
	generator->setLoadingData(L"Swamp", 49);
	generator->resetConfig();

	
}

void PuzzleList::GenerateMountainP()
{
	//std::wstring text = L"Mountain Perspective";
	//SetWindowText(_handle, text.c_str());
	

	generator->setLoadingData(L"Mountain", 39);
	generator->resetConfig();

	
}

void PuzzleList::GenerateCavesP()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();

	
}

void PuzzleList::GenerateVaultsP()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	
}

void PuzzleList::GenerateTrianglePanelsP()
{
	generator->setLoadingData(L"Triangles", 12);
	generator->resetConfig();

	
}