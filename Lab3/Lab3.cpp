#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){

    float a, b, c;
    float discriminant;
    float x1, x2;
    char more = 'y';

    cout << setprecision(3) << fixed;

    while (more == 'y' || more == 'Y') // Input loop, ends when user says N
    {

        cout << "\n\t\tSolve quadratic equation for giving A,B,C coefficient" << endl;
        cout << "\n\t\t\tPlease input A:";
        cin >> a;
        cout << "\n\t\t\t\t     B:";
        cin >> b;
        cout << "\n\t\t\t\t     C:";
        cin >> c;

        discriminant = (b*b) - (4*a*c);

        if (a == 0 && b == 0 && c == 0){ // Infinite check
            cout << "\n\t\t\tInfinite Solutions";
        }

        else if (a == 0 && b == 0 && c != 0){ // Infinite check
            cout << "\n\t\t\tContradict Equation";
        }

        else if (a == 0 ) { // Check for divide by 0
            x1 = -c / b;
            cout << "\n\t\t\tSingle Root. x = " << x1;
        }

        else if (discriminant > 0) { // Discriminant is > 0 so solutions are real and different
            x1 = (-b + sqrt(discriminant)) / (2*a);
            x2 = (-b- sqrt(discriminant)) / (2*a);
            cout << "\n\t\t\tTwo real roots, X1 = " << x1;
            cout << ", X2 = " << x2 << endl;
        }
    
        else if (discriminant == 0) { // Discriminant is 0 so solutions are the same
            x1 = (-b / (2*a));
            cout << "\n\t\t\tRepeated root, X= " << x1 << endl;
        }

        else { // Discriminant is < 0 so solutions are complex
            x1 = -b / (2 * a);
            x2 = sqrt(-discriminant) / (2 * a);
            cout << "\n\t\t\tTwo Complex roots, X1 = " << x1 << " + " << x2 << "i";
            cout << ", X2 = " << x1 << " - " << x2 << "i" << endl;
        }


        cout << "\n\n\t\t\tDo more (Y/N)? ";
        cin >> more;
        
    }
    

    cout << endl;

    return 0;
}