#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int seq[] = {26, 16, 92, 81, 65, 59, 48, 31, 67, 27, 14, 9, 52, 38, 61};
int userNum;

void displaySeq()
{
    for (int i = 0; i < 15; i++)
    {
        cout << seq[i] << " ";
    }
    cout << endl;
}

void binarySearch()
{
    bool found = false;
    int pos = 0;
    int min = 0;
    int max = 14;
    int average;

    while (!found)
    {
        average = (min + max) / 2;
        if (seq[average] == userNum)
        {
            found = true;
            pos = average + 1;
        }
        else
        {

            if (average == min || average == max)
                break;

            if (seq[average] < userNum)
            {
                min = average + 1;
            }
            else
            {
                max = average - 1;
            }
        }
    }

    cout << "\n\t\t";
    if (found)
        cout << userNum << " is found at position " << pos;
    else
        cout << userNum << " is not found";
}

void shellSort(int array[])
{
    int length = 15;

    for (int space = length / 2; space > 0; space /= 2)
    {
        for (int i = space; i < length; i += 1)
        {
            int temp = array[i];
            int j;
            for (j = i; j >= space && array[j - space] > temp; j -= space)
            {
                array[j] = array[j - space];
            }
            array[j] = temp;
        }
    }
}

void getUserNum()
{
    cout << "\n\t\tInput a number: ";
    cin >> userNum;
}

int main()
{

    char more = 'y';
    cout << setprecision(3) << fixed;

    cout << "\t\tUnsorted Seq: ";
    displaySeq();

    // Sort the sequence
    shellSort(seq);

    cout << "\t\tSorted Seq: ";
    displaySeq();

    while (more == 'y' || more == 'Y') // Input loop, ends when user says anything but Y
    {
        // Prompt for user input to get number to search
        getUserNum();

        // Use binary search to find the num
        binarySearch();

        cout << "\n\t\t\tDo more (Y/N)? ";
        cin >> more;
    }

    cout << endl;

    return 0;
}