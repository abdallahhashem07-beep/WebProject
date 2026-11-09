#include "Output.h"

#include "Input.h"

////////////////////////////////////////////////////////////////////////////////////////// 

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_DESIGN;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 55;

	UI.width = 1210; // make it divisible by NumHorizontalCells
	UI.height = 610; 
	UI.wx = 5;
	UI.wy = 5;

	UI.CellWidth = UI.width / NumHorizontalCells;
	UI.CellHeight = (UI.height -  UI.ToolBarHeight - UI.StatusBarHeight) / NumVerticalCells;

	// Pen Colors of messages of status bar and players' info
	UI.MsgColor = DARKRED;
	UI.PlayerInfoColor = DARKSLATEBLUE;

	// Background Colors of toolbar and statusbar 
	UI.ToolBarColor = WHITE;
	UI.StatusBarColor = LIGHTGRAY; 

	// Line Colors of the borders of each cell
	UI.GridLineColor = WHITE;
	UI.GridHighlightColor = DARKRED;

	// Cell Color if Empty & Cell Number Font & Color
	UI.CellColor_NoCard = LIGHTSLATEBLUE;
	UI.CellNumFont = 13;
	UI.CellNumColor = UI.GridLineColor;

	// Cell Color if Has Normal or Chess Card & CARD Code Font & Color
	UI.CellColor_HasNormCard = SALMON;
	UI.CellColor_HasChessCard = MEDIUMSEAGREEN;
	UI.CardCodeFont = 30;
	UI.CardCodeColor = WHITE;

	// Colors of the 4 Players
	UI.PlayerColors[0] = GOLD;
	UI.PlayerColors[1] = DARKBLUE;
	UI.PlayerColors[2] = WHITE;
	UI.PlayerColors[3] = DARKRED;

	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy); 

	// Change the title
	pWind->ChangeTitle("Chess Snakes & Ladders");

	// Create the toolbar, grid area and status bar
	CreateDesignModeToolBar();
	ClearGridArea();
	ClearStatusBar();

}

////////////////////////////////////////////////////////////////////////////////////////// 

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	// The Window Object is created inside the Ouput class
	window* pW = new window(w, h, x, y);
	return pW;
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input* Output::CreateInput() const
{
	// The Input Object is created inside the Output class
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Some Utility Functions										//
//======================================================================================//

int Output::GetCellStartX(const CellPosition & cellPos) const
{
	///TODO: implement the following function as described in Output.h file
	
	// Hint: use HCell of the passed cellPos and UI.CellWidth

	return 0; // this line should be changed with your implementation
}

//////////////////////////////////////////////////////////////////////////////////////////

int Output::GetCellStartY(const CellPosition & cellPos) const
{
	///TODO: implement the following function as described in Output.h file

	// Hint: use VCell of the passed cellPos, UI.CellHeight, and UI.ToolBarHeight

	return 0; // this line should be changed with your implementation
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawCardCode(const CellPosition & cellPos, string cardCode) const
{
	// Get the X and Y of the upper left corner of the cell
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);
	
	// Calculate where to write the cardCode
	int x = cellStartX + 0.5 * UI.CellWidth;    
	int y = cellStartY + 0.15 * UI.CellHeight;

	// Set pen and font before drawing the string on the window
	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CardCodeFont, BOLD , BY_NAME, "Comic Sans MS");  
	
	///TODO: Draw the string of cardCode in the location (x,y) - one line of code
	


}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	// Clear by drawing a rectangle filled with toolbar background color
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->SetBrush(UI.ToolBarColor);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

void Output::ClearStatusBar() const
{
	// Clear drawing a rectangle filled with statusbar background color
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearGridArea() const
{
	// Draw each cell in the Grid: ( NumVerticalCells * NumberHorizontalCells )
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++) 
		{
			CellPosition cellPos(i, j);
			DrawCell(cellPos); // Initially NO Cards in the cell
		}
	}

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateDesignModeToolBar() const
{
	UI.InterfaceMode = MODE_DESIGN;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First, prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// REORDEER them in UI_Info.h ==> enum DESIGN_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[DESIGN_ITM_COUNT];
	MenuItemImages[ITM_ADD_CARD] = "images\\Menu_Card.jpg";	
	MenuItemImages[ITM_EXIT] = "images\\Menu_Exit.jpg";
	MenuItemImages[ITM_SWITCH_TO_PLAY_MODE] = "images\\Menu_SwitchToGame.jpg";

	///TODO: Prepare images for each menu item and add it to the list



	// Draw menu item one image at a time
	for(int i=0; i < DESIGN_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);


}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreatePlayModeToolBar() const
{
	UI.InterfaceMode = MODE_PLAY;

	ClearToolBar(); // in order not to draw above the icons of the other mode when you switch

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way

	// First, prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// REORDER them in UI_Info.h ==> enum PLAY_MODE_ITEMS
	// ** MAKE SURE THAT THE IMAGES ARE .JPG FILES **
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_ROLL_DICE] = "images\\Menu_Dice.jpg";
	MenuItemImages[ITM_SWITCH_TO_DESIGN_MODE] = "images\\Menu_SwitchToGrid.jpg";

	///TODO: Prepare images for each menu item and add it to the list



	// Draw menu item one image at a time
	for(int i=0; i < PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	// First clear the status bar from any previous writing

	// Set pen and font before drawing the string on the window
	pWind->SetPen(UI.MsgColor);
	pWind->SetFont(18, BOLD , BY_NAME, "Verdana");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.3), msg);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintPlayersInfo(string info)
{
	///TODO: Clear what was written on the toolbar

	// Hint: call the output function that clears the play mode toolbar

	// Set the pen and font before drawing the string on the window
	pWind->SetPen(UI.PlayerInfoColor); 
	pWind->SetFont(20, BOLD , BY_NAME, "Verdana");   

	int w=0, h=0;

	///TODO: Calculate the Width and Height of the string if drawn using the current font 
	
	// Hint: (Use GetStringSize() window function on variable: info) 
	//        to set the "w" and "h" variables with its width and height
	

	// Set the start X & Y coordinate of drawing the string
	int x = UI.width - w - 20; // space 20 before the right-side of the window
	                           // ( - w ) because x is the coordinate of the start point of the string (upper left)
	int y = (UI.ToolBarHeight - h) / 2; // in the Middle of the toolbar height


	///TODO: Draw the string "info" in the specified location (x, y)



}

//======================================================================================//
//			         			Game Drawing Functions   								//
//======================================================================================//

void Output::DrawCell(const CellPosition & cellPos, string cardCode, bool highlighted) const
{
	// Get the Cell Number (from 1 to NumVerticalCells*NumHorizontalCells) and the X & Y of its upper left corner
	int cellNum = cellPos.GetCellNum();
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// ----- 1- Draw the cell itself (background) --> Filled Rectangle -----

	// 1.1. SetPen() sets the cell border based on highlighted or not

	if (!highlighted)
		pWind->SetPen(UI.GridLineColor, 1);
	else
		pWind->SetPen(UI.GridHighlightColor, 1);
		

	// 1.2. SetBrush() sets the cell background based on card existance and type

	if (cardCode == "") // no card
		pWind->SetBrush(UI.CellColor_NoCard);

	///TODO: in the next line, or || the other chess card codes: "QUN", etc.
	else if (cardCode == "KNG") 
		; ///TODO: set brush with UI.CellColor_HasChessCard

	else // means if a normal card
		; ///TODO: set brush with UI.CellColor_HasNormCard


	///TODO: Draw the Cell Rectangle using the appropriate coordinates
	
	// Hint: Calculate the coordinates using: cellStartX, cellStartY, UI.CellWidth, UI.CellHeight
	


	// ----- 2- Draw the CELL number (the small number at the bottom right of the cell) -----

	pWind->SetPen(UI.CellNumColor);
	pWind->SetFont(UI.CellNumFont, BOLD , BY_NAME, "Verdana");   

	int w=0, h=0;

	///TODO: Get the Width and Height of the Cell Number if written using the current font 
	
	// Hint: (Use GetIntegerSize() window function on variable: cellNum) 
	//        to set the "w" and "h" variables with its width and height



	// Calculate X & Y coordinate of the start point of writing the card number (upper left point of the cell num)
	int x = cellStartX + (UI.CellWidth - w - 1);   // space 1 from the end of the cell width
												   // ( - w ) because x is for the start point of cell num (num's left corner)
	int y = cellStartY + (UI.CellHeight - h - 1);  // space 1 from the end of the cell height
												   // ( - w ) because y is for the start point of cell num (num's upper corner)
	
	///TODO: Draw the Integer cellNum in the x and y location

	

	// ----- 3- Draw card code (if any) -----

	if (cardCode != "") // Note: cardCode == "" means no card
		DrawCardCode(cellPos, cardCode);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::DrawPlayer(const CellPosition & cellPos, int playerNum, color playerColor) const
{

	///TODO: Validate the playerNum, if not valid, return; out of the function

	// Hint: use the MaxPlayerCount and check the correct range of playerNum


	// Get the X & Y coordinates of the start point of the cell (its upper left corner)
	int cellStartX = GetCellStartX(cellPos);
	int cellStartY = GetCellStartY(cellPos);

	// Calculate the Radius of the Player's Circle
	int radius = UI.CellWidth / 12; // proportional to cell width

	// Calculate the horizontal space before drawing players circles (space from the left border of the cell)
	int ySpace = UI.CellHeight / 8; // proportional to cell height


	// Note: Players' Circles Locations depending on "playerNum" is as follows:
	// Player_0   player_pos1
	// Player_2   Player_3

	// Calculate the Y coordinate of the center of the player's circle (based on playerNum)
	int y = cellStartY + ySpace + radius + 2;
	if (playerNum == 2 || playerNum == 3)
		y += 2 * radius + 2; // because playerNum 2 and 3 are drawn in the second row of circles

	// Calculate the Y coordinate of the center of the player's circle (based on playerNum)
	int x = cellStartX + radius + 10;  													
	if (playerNum == 1 || playerNum == 3)
		x += 2 * radius + 4; // because playerNum 1 and 3 are drawn in the second column of circles


	///TODO: Draw the player Circle of "radius" in center point (x,y) 
	//       and filled with: playerColor

	// Hint: first set the pen and brush with playerColor before draw the circle (3 lines of code)



	
}

//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	// deallocating the window object
	delete pWind;
}

