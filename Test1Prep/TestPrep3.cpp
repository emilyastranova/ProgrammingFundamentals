#include <iostream>
using namespace std;


int main()
{
    int i, x, xx;
    char more;

    do
    {
        cout << "\n\t\tInput x: ";
        cin >> x;
        xx = x;
        for (i = 0; x > 0; i++)
        {
            x = x/10;
        }
        
        cout << "\n\t\tThe number of digits in " << xx << " is " << i;

        cout << "\n\t\t\tDo more (Y/N) ? "; 
        cin >> more; 
    } while (more == 'y' || more == 'Y');
    

}