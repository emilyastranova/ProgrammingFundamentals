#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear = false;

struct date
{
    int mm, dd, yy;
};

struct date updateIt(struct date x)
{
    x.dd++;
    if (x.dd > days[x.mm - 1])
    {
        x.dd = 1;
        x.mm++;
    }

    if (x.mm > 12)
    {
        x.mm = 1;
        x.yy++;
    }

    return x;
}

bool checkLeap(struct date x)
{
    if (x.yy % 4 == 0)
    {
        if (x.yy % 100 == 0)
        {
            if (x.yy % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    else
        return false;

    return false;
}

struct date checkDate(struct date x)
{
    char buff;

    if(isLeapYear)
        days[1] = 29;
    else
        days[1] = 28;

    while (x.dd > days[x.mm - 1] || x.mm > 12)
    {
        cout << "\n\t\tInvalid date, please re-enter: ";
        cout << "\n\t\tInput a date (mm/dd/yyy): ";
        cin >> x.mm >> buff >> x.dd >> buff >> x.yy; // Get user input, remove dashes, store into today struct
        isLeapYear = checkLeap(x); // Check for leap year
        if(isLeapYear)
            days[1] = 29;
        else
            days[1] = 28;
    }
    return x;
}

int main()
{

    cout << setprecision(3) << fixed;

    struct date today, tomorrow;
    char more, buff;
    do // Input loop, ends when user says N
    {
        cout << "\n\t\tInput a date (mm/dd/yyy): ";
        cin >> today.mm >> buff >> today.dd >> buff >> today.yy; // Get user input, remove dashes, store into today struct

        isLeapYear = checkLeap(today); // Check for leap year
        today = checkDate(today); // Check for invalid input
        tomorrow = updateIt(today);

        cout << "\n\t\tTomorrow will be " << tomorrow.mm << "/" << tomorrow.dd << "/" << tomorrow.yy;

        cout << "\n\t\t\tDo more (Y/N)? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}