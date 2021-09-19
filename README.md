# Witness Random Puzzle Generator (Dawgup's Version)

### [Click Here to Download Dawgup's Randomizer (ver 1.1.7.10)](https://github.com/KemSpeedruns/witness-randomizer/releases)

The Witness Random Puzzle Generator takes most of the puzzles in Jonathan Blow's "The Witness" and makes them into new, randomly generated puzzles. The mod requires the game in order to function. No game files will be altered, as the randomizer works enterly in RAM. This mod uses WinAPI, so it is only compatible with Microsoft Windows.

This project uses the code from sigma's puzzle randomizer at https://github.com/sigma144/witness-randomizer for a slightly different purpose than he orginially intended. Credit to sigma for doing the work to make generating puzzles in-game possible. His mod is very fun and I would highly recommend it.

This mod has three different versions currently. 
The first is Base Game Randomizer. In this mode, every panel (except for the ones I can't touch yet) have a symbol count that matches the count in the base game. The size of the panel is also the same.
The second is Emptiness. In this mode, every panel (except for the ones I can't touch yet) either have no symbols, or have symbols that mean nothing (for an example of this, look at tutorial pillar and try some incorrect solutions).
The third is Puzzle Pack. When completed, it will generate completely random puzzles.

**How to use the Witness Random Puzzle Generator:**

1. Launch The Witness
2. Start a New Game
3. Launch WitnessRPG.exe (from any location)
4. Choose difficulty and seed (leave seed blank for random)
5. Click "Randomize" and wait for the process to complete
6. Enjoy your randomly created puzzles! Puzzles will revert to normal after closing the game.

**Current Release Activation Triggers**

Base Game Randomizer:
1. Tutorial Patio Floor opens Tutorial Vault
2. Tutorial Vault opens Tutorial Optional Door 2
3. Tutorial Discard opens Tutroail Optional Door 1
4. Town Crate Discard activates Shadows Laser
5. Stones Tutorial opens Town Church Star Door
6. Town Church Star Door opens the Town lattice-side door
7. Keep Discard opens Monastary Shortcut
8. Town Rooftop Discard activates Monastary Laser
9. Jungle Discard lifts the Jungle Pop-up Wall
10. Dots Tutorial opens Bunker Entry Door
11. Bunker Entry Door actiavates the Bunker Laser
12. Town Red Hexagonal Panel is on
13. Monastary Laser is on
14. Jungle Pop-up Wall activation is on
15. Town Lattice target is cleared
16. Keep Front Laser target is cleared.

Emptiness:
1. Tutorial Dot Tutorial power is on for the whole set.
2. Tutorial Dot Tutorial 1 activates the Town Red Hexagonal Panel-side door.
3. Tutorial Dot Tutorial 2 activates the Jungle Laser. 
5. Tutorial Dot Tutorial 3 activates the Shadows Laser.
7. Tutorial Dot Tutorial 4 activates the Monastary Laser.
8. Tutorial Dot Tutorial 5 activates the Desert Laser (note: will look very odd).

Puzzle Pack:
1. See Base Game, not that this area needs targets yet anyways.

**To resume where you left off after closing and relaunching the game:**

1. Load the save you were previously playing on, if it is not already loaded
2. Launch WitnessRPG.exe (from any location)
3. Click "Randomize" and wait for the process to complete. You don't have to enter the seed or difficulty again. This is because the seed and difficulty were stored in your save file when you randomized initially, so they will be automatically restored and used.

Please report any issues (such as unsolvable/broken puzzles) on the issues page. However, please read the **"Known Issues"** section in the wiki first, as your issue may be addressed there.

Thanks for playing this mod, and good luck!

**Credits:**
Sigma for the base of the randomizer
Dawgup for most of the panels
Mr_ParK3r2 for most of treehouse
IHNN for being good at solving and making testing easier.
