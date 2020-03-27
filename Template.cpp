#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

    char more = 'y';

    cout << setprecision(3) << fixed;

    while (more == 'y' || more == 'Y') // Input loop, ends when user says N
    {

        cout << "\n\n\t\t\tDo more (Y/N)? ";
        cin >> more;
        
    }
    
    cout << endl;

    return 0;
}