# Car Sales Management Application

## Description
The Car Sales Management Application is a C++ Windows Forms application developed for managing car sales data. It allows users to read and write car sales information from/to a `cars.csv` file, display car models with their calculated profits in a ListBox, search for specific car models, and identify the car with the highest profit.

## Installation
To set up and run the application on your system, follow these steps:

### Prerequisites
- Operating System: Windows, the app ONLY tested on Windows 11 it MAY or MAY NOT work on other versions.
- IDE: Embarcadero RAD Studio (C++ Builder), the app was ONLY tested on version 12.1 it MAY or MAY NOT work on other versions.
- Files Required:
  - Source code files: `mainform.h`, `mainform.cpp`, `car.h`, `car.cpp`, `add.h`, `add.cpp`, `profile.h`, `profile.cpp`
  - Resource files: `cars.csv` , `1-8106cD20.ico` (icon)

### Compilation
1. Download the Project:
   - After downloading the zip folder unzip it in your preferred location.
   - Copy the project folder containing all source files to your machine.

2. Open in RAD Studio:
   - Open the project folder
   - Open the project by double clicking the `.cbproj` 

4. compile and run the Project:

## How will the app work
1. Launch the Executable:
   - Double-click the `.exe` file (i.e., `assignment.exe`) in the Executable folder choose either win32 or win64.

2. Main Screen Features:
   - ListBox Display: On startup, the application reads `cars.csv` and displays all car models with their profits in a ListBox.
   - Add Button: Click "Add" to open a form for entering new car sales data.
   - Search Button: Click "Search" to open an InputBox, enter a car model, and view its details.
   - Highest Profit Button: Click "Highest" to display the car model with the highest profit.
   - Exit Button: self explanatory

3. Adding a New Car:
   - In the "Add" form, enter:
     - Car Model 
     - Price 
     - Number of Items Sold 
     - Cost of Sales
     - Commission Percentage
   - Click "Complete" to save to `cars.csv` (after confirmation) or "Cancel" to discard.

4. Viewing Car Details:
   - Select a car model from the ListBox and click to view its full details (price, units sold, cost, commission, profit) in a profile window.



copyright© Nym.jace 2025 - Ex [codice] in infinitum
