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

    // Handle decimal point
    cout << showpoint << setprecision(2) << fixed;

    while (more == 'y' || more == 'Y') // Input loop, ends when user says N
    {
        
        cout << "\n\n\t\tCalculating days past in the year: ";
        cout << "\n\n\t\tPlease input date (mm/dd/yyy): ";
        cin >> mm >> buff >> dd >> buff >> yy;

        if (dd >= x[mm-1] || mm >= 12) // if days >= to days in the month and if month is >= 12
        {
            do
            {
                cout << "\n\n\t\tWrong date in the year, try again! ";  // Display error
                cout << "\n\n\t\tPlease input date (mm/dd/yyy): ";
                cin >> mm >> buff >> dd >> buff >> yy;

            } while (dd >= x[mm-1] || mm >= 12); // Check until input is correct
            
        }

        for (i = 0, days = 0; i < mm - 1; days += x[i++]); // calculate days before the month mm

        days = days + dd; // add days in the month
        if (leap(yy) && mm > 2)
            days = days + 1;

        cout << "\n\n\t\tThere are " << days << " days from the beginning of the year past.";
        cout << "\n\n\t\tDo more (Y/N)? ";
        cin >> more;

    }
    
    cout << "\n\n\t\t\t Done by Tyler A. Harrison\n";
    return 0;

}