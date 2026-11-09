#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "CellPosition.h"

// forward declarations (their includes are in the cpp)
class Input;

class Output	// The application manager & grid (phase 2) should have a pointer to this class
{
private:	

	window* pWind;	// Pointer to the Graphics Window
	
	// ========== Some Utility Functions (Private Functions) ==========

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	int GetCellStartX(const CellPosition & cellPos) const;	// Gets the X coordinate 
															// of the upper left corner of the passed cellpos

	///TODO: IMPLEMENT THE FOLLOWING FUNCTION
	int GetCellStartY(const CellPosition & cellPos) const;	// Gets the Y coordinate 
															// of the upper left corner of the passed cellpos

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void DrawCardCode(const CellPosition & cellPos, string cardCode) const;	// Draws the passed card "code"
																			// in the passed cellpos

	void ClearToolBar() const;	// Clears the toolbar by drawing a filled rectangle

public:

	Output();	// A Constructor for any needed initializations

	window* CreateWind(int, int, int , int) const; // Creates the application window

	Input* CreateInput() const;	// Creates a pointer to the Input object	

	// ========== User Interface Functions ==========
	
	void ClearStatusBar() const;	// Clears the status bar by drawing a filled rectangle
	void ClearGridArea() const;	    // Draws an empty grid (horizontal and vertical lines with empty cells)

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void CreateDesignModeToolBar() const;	// Creates the Design mode toolbar with all its menu icons

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void CreatePlayModeToolBar() const;		// Creates the Play mode toolbar with all its menu icons
	
	void PrintMessage(string msg) const;	// Prints a message on Status bar

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION
	void PrintPlayersInfo(string info);		// Prints players' info on the right-side of the toolbar

	// ========== Game Drawing Functions ==========

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION	
	void DrawCell(const CellPosition & cellpos, string cardCode="", bool highlighted=false) const;	
														// Draws Cell Rectangle with Cell Number 
														// and Card Code (if any), cardNum="" means no Card
														// if highlighted, the cell border line changes
	

	///TODO: COMPLETE THE IMPLEMENTATIN OF THE FOLLOWING FUNCTION	
	void DrawPlayer(const CellPosition & cellPos, int playerNum, color playerColor) const;  
	                                                // Draws "Player Circle" filled with the passed color
													// "playerNum" parameter is used for locating the circle
													// ** Players' Circles Locations depending on "playerNum" is as follows: **
													//    Player_0   player_pos1
													//    Player_2   Player_3
	
	
	~Output();	// A Destructor for any needed deallocations
};

#endif