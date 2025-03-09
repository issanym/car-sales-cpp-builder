//---------------------------------------------------------------------------
// File: mainformH.h
// Purpose: Header file for the main form of a car management application
// Contains the declaration of the main screen form and its components
//---------------------------------------------------------------------------
#ifndef mainformH
#define mainformH
//---------------------------------------------------------------------------
// Include necessary system and VCL headers
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include "car.h"            // Custom Car class
#include <Vcl.ExtCtrls.hpp>
#include <vector>           // STL vector container
#include <profile.h>        // Car profile form
#include "add.h"            // Add car form
#include "splash.h"         // Splash screen form
//---------------------------------------------------------------------------

// Main application form class
class TmainScreen : public TForm
{
__published:	// IDE-managed Components (accessible in Form Designer)
	TListBox *carsLstbx;    // - Displays list of cars
	TButton *addBtn;        // - Button to add a new car
	TOpenDialog *OpenDialog; // - Dialog for opening files
	TButton *searchBtn;     // - Button to search cars
	TButton *exitBtn;       // - Button to exit application
	TButton *highestBtn;    // - Shows highest value car
	TTimer *splashTmr;      // - Timer for splash screen duration
	TTimer *tmr;            // - Timer for periodic refreshes

	// Event handlers
	void __fastcall addBtnClick(TObject *Sender);     // Handles add button click
	void __fastcall searchBtnClick(TObject *Sender);  // Handles search button click
	void __fastcall carsLstbxClick(TObject *Sender);  // Handles car list selection
	void __fastcall FormCreate(TObject *Sender);      // Handles form creation/initialization
	void __fastcall exitBtnClick(TObject *Sender);    // Handles exit button click
	void __fastcall highestBtnClick(TObject *Sender); // Handles highest value button click
	void __fastcall splashTmrTimer(TObject *Sender);  // Handles splash screen timer event
	void __fastcall tmrTimer(TObject *Sender);        // Handles refresh timer event

private:	// User declarations

public:		// User declarations - publicly accessible members
	// Constructor
	__fastcall TmainScreen(TComponent* Owner);

	// Public member variables
    TsplashScreen *splash;  // - Pointer to splash screen
    std::vector<Car> cars;  // - Collection of Car objects

    // Public member functions
    // Loads car data from a file into the car collection
    void LoadCarsData();
};

//---------------------------------------------------------------------------
extern PACKAGE TmainScreen *mainScreen;
//---------------------------------------------------------------------------
#endif
