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
    char more;
    double x;

    do // Input loop, ends when user says N
    {
        cout << "\n\t\t\t\tInput X: ";
        cin >> x;

        cout << setw(10) << "\n" << space(4) << "       LibraryResult\tMyResult" << endl;
        cout << space() << setprecision(2) << fixed << "sin< " << x << ">" << "\t" << setw(10) << setprecision(6) << fixed << sin(x) << endl;
        cout << space() << setprecision(2) << fixed << "cos< " << x << ">" << "\t" << setw(10) << setprecision(6) << fixed << cos(x) << endl;
        cout << space() << setprecision(2) << fixed << "exp< " << x << ">" << "\t" << setw(10) << setprecision(6) << fixed << exp(x) << endl;

        cout << "\n\t\t\tDo more (Y/N)? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');
}