//---------------------------------------------------------------------------
// File: car.cpp
// Purpose: Implementation file for the Car class in a car management application
// Contains the definitions of Car class methods for managing car sales data
//---------------------------------------------------------------------------

#pragma hdrstop

#include "car.h"            // Header file for Car class declaration
//---------------------------------------------------------------------------
#pragma package(smart_init)

// Default constructor initializing Car object with placeholder values
Car::Car()
{
    carModel = "#####";             // - Placeholder for uninitialized car model
    carPrice = -1;                 // - Invalid price indicator
    unitsSold = -1;                 // - Invalid sales count
    salesCost = -1;            // - Invalid cost indicator
    commissionPercentage = -1;      // - Invalid commission indicator
    profit = -1;                 // - Profit not yet calculated
}

// Parameterized constructor initializing Car object with provided values
Car::Car(AnsiString model, double price, int sold, double cost, double commission)
{
    if (model != "")                // - Check for valid model name
        carModel = model;           // - Set model only if non-empty

    carPrice = price;              // - Assign car price
    unitsSold = sold;               // - Assign number of units sold
    salesCost = cost;          // - Assign sales cost
    commissionPercentage = commission; // - Assign commission percentage

    calcProfit();                   // - Compute profit after initialization
}

// Calculates net profit based on price, units sold, cost, and commission
void Car::calcProfit()
{
    profit = (carPrice * unitsSold) - (salesCost * unitsSold) -
                (carPrice * unitsSold * commissionPercentage); // - Formula: Revenue - Costs - Commission
}

// Returns the car model name
AnsiString Car::getCarModel()
{
    return carModel;                // - Provides access to private carModel
}

// Returns the car price of the car
double Car::getCarPrice()
{
    return carPrice;               // - Provides access to private carPrice
}

// Returns the number of units sold
int Car::getUnitsSold()
{
    return unitsSold;               // - Provides access to private unitsSold
}

// Returns the sales cost
double Car::getSalesCost()
{
    return salesCost;          // - Provides access to private salesCost
}

// Returns the commission percentage
double Car::getCommissionPercentage()
{
    return commissionPercentage;    // - Provides access to private commissionPercentage
}

// Returns the calculated net profit
int Car::getProfit()
{
    return profit;               // - Provides access to private Profit
}

// Sets the car model name
void Car::setCarModel(AnsiString model)
{
    carModel = model;               // - Updates carModel with new value
}

// Sets the base price of the car
void Car::setCarPrice(double price)
{
    carPrice = price;              // - Updates carPrice with new value
}

// Sets the number of units sold
void Car::setUnitsSold(int sold)
{
    unitsSold = sold;               // - Updates unitsSold with new value
}

// Sets the total sales cost
void Car::setSalesCost(double cost)
{
    salesCost = cost;          // - Updates salesCost with new value
}

// Sets the commission percentage
void Car::setCommissionPercentage(double commission)
{
    commissionPercentage = commission; // - Updates commissionPercentage
}
