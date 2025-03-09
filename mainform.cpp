//---------------------------------------------------------------------------
// File: mainform.cpp
// Purpose: Implementation of the main form for a car management application
// Contains the implementation of the TmainScreen class methods
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "mainform.h"
#include "car.h"
#include <vector>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmainScreen *mainScreen;  // - Global instance of main screen

//---------------------------------------------------------------------------

// Constructor for the main screen form

__fastcall TmainScreen::TmainScreen(TComponent* Owner)
	: TForm(Owner)
{
    // Constructor is empty, initialization happens in FormCreate
}

// Loads car data from a CSV file into the cars vector and populates the listbox

void TmainScreen::LoadCarsData()
{
    // Clear existing data
    carsLstbx->Items->Clear();
    cars.clear();

    // Create a string list to load the CSV file
    TStringList *dataList = new TStringList(this);

    // Load CSV file from resources directory
    dataList->LoadFromFile("..\\..\\resources\\cars.csv");

    int listSize = dataList->Count;

    // Add header rows to the list box
    carsLstbx->Items->Add("Car Model   \t  Profit");
    carsLstbx->Items->Add("=========\t=========");

    // Variables to store parsed data
    AnsiString line, model;
    int itmSold;
    double price, sale, commission;

    // Process each line of data (skipping header row with i=1)
    for(int i=1; i<listSize; i++)
    {
        // Get the current line from the data list
        line = dataList->Strings[i];

        // Extract car model (substring before first comma)
        model = line.SubString(1, line.Pos(",")-1);
        line = line.Delete(1,line.Pos(","));

        // Extract price (substring before next comma)
        price = line.SubString(1, line.Pos(",")-1).Trim().ToDouble();
        line = line.Delete(1,line.Pos(","));

        // Extract items sold
        itmSold = line.SubString(1, line.Pos(",")-1).Trim().ToInt();
        line = line.Delete(1,line.Pos(","));

        // Extract cost per sale
        sale = line.SubString(1, line.Pos(",")-1).Trim().ToDouble();
        line = line.Delete(1,line.Pos(","));

        // Extract commission (remaining part of the line)
        commission = line.ToDouble();

        // Create a Car object with the parsed data and add to vector
        Car temp(model, price, itmSold, sale, commission);
        cars.push_back(temp);

        // Add car details to list box
        carsLstbx->Items->Add(cars[i-1].getCarModel() + "\t" + "R" + cars[i-1].getProfit());
    }
}

//---------------------------------------------------------------------------
/**
 * Event handler for form creation
 * Initializes the form, shows splash screen, and loads car data
 */
void __fastcall TmainScreen::FormCreate(TObject *Sender)
{
    // Create and show splash screen
    splash = new TsplashScreen(this);
    splash->Parent = this;
    splash->Visible = true;
    splash->Show();


    // Load car data from file
    LoadCarsData();
}

//---------------------------------------------------------------------------
/**
 * Event handler for Add button click
 * Shows the add car screen
 */
void __fastcall TmainScreen::addBtnClick(TObject *Sender)
{
    // load add form
    addScreen->Show();
}

//---------------------------------------------------------------------------
/**
 * Event handler for Search button click
 * Searches for a car by model name and displays its details
 */
void __fastcall TmainScreen::searchBtnClick(TObject *Sender)
{
    // Prompt user for car model to search
    AnsiString model = InputBox("Search car", "Enter car model that you want to see the details:", "");
    bool isFound = false;
    int ind;

    // Search for the car in the collection
    for(int i=0; i<cars.size(); i++)
    {
        if(model.LowerCase() == cars[i].getCarModel().LowerCase())
        {
            isFound = true;
            ind = i;
        }
    }

    // Display car details if found
    if(isFound)
    {
        carProfile->setCarDetails(cars[ind].getCarModel(), cars[ind].getCarPrice(),
                                 cars[ind].getUnitsSold(), cars[ind].getSalesCost(),
                                 cars[ind].getCommissionPercentage(), cars[ind].getProfit());
        carProfile->Show();
    }
    else
        ShowMessage("Car Not found!");
}

//---------------------------------------------------------------------------
/**
 * Event handler for car list box item click
 * Displays details for the selected car
 */
void __fastcall TmainScreen::carsLstbxClick(TObject *Sender)
{
    // Calculate index in cars vector (accounting for header rows)
    int ind = carsLstbx->ItemIndex-2;

    // Handle special cases for header rows
    if(ind == -2)
    {
        ind = 0;
    }
    else if(ind == -1)
        ind = 1;

    // Show car details if a car (not header) is selected
    if(!(carsLstbx->ItemIndex == 0 || carsLstbx->ItemIndex == 1))
    {
        carProfile->setCarDetails(cars[ind].getCarModel(), cars[ind].getCarPrice(),
                                cars[ind].getUnitsSold(), cars[ind].getSalesCost(),
                                cars[ind].getCommissionPercentage(), cars[ind].getProfit());
        carProfile->Show();
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
/**
 * Event handler for Exit button click
 * Asks for confirmation before closing the application
 */
void __fastcall TmainScreen::exitBtnClick(TObject *Sender)
{
    // Show confirmation dialog before exiting
    if(Application->MessageBox(L"Are you sure you want to exit?", L"Exit", MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        Close();
    }
}

//---------------------------------------------------------------------------
/**
 * Event handler for Highest button click
 * Finds and displays the car with the highest profit
 */
void __fastcall TmainScreen::highestBtnClick(TObject *Sender)
{
    // Initialize variables to track highest profit
    int highest = cars[0].getProfit();
    int ind = 0;

    // Find car with highest profit
    for(int i=0; i<cars.size(); i++)
    {
        if(cars[i].getProfit() > highest)
        {
            highest = cars[i].getProfit();
            ind = i;
        }
    }

    // Display details of car with highest profit
    carProfile->setCarDetails(cars[ind].getCarModel(), cars[ind].getCarPrice(),
                            cars[ind].getUnitsSold(), cars[ind].getSalesCost(),
                            cars[ind].getCommissionPercentage(), cars[ind].getProfit());
    carProfile->Show();
}

//---------------------------------------------------------------------------
/**
 * Event handler for splash screen timer
 * Disables timer and removes splash screen when time elapses
 */
void __fastcall TmainScreen::splashTmrTimer(TObject *Sender)
{
    splashTmr->Enabled = false;

    // Clean up splash screen if it exists
    if(splash)
    {
        delete splash;
        splash = nullptr;
    }
}

//---------------------------------------------------------------------------
/**
 * Event handler for instruction timer
 * Shows a help message when timer elapses
 */
void __fastcall TmainScreen::tmrTimer(TObject *Sender)
{
    tmr->Enabled = false;
    ShowMessage("Click on any item in the list to expand it");
}
//---------------------------------------------------------------------------
