#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
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

void printOut(double ax[][3], double ay[][3])
{

    int i,j;
    for(i = 0; i < 3; i++)  {
            cout << "\n\t\t";
        for(j=0; j< 3; j++)
            cout << setw(5) << ax[i][j] << " ";
        cout << "\t\t";
        for(j = 0; j < 3; j++)
            cout << setw(5) << ay[i][j] << " ";
    }
}

int main()
{
    
    double x[][3] = {2, -3, 0, 0, 1.5, 0, 1.5, 0, 1.5};
    double y[][3] = {1, 0, 0, 0, 1, 0, -0, 0, 1};

    cout << right << setw(5) << setprecision(2) << fixed;
    cout << "\n" << "\t\t     " << "inva" << space() << "     " << "A * invaA" << endl;
    printOut(x,y);
    cout << "\n\n\n\n\n--------------------";

}