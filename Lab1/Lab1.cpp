//  This is lab-1, named as lab1.cpp, it can calculate the loan payment in
//  monthly. However, this program has an almost invisible flaw, where?
//  how to fix it? Let you have fun to figure it out!!

#include <cmath>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    float charge, down, trade, intst, mintst, year, pay, cost;
    int month;
    char more = 'y';
    ifstream inFile;
    ofstream outFile;

    outFile.open("data1.out");

    while (more == 'y' || more == 'Y')  {
        cout << "\n\n\t\tWelcome to the user friendly loan system";
        cout << "\n\n\t\t\tInput your Loan Amount: ";
        cin >> charge;
        cout << "\n\t\t\tInput your Down Payment: ";
        cin >> down;
        cout << "\n\t\t\tInput Trade In Allowance: ";
        cin >> trade;
        cout << "\n\t\t\tInput Annual Interest Rate in decimal : ";
        cin >> intst;
        cout << "\n\t\t\tInput Length of Loan (in years): ";
        cin >> year;

        cost = charge - down - trade;
        month = year * 12;
        mintst = intst / 12;
        pay = mintst * cost * pow(1+mintst, month) / (pow(1+mintst, month) - 1);

        cout << "\n\n\t\t\tYour monthly payment is $" << setprecision(2) << fixed << pay << endl;

        cout << "\n\n\t\t\t Do more (Y/N) ? ";
        cin >> more;

        outFile << "\n\t" << setw(8) << setprecision(0) << fixed << charge
                << "     " << setw(6) << down << "\t" << setw(6) << trade
                << "\t     " << setprecision(2) << intst * 100 << "%\t " << right
                << setw(3) << (int) year << "\t $" << setw(8) << setprecision(2)
                << pay;
    }
    outFile.close();

    std::string inLine;
    inFile.open("data1.out");
    if (inFile.fail())
        cout << "\n\t\tUnable to open the input file";
    else {
        cout << "\n\n\n\t   Price     Down\tTradeIn\t   Interest\tYears\t" <<
             "   Monthly" << "\n\t\t    Payment\t\t     Rate\t\t   Payment";

        while (getline(inFile, inLine))
            cout << inLine << endl;
        inFile.close();
        getchar();
    }


    return 0;
}
