#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int x=1, y = 1;

void runUntil(){
    do
    {
        cout << "x = " << x << " y = " << y << endl;
        cout << "Input x: ";
        cin >> x;
        cout << endl;
        cout << "Input y: ";
        cin >> y;
        cout << endl;
    } while (x < y);
    
}

int main()
{

    runUntil();

}