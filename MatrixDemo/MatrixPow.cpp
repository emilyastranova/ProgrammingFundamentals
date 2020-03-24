#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

void printOut(double ax[][3], double ay[][3])
{
    int i,j;
    for(i = 0; i < 3; i++)  {
            cout << "\n\t\t";
        for(j=0; j< 3; j++)
            cout << setw(4) << ax[i][j] << " ";
        cout << "\t\t";
        for(j = 0; j < 3; j++)
            cout << setw(4) << ay[i][j] << " ";
    }
}

void printOut(int ax[][3])  // Made this so I could only print the power matrix
{
    int i,j;
    for(i = 0; i < 3; i++)  {
            cout << "\n\t\t";
        for(j=0; j< 3; j++)
            cout << setw(4) << ax[i][j] << " ";
    }
}

void findPow(double x[][3], double y[][3], double z[][3], double z2[][3], int powNum)
{
    int i,j, temp;
    for(i = 0; i < 3; i++)  // For Matrix X
        for(j=0; j< 3; j++){
            temp = x[i][j];
            for(int n = 1; n < abs(powNum); n++)
                x[i][j] = x[i][j] * temp;
        if(powNum >= 0)     // Exception for negative numbers, different math
            z[i][j] = x[i][j];
        else
            z[i][j] = 1 / x[i][j];
        }

    for(i = 0; i < 3; i++)  // For Matrix Y
        for(j=0; j< 3; j++){
            temp = y[i][j];
            for(int n = 1; n < abs(powNum); n++)
                y[i][j] = y[i][j] * temp;
        if(powNum >= 0)     // Exception for negative numbers, different math
            z2[i][j] = y[i][j];
        else
            z2[i][j] = 1 / y[i][j];

        }

}

int main()
{
    double x[][3] = {1, -2, 0, 2, 0, 1, 2, -1, 1};
    double y[][3] = {2, -3, 1, -2, -2, 3, 1, -2, 2};
    double power[3][3], power2[3][3] = {};
    int powNum;
    printf("\n\t\t     Matrix X\t\t     Matrix Y\n\t\t");
    printOut(x, y);

    cout << "\n\n\tInput number to raise matrix to the power of: ";
    cin >> powNum;

    printf("\n\t\t     Matrix X\t\t     Matrix Y\n\t\t");
    findPow(x, y, power, power2, powNum);
    printOut(power, power2);
    cout << "\n\n\n";

}