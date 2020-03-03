#include <iostream>
using namespace std;

int num = 1;
int numToAdd = 1;

int main()
{
    for (int i = 0; i < 20; i++)
    {

        cout << num << " "; //Output num followed by a space

        if(i != 19) //Don't do it the last time, need to output the final number again
        {   num = num + numToAdd; //Add num to numToAdd
            numToAdd++; //Increase numToAdd by 1
        }

    }

    cout << "\n\nThe 20th term is: " << num << endl;

}