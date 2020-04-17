#include <iostream>
#include <iomanip>
#include <fstream>
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

bool alpha(char x)
{
    if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
        return true;
    else
        return false;
}

int countIt(string x)
{
    bool inWord = false;
    int i = 0, count = 0;

    while (x[i])
    {
        if(alpha(x[i++]))
        {
            if(!inWord)
            {
                inWord = true;
                count++;
            }
        }
        else   
            inWord = false;
    }
    return count;
    
}

int numWords = 0;
void displayFile()
{
    ifstream inF;
    inF.open("data.in");
    string x;
   
    do  // Read the file line for line until end-of-file
    {
        getline(inF, x);
        cout << x << space(1) << countIt(x) <<endl;
        numWords += countIt(x);
    } while (!inF.eof());

}


int main()
{
    displayFile();

    cout << "\n\n" << space() << "There are " << numWords << " words in the file" << endl;
    cout << "-------------------------------------------------" << endl;

}