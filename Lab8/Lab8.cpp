// Name: Tyler Harrison

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

ifstream inFile;
ofstream outFile("blinn.out");
double depNum, quantity, cost, sale;
string items;

/*
    Requirements:
        1) Sum of each department                       [X]
        2) Minimum of each department                   [X]
        3) Extended cost (quantity * unit cost)         [X]
        4) Extended market (quantity * unit sale price) [X]
        5) Subtotal each department                     [X]
        6) Grand lower cost total                       [X]
*/


void printHeader()
{
    cout << "\n\t\t\t\t\t   Blinn Apparel Store\n"
         << endl;
    cout << "\t\t\t\t\tUnit    Cost"
         << "\t\t    Extended" << endl;
    ;
    cout << "\t\t     Quantity"
         << "\t\tCost  "
         << "  Market"
         << "\t\t Cost"
         << "\t   Market "
         << "\t Lower Cost" << endl;
    outFile << "\n\t\t\t\t\t   Blinn Apparel Store\n"
            << endl;
    outFile << "\t\t\t\t\t\t\tUnit    Cost"
            << "\t\t    Extended" << endl;
    outFile << "\t\t     Quantity"
            << "\t\tCost  "
            << "  Market"
            << "\t\t Cost"
            << "\t   Market "
            << "\t Lower Cost" << endl;
}

double findLower(double x, double y)
{
    if (x < y)
        return x;
    else
        return y;
}

void displayDepHeader(int x)
{
    switch (x)
    {
    case 1:
        cout << "Mens Dept" << endl;
        break;
    case 2:
        cout << "Ladies Dept" << endl;
        break;
    case 3:
        cout << "Girls Dept" << endl;
        break;
    case 4:
        cout << "Boys Dept" << endl;
        break;

    default:
        break;
    }
}

int main()
{
    printHeader(); // Display Blinn Apparel Store

    inFile.open("blinn.dat");
    if (!inFile)
        cout << "\n\t\tCan't open data file: blinn.dat\n"; // Tell user file not found

    cout << fixed << setprecision(2);
    outFile << setprecision(2) << fixed;

    double current = 0;
    bool firstList = true;
    double depCost = 0;
    double depSale = 0;
    double grandTotal = 0;

    while (inFile >> depNum >> items >> quantity >> cost >> sale) // Pull in numbers from blinn.dat and assign variables
    {

        if (current != depNum && firstList) // If department changes, write title of dept
        {
            displayDepHeader(depNum);
            current = depNum;
            firstList = false;
        }
        if (current != depNum && !firstList) // If department changes, write title of dept, display total above this for previous dept
        {
            cout << "  Total\t\t\t\t\t\t\t\t$" << depCost
                 << "  $" << depSale
                 << "      $"
                 << findLower(depSale, depCost) << endl;
            outFile << "  Total\t\t\t\t\t\t\t$" << depCost
                    << "  $" << depSale
                    << "      $"
                    << findLower(depSale, depCost) << endl;
            grandTotal += findLower(depSale, depCost); // Add the lower cost up to grand lower total
            displayDepHeader(depNum);
            current = depNum;
            depCost = 0;
            depSale = 0;
        }
        cout << right << setw(4) << "" << items << "\t\t" << quantity << "\t\t" << cost
             << "\t" << sale
             << "\t\t" //Display and do the math
             << cost * quantity
             << "   " << sale * quantity << endl;
        outFile << right << setw(4) << "" << items << "\t\t" << quantity << "\t\t" << cost
                << "\t" << sale
                << "\t\t" //Display and do the math
                << cost * quantity
                << "   " << sale * quantity << endl;
        depCost += cost * quantity; // Increment costs up for total
        depSale += sale * quantity;
    }
    cout << "  Total\t\t\t\t\t\t\t       $" << depCost
         << "  $" << depSale
         << "      $"
         << findLower(depSale, depCost) << endl; // Print last total outside of loop
    outFile << "  Total\t\t\t\t\t\t\t       $" << depCost
            << "  $" << depSale
            << "      $"
            << findLower(depSale, depCost) << endl;
    grandTotal += findLower(depSale, depCost);                          // Add the lower cost up to grand lower total
    cout << "Inventory at lower cost\t\t\t\t\t\t\t\t\t$" << grandTotal; // Print grand lower total

    inFile.close(); // Keep file from corrupting on program end
}