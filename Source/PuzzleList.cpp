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
	GenerateDesertP();
	GenerateKeepP();
	GenerateJungleP();
	GenerateMountainP();
	GenerateCavesP();
	GenerateShadowsP();
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
	Special::copyTarget(0x0C373, 0x033D4); // Tutorial Patio Floor -> Tutorial Vault
	Special::copyTarget(0x033D4, 0x04CA4); // Tutorial Vault -> Tutorial Optional Door 2
	Special::copyTarget(0x17CFB, 0x0A171); // Tutorial Discard -> Tutorial Optional Door 1
	Special::copyTarget(0x17D01, 0x19650); // Town Crate Discard -> Shadows Laser
	Special::copyTarget(0x00A5B, 0x28A79); // Sym Laser Yellow 3 -> Lower Town Stairs
	Special::copyTarget(0x17D6C, 0x28B39); // Treehouse First Purple 5 -> Town Red Hexagonal Panel
	Special::copyTarget(0x28A0D, 0x28A69); // Town Church Stars -> Town Lattice
	Special::copyTarget(0x17C71, 0x17CA4); // Town Rooftop Discard -> Monastary Laser
	Special::copyTarget(0x17D27, 0x17CAB); // Keep Discard Panel -> Jungle Pop-up Wall
	Special::copyTarget(0x17F9B, 0x17CAB); // Jungle Discard -> Jungle Pop-up Wall
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

	//Beam
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

void PuzzleList::GenerateRandomPuzzle(int id, int size, int firstColor, int secondColor, int thirdColor) 
{
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	std::string typeList [] = { "Gaps", "Dots", "Stones", "Stars", "Polys", "Triangles", "Gaps + Dots", "Gaps + Stones", "Gaps + Stars", 
		"Gaps + Polys", "Gaps + Triangles", "Gaps + Sym", "Dots + Stones", "Dots + Stars", "Dots + Polys", "Dots + Triangles", "Dots + Sym",
		"Stones + Stars", "Stones + Polys", "Stones + Triangles", "Stars + Polys", "Stars + Triangles", "Stars + Sym", "Polys + Triangles", "Triangles + Sym"};
	//int typeChoice = Random::rand() % sizeof(typeList);
	int typeChoice = Random::rand() % 25;
	//int typeChoice = 7;
	int subChoice = 0;

	// Used for most mechanics
	int baseSparseness = 2;

	int DotAndGapSparseness = 1;
	int mixedStarSparseness = 3;
	int polySparseness = 4;
	
	switch (typeChoice) {
	case 0:
		//TODO: Multi start puzzle
		//TODO: Multi exit puzzle
		generator->setGridSize(panelSize, panelSize);
		generator->generateMaze(id, 1, 1);
		break;
	case 1:
		subChoice = Random::rand() % 2;
		if (subChoice == 0) {
			GenerateSingleTypePuzzle(id, Decoration::Dot, DotAndGapSparseness, panelSize);
		}
		else {
			GenerateFullDotsPuzzle(id, panelSize);
		}
		break;
	case 2:
		//subChoice = Random::rand() % 2;
		subChoice = 1;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness, Decoration::Stone | secondColor, baseSparseness);
			break;
		case 1:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness + 1, Decoration::Stone | secondColor, baseSparseness + 1,
				Decoration::Stone | thirdColor, baseSparseness + 1);
			break;
		}
		break;
	case 3:
		subChoice = Random::rand() % 2;
		//subChoice = 2;
		switch (subChoice) {
		case 0:
			GenerateMonoStarPuzzle(id, panelSize, firstColor, false);
			break;
		case 1:
			GenerateDualStarPuzzle(id, panelSize, firstColor, secondColor);
			break;
		case 2:
			GenerateTriStarPuzzle(id, panelSize, firstColor, secondColor, thirdColor);
			break;
		}
		break;
	case 4:
		//TODO: Small shapes
		//TODO: Big shapes
		//TODO: Anti Combos
		//TODO: Rot
		//TODO: Disconnect
		subChoice = Random::rand() % 7;
		//subChoice = 5;
		switch (subChoice) {
		case 0:
			GenerateSingleTypePuzzle(id, Decoration::Poly | firstColor, polySparseness, panelSize);
			break;
		case 1:
			GenerateSingleTypePuzzle(id, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness, panelSize);
			break;
		case 2:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness * 2,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness * 2);
			break;
		case 3:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness, Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 4:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 5:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1);
			break;
		case 6:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1);
			break;
		}
		break;
	case 5:
		GenerateSingleTypePuzzle(id, Decoration::Triangle | firstColor, baseSparseness, panelSize);
		break;
	case 6:
		subChoice = Random::rand() % 2;
		//subChoice = 1;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Dot, DotAndGapSparseness);
			break;
		case 1:
			GenerateFullDotsDualPuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness);
			break;
		}
		break;
	case 7:
		subChoice = Random::rand() % 2;
		//subChoice = 1;
		switch (subChoice) {
		case 0:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Stone | firstColor, baseSparseness,
				Decoration::Stone | secondColor, baseSparseness);
			break;
		case 1:
			GenerateQuadTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Stone | firstColor, baseSparseness + 1, 
				Decoration::Stone | secondColor, baseSparseness + 1, Decoration::Stone | thirdColor, baseSparseness + 1);
			break;
		}
		break;
	case 8:
		GenerateMonoStarPuzzleWithNIT(id, panelSize, firstColor, Decoration::Gap, DotAndGapSparseness);
		break;
	case 9:
		//TODO: Disconnect
		//TODO: Small Shapes
		//TODO: Big Shapes
		subChoice = Random::rand() % 7;
		//subChoice = 2;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness);
			break;
		case 1:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness);
			break;
		case 2:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness * 2,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness * 2);
			break;
		case 3:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 4:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 5:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1);
			break;
		case 6:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1);
			break;
		}
		break;
	case 10:
		GenerateDualTypePuzzle(id, panelSize, Decoration::Triangle | firstColor, baseSparseness, Decoration::Gap, DotAndGapSparseness);
		break;
	case 11:
		//TODO: turn to panelSize+1
		//GenerateSymGapsPuzzle(id, panelSize);
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Gap, DotAndGapSparseness + 1);
		break;
	case 12:
		GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Stone | firstColor, baseSparseness,
			Decoration::Stone | secondColor, baseSparseness);
		break;
	case 13:
		//TODO: Full Dots
		//TODO: Multi Color
		//subChoice = Random::rand() % 2;
		//switch(subChoice)
		GenerateMonoStarPuzzleWithNIT(id, panelSize, firstColor, Decoration::Dot, DotAndGapSparseness);
		break;
	case 14:
		//TODO: Disconnect
		//TODO: Small
		//TODO: Big
		subChoice = Random::rand() % 9;
		//subChoice = 3;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness);
			break;
		case 1:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness);
			break;
		case 2:
			GenerateFullDotsDualPuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness);
			break;
		case 3:
			GenerateFullDotsDualPuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness);
			break;
		case 4:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness * 2,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness * 2);
			break;
		case 5:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 6:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness);
			break;
		case 7:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | Decoration::Can_Rotate | firstColor, polySparseness + 1);
			break;
		case 8:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | Decoration::Can_Rotate | firstColor, polySparseness + 1);
			break;
		}
		break;
	case 15:
		//TODO: 1 Full Dots
		subChoice = Random::rand() % 2;
		//subChoice = 6;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Triangle | firstColor, baseSparseness, Decoration::Dot, DotAndGapSparseness);
			break;
		case 1:
			GenerateFullDotsDualPuzzle(id, panelSize, Decoration::Triangle | firstColor, baseSparseness);
			break;
		}
		break;
	case 16:
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Dot, DotAndGapSparseness + 1);
		break;
	case 17:
		//TODO: Different colored stones
		GenerateDualTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness, Decoration::Star | firstColor, mixedStarSparseness);
		break;
	case 18:
		subChoice = Random::rand() % 2;
		switch (subChoice) {
		case 0:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness + 1, Decoration::Stone | secondColor, baseSparseness + 1,
				Decoration::Poly | firstColor, polySparseness);
			break;
		case 1:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness + 1, Decoration::Stone | secondColor, baseSparseness + 1,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness);
			break;
		}
		break;
	case 19:
		GenerateTriTypePuzzle(id, panelSize, Decoration::Stone | firstColor, baseSparseness + 1, Decoration::Stone | secondColor, baseSparseness + 1,
			Decoration::Triangle | firstColor, baseSparseness + 1);
		break;
	case 20:
		//TODO: Rotate
		//TODO: Disconnect
		//TODO: Small
		//TODO: Big
		subChoice = Random::rand() % 10;
		//subChoice = 7;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | firstColor, polySparseness);
			break;
		case 1:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, 
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness + 1);
			break;
		case 2:
			GenerateMonoStarPuzzleWithNIT(id, panelSize, firstColor, Decoration::Poly | secondColor, polySparseness);
			break;
		case 3:
			GenerateMonoStarPuzzleWithNIT(id, panelSize, firstColor, Decoration::Poly | Decoration:: Can_Rotate | secondColor, polySparseness);
			break;
		case 4:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | firstColor, polySparseness * 2, 
				Decoration::Poly | Decoration::Can_Rotate | firstColor, (polySparseness * 2) + 1);
			break;
		case 5:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | secondColor, polySparseness * 2,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, (polySparseness * 2) + 1);
			break;
		case 6:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | firstColor, polySparseness * 2,
				Decoration::Poly | Decoration::Can_Rotate | secondColor, (polySparseness * 2)+1);
			break;
		case 7:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Negative | secondColor, polySparseness);
			break;
		case 8:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness,
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness + 1, Decoration::Poly | Decoration::Negative | secondColor, polySparseness);
			break;
		case 9:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Poly | firstColor, polySparseness,
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | secondColor, polySparseness + 1);
			break;
		}
		break;
	case 21:
		subChoice = Random::rand() % 2;
		//subChoice = 1;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Star | firstColor, mixedStarSparseness, Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 1:
			GenerateMonoStarPuzzleWithNIT(id, panelSize, firstColor, Decoration::Triangle | secondColor, baseSparseness);
			break;
		}
		break;
	case 22:
		GenerateMonoStarPuzzle(id, panelSize, firstColor, true);
		break;
	case 23:
		subChoice = Random::rand() % 7;
		//subChoice = 3;
		switch (subChoice) {
		case 0:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness, Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 1:
			GenerateDualTypePuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness, 
				Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 2:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness * 2, 
				Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness * 2, Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 3:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness, Decoration::Poly | Decoration::Negative | firstColor, polySparseness, 
				Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 4:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness, 
				Decoration::Poly | Decoration::Negative | firstColor, polySparseness, Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 5:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Poly | firstColor, polySparseness, 
				Decoration::Poly | Decoration:: Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1, 
				Decoration::Triangle | firstColor, baseSparseness);
			break;
		case 6:
			GenerateTriTypePuzzle(id, panelSize, Decoration::Poly | Decoration::Can_Rotate | firstColor, polySparseness, 
				Decoration::Poly | Decoration::Can_Rotate | Decoration::Negative | firstColor, polySparseness + 1, Decoration::Triangle | firstColor, baseSparseness);
			break;
		}
		break;
	case 24:
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Triangle | firstColor, baseSparseness + 1);
		break;
	}
}

void PuzzleList::GenerateRandomSymPuzzle(int id, int size, int color) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	std::string typeList[] = { "Gaps", "Dots", "Stars", "Triangles" };
	int typeChoice = Random::rand() % 4;
	//int typeChoice = 0;
	switch (typeChoice) {
	case 0:
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Gap, 2);
		break;
	case 1:
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Dot, 2);
		break;
	case 2:
		GenerateMonoStarPuzzle(id, panelSize, color, true);
		break;
	case 3:
		GenerateSingleTypeSymPuzzle(id, panelSize, Decoration::Triangle | color, 3);
		break;
	}
}

//randSE = random start and exit
void::PuzzleList::GenerateSpecificSingleCount(int id, int size,  int type, int count, bool randSE) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	if (randSE) {
		generator->generate(id, type, count, Decoration::Start, 1, Decoration::Exit, 1);
	}
	else {
		generator->setSymbol(Decoration::Start, 0, panelSize * 2);
		generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
		generator->generate(id, type, count);
	}
}

//Works for Gaps (but I wouldn't recommend it), Dots, Poly, Triangle
//Min sparseness values:
//Gaps and Dots: 1, Triangles: 2, Poly: 4
void PuzzleList::GenerateSingleTypePuzzle(int id, int type, int sparseness, int size) 
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
	generator->setSymbol(Decoration::Start, 0 , panelSize*2);
	generator->setSymbol(Decoration::Exit, panelSize*2, 0);
	int maxSymbolCount = (panelSize * panelSize) / sparseness;
	generator->generate(id, type, (Random::rand() % maxSymbolCount) + 1);
}

void PuzzleList::GenerateSingleTypePuzzleWithFlag(int id, int size, int type, int sparseness, Generate::Config flag) {
	generator->resetConfig();
	generator->setFlagOnce(flag);
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int maxSymbolCount = (panelSize * panelSize) / sparseness;
	generator->generate(id, type, (Random::rand() % maxSymbolCount) + 1);
}

void PuzzleList::GenerateDualTypePuzzle(int id, int size, int firstType, int firstSparseness, int secondType, int secondSparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int firstMaxSymbolCount = (panelSize * panelSize) / firstSparseness;
	int secondMaxSymbolCount = (panelSize * panelSize) / secondSparseness;
	generator->generate(id, firstType, (Random::rand() % firstMaxSymbolCount) + 1, secondType, (Random::rand() % secondMaxSymbolCount) + 1);
}

void PuzzleList::GenerateTriTypePuzzle(int id, int size, int firstType, int firstSparseness, int secondType, int secondSparseness, int thirdType, int thirdSparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int firstMaxSymbolCount = (panelSize * panelSize) / firstSparseness;
	int secondMaxSymbolCount = (panelSize * panelSize) / secondSparseness;
	int thirdMaxSymbolCount = (panelSize * panelSize) / thirdSparseness;
	generator->generate(id, firstType, (Random::rand() % firstMaxSymbolCount) + 1, secondType, (Random::rand() % secondMaxSymbolCount) + 1, 
		thirdType, (Random::rand() % thirdMaxSymbolCount) + 1);
}

void PuzzleList::GenerateQuadTypePuzzle(int id, int size, int firstType, int firstSparseness, int secondType, int secondSparseness, int thirdType, int thirdSparseness,
	int fourthType, int fourthSparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int firstMaxSymbolCount = (panelSize * panelSize) / firstSparseness;
	int secondMaxSymbolCount = (panelSize * panelSize) / secondSparseness;
	int thirdMaxSymbolCount = (panelSize * panelSize) / thirdSparseness;
	int fourthMaxSymbolCount = (panelSize * panelSize) / fourthSparseness;
	generator->generate(id, firstType, (Random::rand() % firstMaxSymbolCount) + 1, secondType, (Random::rand() % secondMaxSymbolCount) + 1,
		thirdType, (Random::rand() % thirdMaxSymbolCount) + 1, fourthType, (Random::rand() % fourthMaxSymbolCount) + 1);
}

//Only set up for size 4.
void PuzzleList::GenerateSingleTypeSymPuzzle(int id, int size, int type, int sparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int maxSymbolCount = (panelSize * panelSize) / sparseness;
	Panel::Symmetry symList4[] = { Panel::Symmetry::FlipNegXY, Panel::Symmetry::Horizontal, Panel::Symmetry::Rotational, Panel::Symmetry::Vertical };
	int symChoice = Random::rand() % 4;
	generator->setSymmetry(symList4[symChoice]);
	generator->generate(id, type, (Random::rand() % maxSymbolCount) + 1, Decoration::Start, 1, Decoration::Exit, 1);
	//generator->generate(id, Decoration::Gap, (Random::rand() % ((panelSize * panelSize) / 2)) + 1, Decoration::Start, 1, Decoration::Exit, 1);
}

void PuzzleList::GenerateDoubleTypeSymPuzzle(int id, int size, int firstType, int firstSparseness, int secondType, int secondSparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int firstMaxSymbolCount = (panelSize * panelSize) / firstSparseness;
	int secondMaxSymbolCount = (panelSize * panelSize) / secondSparseness;
	Panel::Symmetry symList4[] = { Panel::Symmetry::FlipNegXY, Panel::Symmetry::Horizontal, Panel::Symmetry::Rotational, Panel::Symmetry::Vertical };
	int symChoice = Random::rand() % 4;
	generator->setSymmetry(symList4[symChoice]);
	generator->generate(id, firstType, (Random::rand() % firstMaxSymbolCount) + 1, secondType, (Random::rand() % secondMaxSymbolCount) + 1, 
		Decoration::Start, 1, Decoration::Exit, 1);
}

void PuzzleList::GenerateSingleMonoColorDisconnect(int id, int type, int sparseness, int size) {
	generator->setFlagOnce(Generate::Config::DisconnectShapes);
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int maxSymbolCount = (panelSize * panelSize) / sparseness;
	generator->generate(id, type, (Random::rand() % (maxSymbolCount-1)) + 2);
}

void PuzzleList::GenerateFullDotsPuzzle(int id, int size) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = ((Random::rand() % 5)*2) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	generator->generate(id, Decoration::Dot_Intersection, (panelSize + 1) * (panelSize + 1), Decoration::Start, panelSize);
}

void PuzzleList::GenerateFullDotsDualPuzzle(int id, int size, int type, int sparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = ((Random::rand() % 5) * 2) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int maxSymbolCount = (panelSize * panelSize) / sparseness;
	generator->generate(id, Decoration::Dot_Intersection, (panelSize + 1) * (panelSize + 1), type, (Random::rand() % maxSymbolCount) + 1);
}

//Max size: 8
void PuzzleList::GenerateMonoStarPuzzle(int id, int size, int color, bool sym)
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
	if (!sym) {
		generator->setSymmetry(Panel::Symmetry::None);
		generator->setSymbol(Decoration::Start, 0, panelSize * 2);
		generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
		generator->generate(id, Decoration::Star | color, ((Random::rand() % ((countList[panelSize-3]/2) - 1)) + 1) * 2);
	}
	else {
		Panel::Symmetry symList4[] = { Panel::Symmetry::FlipNegXY, Panel::Symmetry::Horizontal, Panel::Symmetry::Rotational, Panel::Symmetry::Vertical };
		int symChoice = Random::rand() % 4;
		generator->setSymmetry(symList4[symChoice]);
		generator->generate(id, Decoration::Start, 1, Decoration::Exit, 1, 
			Decoration::Star | color, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2);
	}
}

void PuzzleList::GenerateMonoStarPuzzleWithNIT(int id, int size, int firstColor, int nonInteractingType, int NITsparseness) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 6) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	int countList[] = { 4, 8, 12, 14, 16, 18 };
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	int maxSymbolCount = (panelSize * panelSize) / NITsparseness;
	generator->generate(id, Decoration::Star | firstColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2, 
		nonInteractingType, (Random::rand() % maxSymbolCount) + 1);
}

void PuzzleList::GenerateDualStarPuzzle(int id, int size, int firstColor, int secondColor) {
	//TODO: Test Counts
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 6) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	int countList[] = { 4, 8, 12, 14, 16, 18 };
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	generator->generate(id, Decoration::Star | firstColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2, 
		Decoration::Star | secondColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2);
}

void PuzzleList::GenerateTriStarPuzzle(int id, int size, int firstColor, int secondColor, int thirdColor) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = (Random::rand() % 6) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	int countList[] = { 2, 4, 8, 12, 16, 18 };
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	generator->generate(id, Decoration::Star | firstColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2,
		Decoration::Star | secondColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2, 
		Decoration::Star | thirdColor, ((Random::rand() % ((countList[panelSize - 3] / 2) - 1)) + 1) * 2);
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
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	generator->generate(id, Decoration::Dot, (Random::rand() % ((panelSize * panelSize)/2)) + 1, Decoration::Gap, (Random::rand() % (panelSize * panelSize) / 2) + 1);
}

//Currently is only set up for size 4.
void PuzzleList::GenerateSymGapsPuzzle(int id, int size) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0)
	{
		panelSize = ((Random::rand() % 5) * 2) + 3;
	}
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	//List of working types on 4x4: 
	//Conditionless: FlipNegXY, Horizontal, Rotational, Vertical
	//With Set Start Points: 
	Panel::Symmetry symList4[] = { Panel::Symmetry::FlipNegXY, Panel::Symmetry::Horizontal, Panel::Symmetry::Rotational, Panel::Symmetry::Vertical };
	int symChoice = Random::rand() % 4;
	generator->setSymmetry(symList4[symChoice]);
	/*generator->setSymbol(Decoration::Start, 0, 0);
	generator->setSymbol(Decoration::Start, panelSize * 2, 0);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Start, panelSize * 2, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize, 0);
	generator->setSymbol(Decoration::Exit, 0, panelSize);
	generator->setSymbol(Decoration::Exit, panelSize, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, panelSize);
	generator->generate(id, Decoration::Gap, (panelSize * panelSize)/2);*/
	generator->generate(id, Decoration::Gap, (Random::rand() % ((panelSize * panelSize) / 2)) + 1, Decoration::Start, 1, Decoration::Exit, 1);
}

//1 mult min of size 3. 2 mult min of size 4, mult max of 3 (so far)
void PuzzleList::GenerateEverythingMinusSymPanel(int id, int size, int maxMultiplier, int color) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0 && maxMultiplier == 2)
	{
		panelSize = (Random::rand() % 9) + 3;
	}
	else if (panelSize == 0) 
	{
		panelSize = 3;
	}
	/*int panelMultiplier = 0;
	if (maxMultiplier == 1) {
		panelMultiplier = 1;
	}
	else {
		panelMultiplier = (Random::rand() % 2) + 1;
	}*/
	int panelMultiplier = maxMultiplier;
	generator->pathWidth = 1.0f - (0.05f * panelSize);
	generator->setGridSize(panelSize, panelSize);
	generator->setFlag(Generate::Config::CombineErasers);
	generator->setFlag(Generate::Config::WriteColors);
	generator->setSymmetry(Panel::Symmetry::None);
	generator->setSymbol(Decoration::Start, 0, panelSize * 2);
	generator->setSymbol(Decoration::Exit, panelSize * 2, 0);
	generator->generate(id, Decoration::Gap, 1 * panelMultiplier, Decoration::Dot, 1 * panelMultiplier, 
		Decoration::Stone | color, 1 * panelMultiplier, Decoration::Eraser | color, 1 * panelMultiplier, 
		Decoration::Poly | color, 1 * panelMultiplier, Decoration::Star | color, 1 * panelMultiplier,
		Decoration::Triangle | color, 1 * panelMultiplier);
}

//FlipNegXY, Horizontal, ParallelH, ParallelHFlip, and ParallelV size min for 1 mult: 3. FlipXY size min for 1 mult: 5.
void PuzzleList::GenerateEverythingPanel(int id, int size, int multiplier) {
	generator->resetConfig();
	int panelSize = size;
	if (panelSize == 0) {
		panelSize = (Random::rand() % 9) + 3;
	}
	//int symChoice = Random::rand() % 15;
	int symChoice = 6;
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

void PuzzleList::GenerateEraserPanel(int id, int size, int sparseness) {
	//TODO: Figure out why eraser are placed on top of each other here.
	generator->resetConfig();
	generator->setFlagOnce(Generate::Config::CombineErasers);
	generator->setFlagOnce(Generate::Config::DisableWrite);
	generator->initPanel(id);
	generator->setGridSize(size, size);
	generator->setSymbol(Decoration::Start, 0, size * 2);
	generator->setSymbol(Decoration::Exit, size * 2, 0);
	generator->generate(id);
	int numErasers = Random::rand() % ( ((size*size) / sparseness ) - 1) + 2;
	//int numErasers = (size * size) / sparseness;
	//int numErasers = 1;
	int x = 0;
	int y = 0;
	for (int i = 0; i < numErasers; i++) {
		x = Random::rand() % 4;
		y = Random::rand() % 4;
		x = x + x + 1;
		y = y + y + 1;
		generator->set(x, y, Decoration::Eraser | Decoration::Color::Black);
	}
	generator->write(0x00293);
}

void PuzzleList::GenerateTutorialP()
{
	generator->setLoadingData(L"Tutorial", 20);
	generator->resetConfig();
	Special::drawSeedAndDifficulty(0x00064, seedIsRNG ? -1 : seed, false);
	//generator->generate(0x00182, Decoration::Gap, 1);
	/*GenerateGapsAndDots(0x00293, 4);*/
	/*generator->resetConfig();
	generator->setGridSize(5,5);
	generator->setFlagOnce(Generate::Config::LongestPath);
	generator->generate(0x00293, Decoration::Dot_Intersection, 25);*/
	
	//GenerateEraserPanel(0x00293, 4, 1);
	/*generator->setFlagOnce(Generate::Config::SmallShapes);
	generator->generate(0x00293, Decoration::Poly, 8);*/
	//GenerateEverythingMinusSymPanel(0x00293, 7, 6, Decoration::Color::Black);
	//GenerateMonoStarPuzzleWithNIT(0x00293, 4, Decoration::Color::Black, Decoration::Stone | Decoration::Color::White, 2);
	//GenerateTriTypePuzzle(0x00293, 4, Decoration::Gap, 1, Decoration::Stone | Decoration::Color::Black, 2, Decoration::Stone | Decoration::Color::White, 2);
	GenerateRandomPuzzle(0x00293, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00295, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x002C2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A3B2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Optional Doors
	GenerateRandomPuzzle(0x0A171, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x04CA4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Dots Tutorial
	GenerateRandomPuzzle(0x0005D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0005E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0005F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00060, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00061, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Stones Tutorial
	GenerateRandomPuzzle(0x018AF, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0001B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x012C9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0001C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0001D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0001E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0001F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00020, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00021, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateSymmetryP()
{
	generator->setLoadingData(L"Symmetry", 30);
	generator->resetConfig();
	//Vertical Symmetry
	GenerateRandomSymPuzzle(0x00086, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00087, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00059, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00062, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x0005C, 4, Decoration::Color::Black);
	
	//Rotational Symmetry
	GenerateRandomSymPuzzle(0x0008D, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00081, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00083, 4, Decoration::Color::Black);

	//Melting Set
	GenerateRandomSymPuzzle(0x00084, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00082, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x0343A, 4, Decoration::Color::Black);

	//Black Dots
	GenerateRandomSymPuzzle(0x00022, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00023, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00024, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00025, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00026, 4, Decoration::Color::Black);
	
	//Colored Dots
	GenerateRandomSymPuzzle(0x0007C, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x0007E, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00075, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00073, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00077, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00079, 4, Decoration::Color::Black);
	
	//Fading Lines
	GenerateRandomSymPuzzle(0x00065, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x0006D, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00072, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x0006F, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00070, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00071, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00076, 4, Decoration::Color::Black);

	//Door 1
	/*generator->resetConfig();
	generator->setFlagOnce(Generate::Config::FullGaps);
	generator->generate(0x000B0, Decoration::Gap, 1, Decoration::Dot, 4);*/
	GenerateRandomPuzzle(0x000B0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	//GenerateDualStarPuzzle(0x000B0, 4, Decoration::Color::Black, Decoration::Color::White);
	
	//Laser Puzzle
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

void PuzzleList::GenerateOrchardP()
{
	generator->setLoadingData(L"Orchard", 5);
	generator->resetConfig();
	//TODO: Figure out how to override orchard panels
	specialCase->generateApplePuzzle(0x00143, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x0003B, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x00055, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x032F7, false, Random::rand() % 2 == 0);
	specialCase->generateApplePuzzle(0x032FF, true, Random::rand() % 2 == 0);
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
	//Quarry Entry Doors
	GenerateRandomPuzzle(0x09E57, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C09, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Mill Entry Doors
	GenerateRandomPuzzle(0x01E5A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x01E59, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Mill Lower Row
	GenerateRandomPuzzle(0x00E0C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x01489, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0148A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x014D9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x014E7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x014E8, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Mill Upper Row
	GenerateRandomPuzzle(0x00557, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x005F1, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00620, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x009F5, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0146C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x3C12D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x03686, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x014E9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Mill Control Room
	GenerateRandomPuzzle(0x0367C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x3C125, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Mill Stairs
	GenerateRandomPuzzle(0x03677, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Boathouse Ramp Activation
	GenerateRandomPuzzle(0x034D4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x021D5, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Boathouse Lower Row
	GenerateRandomPuzzle(0x021B3, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x021B4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x021B0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x021AF, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x021AE, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	// Boathouse Upper Row
	GenerateRandomPuzzle(0x021B5, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x021B6, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x021B7, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x021BB, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x09DB5, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x09DB1, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x3C124, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x09DB3, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x09DB4, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0A3CB, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0A3CC, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0A3D0, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
}

void PuzzleList::GenerateTreehouseP()
{
	generator->setLoadingData(L"Treehouse", 57);
	generator->resetConfig();
	//Starting Doors
	GenerateRandomPuzzle(0x0288C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x02886, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Yellow Bridge
	GenerateRandomPuzzle(0x17D72, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D8F, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D74, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DAC, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D9E, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB9, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D9C, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DC2, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DC4, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);

	//Door 3
	GenerateRandomPuzzle(0x0A182, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Right Orange Bridge
	GenerateRandomPuzzle(0x17D88, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB4, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D8C, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DCD, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB2, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DCC, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DCA, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D8E, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB1, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DA2, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);

	//Purple 1
	GenerateRandomPuzzle(0x17DC8, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DC7, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17CE4, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D2D, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D6C, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);

	//Purple 2
	GenerateRandomPuzzle(0x17D9B, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D99, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DAA, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D97, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17BDF, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17D91, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DC6, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);

	//Left Orange Bridge
	GenerateRandomPuzzle(0x17DB3, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB5, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB6, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DC0, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DD7, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DD9, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB8, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DDC, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DDE, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DE3, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DEC, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DAE, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DB0, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17DDB, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);

	//Green Bridge
	GenerateRandomPuzzle(0x17E3C, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17E4D, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17E4F, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17E5B, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17E5F, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
	GenerateRandomPuzzle(0x17E61, 4, Decoration::Color::Red, Decoration::Color::Purple, Decoration::Color::Blue);
}

void PuzzleList::GenerateKeepP()
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

	//Back Laser
	GenerateRandomPuzzle(0x03317, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateTownP()
{
	generator->setLoadingData(L"Town", 23);
	generator->resetConfig();
	//Town 25 Dots
	GenerateRandomPuzzle(0x2899C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x28A33, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x28ABF, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x28AC0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x28AC1, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x28AD9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Church Stars
	GenerateRandomPuzzle(0x28A0D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Yellow Door
	GenerateRandomPuzzle(0x28998, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Soundproof Room
	specialCase->generateSoundDotPuzzle(0x034E3, { 4, 4 }, { DOT_SMALL, DOT_MEDIUM, DOT_LARGE, DOT_LARGE }, false);

	//RGB
	GenerateRandomPuzzle(0x03C0C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x03C08, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Town Blues
	GenerateRandomSymPuzzle(0x28AC7, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x28AC8, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x28ACA, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x28ACB, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x28ACC, 4, Decoration::Color::Black);

	//Cinema
	GenerateRandomPuzzle(0x17F89, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A168, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x33AB2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Orange Crate
	GenerateRandomPuzzle(0x0A0C8, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateBunkerP()
{
	generator->setLoadingData(L"Bunker", 15);
	generator->resetConfig();
	GenerateRandomPuzzle(0x17C2E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	// The rest of bunker is dot puzzles only.
	generator->resetConfig();
	generator->setFlag(Generate::Config::WriteDotColor);
	generator->generate(0x09F7D, Decoration::Dot, (Random::rand() % 9)+1);
	generator->generate(0x09FDC, Decoration::Dot, (Random::rand() % 9) + 1);
	generator->generate(0x09FF7, Decoration::Dot, (Random::rand() % 9) + 1);
	generator->generate(0x09F82, Decoration::Dot, (Random::rand() % 9) + 1);
	generator->generate(0x09FF8, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x09D9F, Decoration::Dot, (Random::rand() % 9) + 1);
	generator->generate(0x09DA1, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x09DA2, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x09DAF, Decoration::Dot, (Random::rand() % 20) + 1);
	generator->generate(0x0A010, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x0A01B, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x0A01F, Decoration::Dot, (Random::rand() % 16) + 1);
	generator->generate(0x17E63, Decoration::Dot, (Random::rand() % 9) + 1);
	generator->generate(0x17E67, Decoration::Dot, (Random::rand() % 9) + 1);
}

void PuzzleList::GenerateJungleP()
{
	generator->setLoadingData(L"Jungle", 6);
	generator->resetConfig();
	//TODO: Figure out how to overide jungle panels
	//Jungle Wall
	specialCase->generateSoundDotPuzzle(0x0026D, { 4, 4 }, { DOT_SMALL, DOT_LARGE }, true);
	specialCase->generateSoundDotPuzzle(0x0026E, { 4, 4 }, { DOT_SMALL, DOT_LARGE }, true);
	specialCase->generateSoundDotPuzzle(0x0026F, { 4, 4 }, { DOT_MEDIUM, DOT_MEDIUM, DOT_SMALL, DOT_MEDIUM, DOT_LARGE }, false);
	if (Random::rand() % 2) specialCase->generateSoundDotPuzzle(0x00C3F, { 4, 4 }, { DOT_SMALL, DOT_MEDIUM, DOT_SMALL, DOT_LARGE }, true);
	else specialCase->generateSoundDotPuzzle(0x00C3F, { 4, 4 }, { DOT_LARGE, DOT_MEDIUM, DOT_MEDIUM, DOT_SMALL, DOT_LARGE }, true);
	if (Random::rand() % 2) specialCase->generateSoundDotPuzzle(0x00C41, { 4, 4 }, { DOT_SMALL, DOT_SMALL, DOT_LARGE, DOT_MEDIUM, DOT_LARGE }, true);
	else specialCase->generateSoundDotPuzzle(0x00C41, { 4, 4 }, { DOT_MEDIUM, DOT_MEDIUM, DOT_SMALL, DOT_MEDIUM, DOT_LARGE }, true);
	if (Random::rand() % 2) specialCase->generateSoundDotPuzzle(0x014B2, { 4, 4 }, { DOT_SMALL, DOT_LARGE, DOT_SMALL, DOT_LARGE, DOT_MEDIUM }, true);
	else specialCase->generateSoundDotPuzzle(0x014B2, { 4, 4 }, { DOT_LARGE, DOT_MEDIUM, DOT_SMALL, DOT_LARGE, DOT_SMALL }, true);
}

void PuzzleList::GenerateSwampP()
{
	generator->setLoadingData(L"Swamp", 49);
	generator->resetConfig();
	//Swamp Tutorial Set
	GenerateRandomPuzzle(0x00469,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00472,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00262,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00474,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00553,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0056F,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00390,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x010CA,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00983,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00984,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00986,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00985,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00987,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x181A9,4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Red Panels
	GenerateRandomPuzzle(0x00982, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0097F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0098F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00990, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C0D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C0E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Discontinous Tutorial Panels
	GenerateRandomPuzzle(0x00999, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0099D, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x009A0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x009A1, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	
	//Rotation Tutorial Panels
	GenerateRandomPuzzle(0x00007, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00008, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00009, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0000A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Rotation Advanced Panels
	GenerateRandomPuzzle(0x003B2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00A1E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00C2E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00E3A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	
	//Purple Underwater
	GenerateRandomPuzzle(0x009A6, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Blue Underwater
	GenerateRandomPuzzle(0x009AB, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x009AD, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x009AE, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x009AF, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00006, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Teal Underwater
	GenerateRandomPuzzle(0x00002, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00004, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00005, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x013E6, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00596, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Red Underwater
	GenerateRandomPuzzle(0x00001, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x014D2, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x014D4, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x014D1, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Laser Shortcut
	GenerateRandomPuzzle(0x17C05, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C02, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateMountainP()
{
	std::wstring text = L"Mountain Perspective";
	SetWindowText(_handle, text.c_str());
	specialCase->generateMountaintop(0x17C34, { { Decoration::Stone | Decoration::Color::Black, 2 },{ Decoration::Stone | Decoration::Color::White, 2, }, });

	generator->setLoadingData(L"Mountain", 39);
	generator->resetConfig();

	//Purple Path
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
	GenerateRandomPuzzle(0x09E73, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E75, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E78, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E79, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E6C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E6F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E6B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Blue
	generator->resetConfig();
	generator->setObstructions({ { 4, 3 },{ 5, 4 },{ 5, 6 },{ 5, 8 },{ 5, 10 },{ 6, 9 },{ 7, 10 } });
	generator->generate(0x33AF5, Decoration::Stone | Decoration::Color::Black, 5, Decoration::Stone | Decoration::Color::White, 3);
	if (Random::rand() % 2 == 0) generator->setObstructions({ { 5, 4 },{ 5, 6 },{ 5, 8 },{ 5, 10 },{ 9, 4 },{ 9, 6 },{ 9, 8 },{ 9, 10 },{ 7, 0 },{ 7, 2 } });
	else generator->setObstructions({ { 3, 4 },{ 3, 6 },{ 3, 8 },{ 3, 10 },{ 7, 4 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 5, 0 },{ 5, 2 },{ 9, 0 },{ 9, 2 } });
	generator->generate(0x33AF7, Decoration::Stone | Decoration::Color::Black, 6, Decoration::Stone | Decoration::Color::White, 6);
	generator->setObstructions({ { 0, 1 },{ 0, 3 },{ 0, 5 },{ 0, 7 },{ 9, 4 },{ 1, 4 },{ 1, 6 },{ 1, 8 },{ 2, 7 },{ 2, 9 },{ 3, 8 },{ 3, 10 },{ 4, 9 },{ 5, 8 },{ 5, 10 },
		{ 6, 7 },{ 6, 9 },{ 7, 6 },{ 7, 8 },{ 7, 10 },{ 8, 5 },{ 8, 7 },{ 8, 9 },{ 9, 2 },{ 9, 4 },{ 9, 6 },{ 9, 8 },{ 10, 1 },{ 10, 3 },{ 10, 5 } });
	generator->generate(0x09F6E, Decoration::Dot, 5);

	//Purple
	GenerateRandomPuzzle(0x09EAD, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09EAF, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Green
	GenerateRandomPuzzle(0x09E7A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E71, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E72, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E69, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E7B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Rainbow
	GenerateRandomPuzzle(0x09FD3, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09FD4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09FD6, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09FD7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	generator->resetConfig();
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

	//Dual Bridges
	generator->resetConfig();
	generator->setFlag(Generate::Config::DecorationsOnly);
	generator->setFlag(Generate::Config::ShortPath);
	generator->setFlag(Generate::Config::DisableReset);
	generator->blockPos = { {1,9},{3,9},{5,9},{7,9},{9,9},{11,9},{1,7},{3,7},{5,7},{7,7},{9,7},{11,7} };
	generator->generate(0x09E86, Decoration::Star | Decoration::Color::Orange, 4, Decoration::Stone | Decoration::Color::Black, 1,
		Decoration::Stone | Decoration::Color::White, 1);
	generator->write(0x09ED8);

	//Metapuzzle
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

void PuzzleList::GenerateCavesP()
{
	generator->setLoadingData(L"Caves", 51);
	generator->resetConfig();
	//UTM Entrance Panels
	GenerateRandomPuzzle(0x17FA2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00FF8, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Blue Area
	// Symmetry
	GenerateRandomSymPuzzle(0x01A0D, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x018A0, 4, Decoration::Color::Black);

	//Left
	GenerateRandomPuzzle(0x008B8, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00973, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0097B, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0097D, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x0097E, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Discontinous
	GenerateRandomPuzzle(0x009A4, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
		
	//Cave-in
	GenerateRandomPuzzle(0x00A72, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Right Far
	GenerateRandomPuzzle(0x00994, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x334D5, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00995, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00996, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00998, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Right Near
	GenerateRandomPuzzle(0x00190, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00558, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x00567, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);
	GenerateRandomPuzzle(0x006FE, 4, Decoration::Color::White, Decoration::Color::Red, Decoration::Color::Purple);

	//Derivative Puzzle Area
	GenerateRandomPuzzle(0x32962, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x32966, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x01A31, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00B71, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Beam
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

	//Green Dots
	GenerateRandomPuzzle(0x0A16B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A2CE, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A2D7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A2DD, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0A2EA, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17FB9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Invis Dots
	GenerateRandomPuzzle(0x0008F, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0006B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0008B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0008C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0008A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x00089, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0006A, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0006C, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Invis Sym
	GenerateRandomSymPuzzle(0x00027, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00028, 4, Decoration::Color::Black);
	GenerateRandomSymPuzzle(0x00029, 4, Decoration::Color::Black);

	//Mountainside Shortcuts
	GenerateRandomPuzzle(0x021D7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17CF2, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Challenge Pillar
	generator->resetConfig();
	generator->generate(0x09DD5, Decoration::Triangle, 9);

	//Challenge Entrance
	GenerateRandomPuzzle(0x0A16E, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);

	//Town Area Shortcuts
	GenerateRandomPuzzle(0x039B4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x09E85, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateVaultsP()
{
	generator->setLoadingData(L"Vaults", 5);
	generator->resetConfig();
	GenerateRandomPuzzle(0x033D4, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x0CC7B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomSymPuzzle(0x002A6, 4, Decoration::Color::Black);
	generator->resetConfig();
	specialCase->generateSoundDotReflectionPuzzle(0x00AFB, { 6, 6 }, { DOT_MEDIUM, DOT_LARGE, DOT_MEDIUM, DOT_SMALL }, { DOT_LARGE, DOT_SMALL, DOT_MEDIUM }, 5, false);
	generator->resetConfig();
	specialCase->generateJungleVault(0x15ADD, false);
}

void PuzzleList::GenerateTrianglePanelsP()
{
	generator->setLoadingData(L"Triangles", 12);
	generator->resetConfig();
	GenerateRandomPuzzle(0x17CFB, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x3C12B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17CE7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17CF0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17FA0, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17FA9, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17F9B, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C71, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17D01, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17CF7, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17C42, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17F93, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17D28, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
	GenerateRandomPuzzle(0x17D27, 4, Decoration::Color::Black, Decoration::Color::White, Decoration::Color::Red);
}

void PuzzleList::GenerateShadowsP()
{
	generator->setLoadingData(L"Shadows", 1);
	generator->resetConfig();
	//TODO: Figure out how to override shadows panels.

}