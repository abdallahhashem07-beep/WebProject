#include "Input.h"
#include "Output.h"

//This is a test code to test the Input and Output classes

int main()
{
	int x,y;

	//Create Input and Output objects to test
	Output * pOut = new Output();
	Input * pIn = pOut->CreateInput();

	//Starting the test
	pOut->PrintMessage("This demo is to test classes of phase 1, Click anywhere to start the test");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 1:	
	//			Create The FULL Tool bar of Design Mode, the grid area and the status bar	
	//			This has already been done through the constrcutor of class Output
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST1: Drawing Tool bar, Grid and Status bar, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///////////////////////////////////////////////////////////////////////////////////
	// TEST 2:	
	//			Testing the Output Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST2: Testing the [ Output ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 2.1- Drawing Cells with Cards Test ///
	/// ===================================
	pOut->PrintMessage("2.1- Drawing (Cells with CARDS) + Highlighted Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition card_ldr (0, 0);  // assume card code is : LDR (normal card), cellNum 89
	CellPosition card_cel (0, 10); // assume card code is : CEL (normal card), cellNum 99	
	CellPosition card_dic (8, 0);  // assume card code is : DIC (normal card), cellNum 1
	CellPosition card_kng (8, 10); // assume card code is : KNG (chess card),  cellNum 11
	CellPosition card_nyt (4, 5); // assume card code is : NYT  (chess card),  cellNum 50


	///TODO: Call Function DrawCell of Class Ouput Multiple Times
	///       to draw cells in the cell positions declared above
	///       with their respective card codes:LDR, etc.
	

	pOut->PrintMessage("Highlighting cell number 1 and 99,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	
	///TODO: Call Function DrawCell of Class Ouput Multiple Times
	///       to highlight cell number 1 and 99: card_dic and card_cel


	pOut->PrintMessage("FINISHED - Drawing (Cells with CARDS) + Highlighted Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	/// 2.2- Drawing Players Test ///
	/// ==============================
	pOut->PrintMessage("2.2- Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition player_pos1 (8, 0);  // cellNum 1
	CellPosition player_pos2 (2, 18); // Tests the validation
	CellPosition player_pos3 (2, 5);  // cellNum 72


	///TODO: Call Function DrawPlayer of Class Ouput Multiple Times
	///       to draw the following players:
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) in cell position (player_pos1 declared above) 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) in cell position (player_pos1 declared above) 
	///       playerNum (2) with color (PlayerColors[2] defined in UI object) in cell position (player_pos1 declared above) 
	///       playerNum (3) with color (PlayerColors[3] defined in UI object) in cell position (player_pos1 declared above) 
	///       playerNum (0) with color (PlayerColors[0] defined in UI object) in cell position (player_pos2 declared above) 
	///       playerNum (1) with color (PlayerColors[1] defined in UI object) in cell position (player_pos3 declared above) 
	///       playerNum (5) with color (PlayerColors[1] defined in UI object) in cell position (player_pos3 declared above) 
	///       playerNum (-1) with color (PlayerColors[1] defined in UI object) in cell position (player_pos3 declared above) 
	///       Note that some of the above player positions and player numbers are (INVALID) --> for testing the validation conditions


	pOut->PrintMessage("FINISHED - Drawing (Players) Test,  Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 3: 
	//			Input Class - Part 1
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST3: Now Time to test class [ Input ], Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.1- Getting Integer ///
	/// ===========================
	pOut->PrintMessage("3.1- (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call GetInteger Function and receive its returned integer
	// 2- Print it in the status bar in this format:   You Entered: 116
	//    (assuming the entered number is 116)
	// 3- Call GetPointClicked() function



	pOut->PrintMessage("FINISHED - (GetInteger) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// 3.2- Getting Cell Clicked ///
	/// =========================
	pOut->PrintMessage("3.2- (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Call function GetCellClicked
	// 2- Print on the status bar the vCell and hCell of the clicked cell
	// 3- Repeat Step 1 and 2 five times



	pOut->PrintMessage("FINISHED - (GetCellClicked) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	/// 3.3- Reading a String ///
	/// =====================
	pOut->PrintMessage("3.3- (GetString) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click


	///TODO: Add code here to 
	// 1- Read a string from the user on the status bar
	// 2- After reading the string clear the status bar
	// 3- print on the status bar "You Entered: " then print the string
	// NOTE: GetString() is already implemented. It is just required from you to call it



	pOut->PrintMessage("FINISHED - (GetString) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 4:	
	//			Test the functions of CellPosition Class
	///////////////////////////////////////////////////////////////////////////////////

	pOut->PrintMessage("TEST4: Testing the [ CellPosition ] class, Click anywhere to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.1- (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	CellPosition cellpos_1(0, 0);

	///TODO:
	// 1- Ask user to enter an integer and read it using GetInteger()
	// 2- Call SetVCell() of cellpos_1 with that integer
	// 3- Print GetVCell() of cellpos_1 as follows: "Now the vCell = 5" (assuming the entered integer is 5)
	// 4- Call GetPointClicked()
	// 5- Repeat the above steps FIVE TIMES
	// 6- Repeat all the above steps to test SetHCell() function instead with the needed modifications

	pOut->PrintMessage("FINISHED - (Setters with Validation) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.2- (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user two integers representing vCell and hCell
	// 2- Creates a CellPosition object of them
	// 3- Use the function GetCellNum() to get the corresponding Cell Number (it used function : GetCellNumFromPosition() inside it)
	// 4- Print the Cell Number on the status bar
	// 5- Repeat the above steps Five TIMES

	pOut->PrintMessage("FINISHED - (GetCellNumFromPosition) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	pOut->PrintMessage("4.3- (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	/// TODO:
	// 1- Read from user one integer representing cellNum
	// 2- Creates a CellPosition object of that integer using that constructor: CellPosition (int cellNum);
	//   --> it uses the function : GetCellPositionFromNum () inside it
	// 4- Print the Cell vCell and hCell on the status bar
	// 5- Repeat the above steps Five TIMES

	pOut->PrintMessage("FINISHED - (GetCellPositionFromNum) Test, Click to continue");
	pIn->GetPointClicked(x,y);	//Wait for any click

	///////////////////////////////////////////////////////////////////////////////////
	// TEST 5: 
	//			Input Class - Part2: Check for the user action
	///////////////////////////////////////////////////////////////////////////////////
	pOut->PrintMessage("TEST5: Testing Input ability to detect User Action, click anywhere");

	ActionType ActType;

	///TODO:  
	//You must add a case for EACH action (both Create-Grid mode and Game mode actions)
	//Add cases for the missing actions below
	do
	{
		ActType = pIn->GetUserAction();

		switch (ActType)
		{
		case ADD_CARD:
			pOut->PrintMessage("Action: ADD_CARD , Click anywhere");
			break;

		case EXIT:				
			break;

		case TO_PLAY_MODE:

			///TODO:  Call Function (PrintPlayersInfo) of Class Output with a string similar to 
			//        the one given in the screenshot of project document

			pOut->PrintMessage("Action: TO_PLAY_MODE , Click anywhere");
			pOut->CreatePlayModeToolBar();
			break;


			///TODO:  ADD Cases similarly for ALL the remaining actions of DESIGN Mode


		case ROLL_DICE:
			pOut->PrintMessage("Action: ROLL_DICE , Click anywhere");
			break;

		case TO_DESIGN_MODE:
			pOut->PrintMessage("Action: TO_DESIGN_MODE , Click anywhere");
			pOut->CreateDesignModeToolBar();
			break;


			///TODO:  ADD Cases similarly for ALL the remaining actions of PLAY Mode

		}
	}while(ActType != EXIT);


	/// Exiting
	pOut->PrintMessage("Action: EXIT, test is finished, click anywhere to exit");
	pIn->GetPointClicked(x,y);


	delete pIn;
	delete pOut;	
	return 0;
}


