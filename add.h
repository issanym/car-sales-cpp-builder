//---------------------------------------------------------------------------
// File: addH.h
// Purpose: Header file for the add screen form in a car management application
// Contains the declaration of the TaddScreen class for adding new car data
//---------------------------------------------------------------------------
#ifndef ADD_H
#define ADD_H
//---------------------------------------------------------------------------
// Include necessary system and VCL headers
#include <System.Classes.hpp>   // - Base classes for VCL components
#include <Vcl.Controls.hpp>     // - Standard VCL control components
#include <Vcl.StdCtrls.hpp>     // - Standard VCL controls like TLabel, TEdit, TButton
#include <Vcl.Forms.hpp>        // - VCL form class definitions
//---------------------------------------------------------------------------

class TmainScreen;              // - Forward declaration of TmainScreen class

// Add screen form class for entering new car data
class TaddScreen : public TForm
{
__published:    // IDE-managed Components - accessible in Form Designer
    TLabel *Label1;             // - Label for car model field
    TLabel *Label2;             // - Label for base price field
    TLabel *Label3;             // - Label for units sold field
    TLabel *Label4;             // - Label for total sales cost field
    TLabel *Label5;             // - Label for commission percentage field
    TEdit *edtModel;            // - Text input for car model
    TEdit *edtCarPrice;        // - Text input for car price
    TEdit *edtUnitsSold;        // - Text input for units sold
    TEdit *edtSalesCost;   		// - Text input for total sales cost
    TEdit *edtCommission;       // - Text input for commission percentage
    TButton *completeBtn;       // - Button to save entered car data
    TButton *cancelBtn;         // - Button to discard changes and close form

    // Event handlers
    void __fastcall cancelBtnClick(TObject *Sender);    // - Handles cancel button click
    void __fastcall completeBtnClick(TObject *Sender);  // - Handles complete button click

private:    // User declarations

public:     // User declarations
    // Constructor
    __fastcall TaddScreen(TComponent* Owner);           // - Initializes the add screen form
};

//---------------------------------------------------------------------------
extern PACKAGE TaddScreen *addScreen;   // - Global pointer to add screen instance
//---------------------------------------------------------------------------
#endif
