//---------------------------------------------------------------------------
// File: profileH.h
// Purpose: Header file for the car profile form in a car management application
// Contains the declaration of the TcarProfile class for displaying car details
//---------------------------------------------------------------------------
#ifndef PROFILE_H
#define PROFILE_H
//---------------------------------------------------------------------------
// Include necessary system and VCL headers
#include <System.Classes.hpp>   // - Base classes for VCL components
#include <Vcl.Controls.hpp>     // - Standard VCL control components
#include <Vcl.StdCtrls.hpp>     // - Standard VCL controls like TLabel, TEdit, TButton
#include <Vcl.Forms.hpp>        // - VCL form class definitions
//---------------------------------------------------------------------------

// Car profile form class for displaying car sales data
class TcarProfile : public TForm
{
__published:    // IDE-managed Components - accessible in Form Designer
    TLabel *mdlName;            // - Displays the car model name
    TLabel *Label1;             // - Label for base price field
    TEdit *tedtCarPrice;       // - Text display for car price
    TLabel *Label2;             // - Label for units sold field
    TEdit *tedtUnitsSold;       // - Text display for units sold
    TLabel *Label3;             // - Label for total sales cost field
    TEdit *tedtSalesCost;  // - Text display for total sales cost
    TLabel *Label4;             // - Label for commission percentage field
    TEdit *tedtCommission;      // - Text display for commission percentage
    TLabel *Label5;             // - Label for net profit field
    TEdit *tedtProfit;       // - Text display for profit
    TButton *okBtn;             // - Button to close the profile form

    // Event handlers
    void __fastcall okBtnClick(TObject *Sender);    // - Handles OK button click

private:    // User declarations

public:     // User declarations - publicly accessible members
    // Constructor
    __fastcall TcarProfile(TComponent* Owner);      // - Initializes the car profile form

    // Public method to set car details in the form
    void setCarDetails(AnsiString model,            // - Sets all car details for display
                       double carPrice,
                       int unitsSold,
                       double salesCost,
                       double commissionPercentage,
                       double profit);
};

//---------------------------------------------------------------------------
extern PACKAGE TcarProfile *carProfile;
//---------------------------------------------------------------------------
#endif
