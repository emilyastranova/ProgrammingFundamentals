#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

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