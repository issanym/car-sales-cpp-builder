//---------------------------------------------------------------------------
// File: add.cpp
// Purpose: Implementation file for the add screen form in a car management application
// Contains the definitions of TaddScreen class methods for adding new car data
//---------------------------------------------------------------------------

#include <vcl.h>            // - VCL library for core functionality
#pragma hdrstop

#include "add.h"            // - Header for TaddScreen class
#include "mainform.h"       // - Header for TmainScreen class
#include <cctype>           // - Standard library for character handling (isdigit)
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"    // - Links the form's design file

TaddScreen *addScreen;      // - Global pointer to add screen instance

//---------------------------------------------------------------------------
// Constructor for TaddScreen, initializes the form
__fastcall TaddScreen::TaddScreen(TComponent* Owner)
    : TForm(Owner)
{

}

//---------------------------------------------------------------------------
// Event handler for cancel button click
void __fastcall TaddScreen::cancelBtnClick(TObject *Sender)
{
    mainScreen->LoadCarsData();
    edtModel->Clear();
    edtCarPrice->Clear();
    edtUnitsSold->Clear();
    edtSalesCost->Clear();
    edtCommission->Clear();
    Close();                // - Closes the add screen form, discarding changes
}

//---------------------------------------------------------------------------
// Helper function to validate if a string contains only digits or a valid decimal
bool isDigit(AnsiString str)
{
    // - Handle empty string case
    if (str.Length() == 0)
        return false;       // - Empty string is invalid

    bool hasDecimal = false; // - Tracks if a decimal point has been found

    // - Loop through each character (AnsiString indices start at 1)
    for (int i = 1; i <= str.Length(); i++)
    {
        // - Allow digits and at most one decimal point
        if (isdigit(str[i]))
            continue;       // - Digit is valid, proceed to next character
        else if (str[i] == '.' && !hasDecimal)
            hasDecimal = true; // - First decimal point is valid
        else
            return false;   // - Invalid character encountered
    }

    return true;            // - All characters were valid (digits or one decimal)
}

//---------------------------------------------------------------------------
// Event handler for complete button click, processes and saves car data
void __fastcall TaddScreen::completeBtnClick(TObject *Sender)
{
    // - Retrieve input values from edit fields
    AnsiString model = edtModel->Text;              // - Car model name
    AnsiString priceStr = edtCarPrice->Text;       // - car price string
    AnsiString unitsStr = edtUnitsSold->Text;       // - Units sold string
    AnsiString costStr = edtSalesCost->Text;   // - sales cost string
    AnsiString commissionStr = edtCommission->Text; // - Commission percentage string

    // - Validate numeric fields
    bool isValid = isDigit(priceStr) && isDigit(unitsStr) &&
                   isDigit(costStr) && isDigit(commissionStr); // - Check if all are digits or decimals

    // - Prompt user for confirmation
    if (Application->MessageBox(L"Are you sure you want to add?",
                                L"Confirmation", MB_YESNO | MB_ICONQUESTION) == IDYES)
    {
        // - Create a string list for file operations
        TStringList *carList = new TStringList(this);

        if (isValid)
        {
            // - Load existing car data from CSV file
            carList->LoadFromFile("..\\..\\resources\\cars.csv");

            // - Add new car data as a comma-separated line
            carList->Add(model + "," + priceStr + "," +
                         (int)unitsStr.ToDouble() + "," + costStr + "," + commissionStr);

            // - Save updated data back to CSV file
            carList->SaveToFile("..\\..\\resources\\cars.csv");

            // - Notify user of success
            ShowMessage("Car details added successfully.");

            // - Refresh main screen data and close form
            mainScreen->LoadCarsData();
            edtModel->Clear();
            edtCarPrice->Clear();
            edtUnitsSold->Clear();
            edtSalesCost->Clear();
            edtCommission->Clear();
            Close();
        }
        else
        {
            // - Display error if validation fails
            Application->MessageBox(L"Enter digits or decimals where required",
                                    L"ERROR", MB_OK | MB_ICONERROR);
        }

}
}
