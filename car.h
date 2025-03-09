//---------------------------------------------------------------------------
// File: car.h
// Purpose: Header file for the Car class in a car management application
// Contains the declaration of the Car class to manage car sales data
//---------------------------------------------------------------------------
#ifndef CAR_H
#define CAR_H
//---------------------------------------------------------------------------
// Include necessary VCL headers
#include <vcl.h>            // VCL library for AnsiString and other components
//---------------------------------------------------------------------------

// Car class to encapsulate car sales information
class Car
{
private:    // Private members - inaccessible outside the class
    AnsiString carModel;            // - Stores the model name of the car
    double carPrice;               // - Base price of the car
    int unitsSold;                  // - Number of cars sold
    double salesCost;          		// - Total cost associated with sales
    double commissionPercentage;    // - Commission percentage for sales
    int profit;                  // - Calculated profit after costs

    // Private method
    void calcProfit();              // - Computes the profit based on sales data

public:     // Public members - accessible outside the class
    // Constructors
    Car();                          // - Default constructor initializing with default values
    Car(AnsiString model,           // - default overloaded constructor for initializing car data
        double price,
        int usold,
        double cost,
        double commission);

    // Getter methods
    AnsiString getCarModel();       // - Returns the car model name
    double getCarPrice();          // - Returns the car's price
    int getUnitsSold();             // - Returns the number of cars sold
    double getSalesCost();     // - Returns the total sales cost
    double getCommissionPercentage(); // - Returns the commission percentage
    int getProfit();             // - Returns the calculated net profit

    // Setter methods
    void setCarModel(AnsiString model);         // - Sets the car model name
    void setCarPrice(double price);            // - Sets the car's base price
    void setUnitsSold(int sold);                // - Sets the number of cars sold
    void setSalesCost(double cost);        // - Sets the total sales cost
    void setCommissionPercentage(double commission); // - Sets the commission percentage
};

//---------------------------------------------------------------------------
#endif
