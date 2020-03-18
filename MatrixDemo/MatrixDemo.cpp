#include <iostream>
#include <iomanip>
using namespace std;

void printOut(int ax[][3], int ay[][3])
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

void findSum(int a[][3], int b[][3], int c[][3])
{
    int i,j;
    for(i = 0; i < 3; i++)  
        for(j=0; j< 3; j++)
            c[i][j] = a[i][j] + b[i][j];
    
}

void findProd(int x[][3], int y[][3], int z[][3])
{
    int i, j, k;
    for(i = 0; i < 3; i++)  
        for(j = 0; j < 3; j++){
            z[i][j] = 0;
                for (k = 0; k < 3; k++)
                    z[i][j] += x[i][k] * y[k][j];
                
        }

    
}

int main()
{
    int x[][3] = {1, -2, 0, 2, 0, 1, 2, -1, 1};
    int y[][3] = {2, -3, 1, -2, -2, 3, 1, -2, 2};
    int id[][3] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    int sum[3][3], prod[3][3], power[3][3] = {};
    int temp[3][3] = {};
    int i, j, k, m;
    printf("\n\t\t     Matrix X\t\t     Matrix Y\n\t\t");
    printOut(x,y);
    findSum(x,y,sum);
    findProd(x,y,prod);
    printf("\n\n\n\t\t      X + Y\t\t      X * Y");
    printOut(sum, prod);
    cout << "\n\n\n";

}