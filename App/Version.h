#pragma once

#define TO_STRING2(s) L#s
#define TO_STRING(s) TO_STRING2(s)

#define MAJOR 1
#define MINOR 1
#define PATCH 7
#define BUILD 14

#define VERSION_STR     TO_STRING(MAJOR) L"." TO_STRING(MINOR) L"." TO_STRING(PATCH) L"." TO_STRING(BUILD)
#define VERSION			MAJOR, MINOR, PATCH

#define PRODUCT_NAME L"Witness Random Puzzle Generator"
#define WINDOW_CLASS L"WitnessRandomizer"
