#include <iostream>
using namespace std;


int main()
{
    int i, p;
    char more;
    do
    {
        cout << "\n\t\tInput an Integer: ";
        cin >> p;

        for (i = 2; i <= p / 2; i++)
            if (p % i == 0) {
                cout << "\n\t\t" << p << " is NOT prime";
                break;
            }
        if (i > p / 2)
            cout << "\n\t\t" << p << " is PRIME";
        cout << "\n\t\t\tDo more (Y/N) ? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');

}