// Name: structTime.cpp Finding next second 
// Also demo two digit display for using setfill() and setw()
#include <iostream>
#include <iomanip>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool nextDay = false;
int leap (int year)
{
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
struct time
{
    int hh, mm, ss;
};
struct date
{
    int dd, mm, yy;
};
bool validDate(struct date x)
{
    int month = x.mm - 1;

    // Handle leap year
    if (leap(x.yy))
    {
        days[month] = 29;
    }
    else
    {
        days[month] = 28;
    }
    
    if (x.dd > days[month] || x.dd < 0 || x.mm > 12 || x.mm < 0)
        return false;
    else
        return true;
}
bool valid(struct time x)
{
    if (x.hh > 23 || x.hh < 0 || x.mm > 59 || x.mm < 0 || x.ss > 59 || x.ss < 0)
        return false;
    else
        return true;
}
struct time upDate(struct time x)
{
    x.ss++;
    if (x.ss > 59){
        x.ss = 0;
        x.mm++;
    }
    if (x.mm > 59){
        x.mm = 0;
        x.hh++;
    }
    if (x.hh > 23){
        x.hh = 0;
        nextDay = true;
    }
    return x;
}
struct date updateDay(struct date x)
{
    if(nextDay){
        x.dd++;
        if(x.dd > days[x.mm-1])
        {
            x.dd = 1;
            x.mm++;
        }
        if(x.mm > 12)
        {
            x.mm = 1;
            x.yy++;
        }
    }
    return x;
}
int main(){
    struct time now, next;
    struct date nowD, nextD;
    char buff,more;
    do{
        nextDay = false;

        cout << "\n\t\tInput the date (mm/dd/yyyy): ";
        cin >> nowD.mm >> buff >> nowD.dd >> buff >> nowD.yy;
        cout << "\n\t\tInput the time (hh:mm:ss): ";
        cin >> now.hh >> buff >> now.mm >> buff >> now.ss;
        if (valid(now) && validDate(nowD))
        {
            next = upDate(now);
            nextD = updateDay(nowD);
            cout << "\n\t\tOne second later, it is " << nextD.mm << "/" << nextD.dd << "/" << nextD.yy << " and the time is " << setfill('0') << setw(2) << next.hh << ":" << setfill('0') << setw(2) << next.mm
                << ":" << setfill('0') << setw(2) << next.ss;
            if (next.hh > 11)
                cout << " PM";
            else
                cout << "AM";
        }
            else 
                cout << "\n\t\tYour input is invalid for time or date, try again...";
    cout << "\n\t\t\tDo more (Y/N) ? ";
    cin >> more;
    }
    while (more == 'y' || more == 'Y');
}