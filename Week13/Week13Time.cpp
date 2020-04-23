// Name: structTime.cpp Finding next second 
// Also demo two digit display for using setfill() and setw()
#include <iostream>
#include <iomanip>
using namespace std;

struct time
{
    int hh, mm, ss;
};

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
    }
    return x;
}

int main(){
    struct time now, next;
    char buff,more;
    do{
        
        cout << "\n\t\tInput the time (hh:mm:ss): ";
        cin >> now.hh >> buff >> now.mm >> buff >> now.ss;
        if (valid(now))
        {
            next = upDate(now);
            cout << "\n\t\tThe update time is " << setfill('0') << setw(2) << next.hh << ":" << setfill('0') << setw(2) << next.mm
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