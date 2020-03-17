#include <iostream>
#include <iomanip>
using namespace std;

int leap (int year)
{
    //if (year % 400 == 0 || year & 100 != 0 && year % 4 == 0) (this statement does NOT work so I fixed it)
    if (year % 4 == 0) // If year is a multiple of 4
    {
        if (year % 100 == 0) // If divisible by 100, then must be also divisible by 400
        { 
            if(year % 400 == 0)
                return 1;
            else
                return 0;
        }
        else // Otherwise, just a regular leap year
            return 1;   
    }
    else
        return 0;  
    
}

int main(){

    int x[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days, mm, dd, yy, i;
    char more ='y', buff;
    int choice;

    // Handle decimal point
    cout << showpoint << setprecision(2) << fixed;

    while (more == 'y' || more == 'Y') // Input loop, ends when user says N
    {

        cout << "\n\t\tThis program will find days passed or date in the year";
        cout << "\n\t\t\t1) Input date (mm/dd/yyy) to find days passed";
        cout << "\n\t\t\t2) Input passed days to find date in the year";
        cout << "\n\t\t\t\tYour choice (1/2): ";
        cin >> choice;
        
        if (choice == 1)
        {
            cout << "\n\n\t\t\tPlease input date (mm/dd/yyy): ";
            cin >> mm >> buff >> dd >> buff >> yy;

            if (leap(yy))
                x[1] = 29; // Account for leap year
            else
                x[1] = 28;

            if (dd > x[mm-1] || mm > 12) // if days > to days in the month and if month is > 12
            {
                do
                {
                    cout << "\n\n\t\tWrong date in the year, try again! ";  // Display error
                    cout << "\n\n\t\tPlease input date (mm/dd/yyy): ";
                    cin >> mm >> buff >> dd >> buff >> yy;

                        if (leap(yy))
                            x[1] = 29; // Account for leap year
                        else
                            x[1] = 28;

                } while (dd > x[mm-1] || mm > 12); // Check until input is correct
                
            }

            for (i = 0, days = 0; i < mm - 1; days += x[i++]); // calculate days before the month mm

            days = days + dd; // add days in the month

            cout << "\n\t\t\tThere are " << days << " days passed in the year " << yy;

        }

        if (choice == 2)
        {
            bool somethingWrong = false;
            mm = 1; // Reset months
        
            cout << "\n\t\t\tInput days: ";
            cin >> days;

            cout << "\n\t\t\t\tYears: ";
            cin >> yy;

            if (leap(yy))
            {
                if (days > 366 || days < 1) // Handle illegal input
                {
                    cout << "\n\n\\tt\tSorry, something wrong with days or year";  // Display error
                    somethingWrong = true;
                }
                x[1] = 29; // Account for leap year

            }

            else
            {
                if (days > 365 || days < 1) // Handle illegal input
                 {
                    cout << "\n\t\t\tSorry, something wrong with days or year";  // Display error
                    somethingWrong = true;
                 }
                x[1] = 28; // Reset days in case you redo the loop
            }

            if (!somethingWrong)
            {
                for (int i = 0; i < 12; i++) // Go through every month
                {
                    //cout << "\n\t\tIn month: " << i+1 << ", there are " << x[i] << " days.";
                    if(days > 0 && days > x[i]) // Run if days are left
                    {
                        //cout << "\n\t\t" << days << " is more than " << x[i] <<" so we subtract.";
                        days = days - x[i]; // Subtract number of days by reading the array
                        if(mm < 12)
                            mm += 1; // Add one more month
                    }
                    else
                    {
                        //cout << "\n\t\t" << days << " is not more than " << x[i] <<" so we stop.";
                        break; // Exit the looop to stop counting months
                    }
                    
                }
                cout << "\n\t\t\tThe date is " << mm << "/" << days << "/" << yy;
            }
        }

        cout << "\n\n\t\t\tDo more (Y/N)? ";
        cin >> more;

    }
    
    cout << "\n\n\t\t\tDone by Tyler A. Harrison\n";
    return 0;

}