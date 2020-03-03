#include <iostream>
using namespace std;


int main()
{
    int i, num;
    char more;
    do
    {
        cout << "\n\t\tInput a number: ";
        cin >> num;

        cout << "\t\tThe factors are 1";
        for (int i = 2; i < num; i++) //Calculate factors
        {
            if (num % i == 0)
            {
                cout << ", " << i;
            }
        }

        cout << "\n\n\t\t\tDo more (Y/N) ? ";
        cin >> more;
    } while (more == 'y' || more == 'Y');

}