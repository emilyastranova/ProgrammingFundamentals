#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    int choice;
    double f, c;
    char more = 'y';

    cout << "\n\t\tRelationship between Fahrenheit and Celsius";
    cout << "\n\t\t\t 1 )    F  - >  C";
    cout << "\n\t\t\t 2 )    C  - >  F";

    // Handle decimal point
    cout << showpoint << setprecision(2) << fixed;

    while (more == 'y' || more == 'Y') // Input loop, ends when user says N
    {
        cout << "\n\n\t\t     Choice(1/2) ? ";
        cin >> choice;
        while (choice != 1 && choice != 2) // Making sure the user enters 1 or 2
        {

            if (choice != 1 && choice != 2)
            {
            cout << "\n\t\t     Invalid input: Please choose 1 or 2";
            cout << "\n\n\t\t     Choice(1/2) ? ";
            cin >> choice;
            }

        }

        if(choice == 1)
        {
            cout << "\n\n\t\t     Input F: ";
            cin >> f;
            c = (f-32) * 5/9;
            cout << "\n\n\t\t     " << f << "F\t=\t" << c << "C";
            cout << "\n\n\t\t     Do more (Y/N) ? ";
            cin >> more;
        }
        else
        {
            cout << "\n\n\t\t     Input C: ";
            cin >> c;
            f = c*9/5 + 32;
            cout << "\n\n\t\t     " << c << "C\t=\t" << f << "F";
            cout << "\n\n\t\t     Do more (Y/N) ? ";
            cin >> more;
        }
        
    }
    

    cout << endl;
    
    

    

    return 0;
}