#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

string space() // I got tired of typing three tabs
{
    return "\t\t\t";
}
string space(int x) // Specified amount of tabs (e.g. space(4))
{
    string tab = "";

    for (int i = 0; i < x; i++)
        tab = tab + "\t";

    return tab;
}

int main()
{

    cout << setprecision(3) << fixed;
    char more, buff;
    do // Input loop, ends when user says N
    {

        cout << "\n\t\t\tDo more (Y/N)? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}