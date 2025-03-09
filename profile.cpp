//---------------------------------------------------------------------------
// File: profile.cpp
// Purpose: Implementation file for the car profile form in a car management application
// Contains the definitions of TcarProfile class methods for displaying car details
//---------------------------------------------------------------------------

#include <vcl.h>            // - VCL library for core functionality
#pragma hdrstop

#include "profile.h"        // - Header for TcarProfile class
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"    // - Links the form's design file

TcarProfile *carProfile;

//---------------------------------------------------------------------------
// Constructor for TcarProfile, initializes the form
__fastcall TcarProfile::TcarProfile(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------
// Sets car details in the form for display
void TcarProfile::setCarDetails(AnsiString model, double carPrice, int unitsSold, double salesCost, double commissionPercentage,double profit)
{
    mdlName->Caption = model;                   // - Display car model in label
    tedtCarPrice->Text = "R" + AnsiString(carPrice);         // - Display price with currency prefix
    tedtUnitsSold->Text = AnsiString(unitsSold);               // - Display units sold
    tedtSalesCost->Text = "R" + AnsiString(salesCost); // - Display cost with currency prefix
    tedtCommission->Text = AnsiString(commissionPercentage);   // - Display commission percentage
    tedtProfit->Text = "R" + AnsiString(profit);         // - Display profit with currency prefix


}

//---------------------------------------------------------------------------
// Event handler for OK button click
void __fastcall TcarProfile::okBtnClick(TObject *Sender)
{
    Close();                // - Closes the car profile form
}
//---------------------------------------------------------------------------
