#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 11
#define NumVerticalCells 9
#define MaxPlayerCount 4

enum GUI_MODE		// Graphical user interface mode
{
	MODE_DESIGN,	// Design mode (startup mode)
	MODE_PLAY       // Play mode
};

enum DESIGN_MODE_ITEMS // The items of the Design Mode (you should add more items)
{
	// Note: Items MUST be ORDERED here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ADD_CARD,

	///TODO: Add more items names here

	ITM_EXIT,
	ITM_SWITCH_TO_PLAY_MODE,
	
	DESIGN_ITM_COUNT	// no. of items ==> This should be the last line in this enum
};

enum PLAY_MODE_ITEMS // The items of the Play Mode (you should add more items)
{
	// Note: Items are ORDERED here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ROLL_DICE,

	///TODO: Add more items names here

	ITM_SWITCH_TO_DESIGN_MODE,

	PLAY_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};


__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,			// Window width and height
		wx , wy,				// Window starting coordinates
		StatusBarHeight,		// Status Bar Height
		ToolBarHeight,			// Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;			// Width of each item in toolbar menu
	
	int CellHeight;				// Height of 1 CELL
	int CellWidth;				// Width of 1 CELL
	
	color MsgColor;				// Messages color (usually used in statusbar)
	color PlayerInfoColor;		// Players' Info color (used in the toolbar - right-indented)

	color CellColor_NoCard;		// Cell color if it does not have card
	color CellColor_HasNormCard;	// Cell color if it has a normal card
	color CellColor_HasChessCard;	// Cell color if it has a chess card

	color ToolBarColor;			// Toolbar color (toolbar background)
	color StatusBarColor;		// Statusbar color (statusbar background)

	color GridLineColor;		// Color of the Lines separating adjacent cells is not highlighted
	color GridHighlightColor;   // Color of the Lines separating adjacent cells if the cell is highlighted

	int CellNumFont;			// Font size of cell numbers
	color CellNumColor;			// Cell number color

	int CardCodeFont;			// Font size of card codes
	color CardCodeColor;		// Card code color

	color PlayerColors[MaxPlayerCount];		// Color of each player

	///TODO: Add more members if needed

} UI ;	// create a global object UI

#endif