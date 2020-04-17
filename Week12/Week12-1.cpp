/* This program will read in data from a disk file, named prison.dat, then calculate and make report about inmates in a prison.
123456789012345678901234 Long T 43 6 1995 40 Time S 347 9 2008 21 Sims L 745 1 2005 19
Col. 1 - 4: Last Name Col. 6: Initial Col. 8 - 10: sentence months Col. 12: Month got in. Col. 14 - 17: Year got in. COL. 19 - 20: age got in.
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int main()
{
    ifstream inFile;
    ofstream outFile;
    // varName for input using
    char name1[5], name2[2];
    int sentence, inMon, inYear, inAge;
    int outMon, outYear, outAge;
    inFile.open("prison.dat"); // connect infile with disk fileName
    if (!inFile)
        cout << "\n\t\tCan't open data file: prison.dat\n";
    else
    {
        cout << "\n\n\t\t\t\tBlinn Prison Report";
        cout << "\n\n\n\tName\t Sentence \tEntered    Prison    Released\t Prison";
        cout << "\n\t\t   Months\t  Age \t  YR Month    Age  YR \t  Month";
        while (inFile >> name1 >> name2 >> sentence >> inMon >> inYear >> inAge)
        {
            outAge = inAge + (sentence + inMon) / 12;
            outYear = inYear + sentence / 12;
            outMon = inMon + sentence % 12;
            if (outMon > 12)
            {
                outMon = outMon - 12;
                outYear = outYear + 1;
            }
            cout << "\n\t" << name1 << " " << name2 << setw(10) << sentence
                 << setw(10) << inAge << setw(5) << inYear << setw(7) << inMon << setw(10) << outAge << setw(5) << outYear << setw(8) << outMon;

        }
        cout << "\n\n\n\t\t\t"
             << "Programming is FUN!!\n\n\n";
    }
    return 0;
}
