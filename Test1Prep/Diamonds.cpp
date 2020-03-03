#include <iostream>
using namespace std;


int main()
{
    int n;
    char more;

    do
    {
        cout << "Input a size: "; //Get size
        cin >> n;
        for (int i = 0; i < n; i++){ //Run n times (vertical) TOP
            cout << "\n"; //New line

            for(int j = 0; j < n - i; j++)
                cout << ' ';
            for(int j = 0; j <= i; j++)
                cout << "+ ";
        }
        for (int i = n-2; i >= 0; i--){ //Run n times (vertical) BOTTOM
            cout << "\n"; //New line

            for(int j = 0; j < n - i; j++)
                cout << ' ';
            for(int j = 0; j <= i; j++)
                cout << "+ ";
        }

        cout << "\nDo more? (Y/N) "; //Do more?
        cin >> more;
    } while (more == 'y' || more == 'Y');
    

}