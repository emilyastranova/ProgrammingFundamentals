#include <iostream>
using namespace std;


int main()
{
    int i, x, xx, sum; char more; 
    do { 
        cout << "\n\t\tInput x: ";
        cin >> x; 
        for (i =  0, sum = 0, xx = x; x > 0; i++, x = x / 10)
            sum = sum + x % 10; 
        cout << "\n\t\tThe digit sum of " << xx << " is " << sum; 
        cout << "\n\t\t\tDo more (Y/N) ? "; 
        cin >> more; 
        }  
    while (more == 'y' || more== 'Y');


}