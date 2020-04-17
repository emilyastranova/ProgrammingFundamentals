#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

struct file
{
    char name[20];
    char address[30];
    char city[20];
    char st[3];
    char zip[6];
    int age;
};

void printIt(struct file x[])
{
    int i;
    for (i = 0; i < 20; i++)
        cout << "\n\t     " << setw(20) << left << x[i].name << "    " << x[i].zip << "\t " << x[i].age;
};

void bubbleSort(struct file x[])
{
    int i, j;
    struct file temp;
    for (i = 0; i < 20; i++)
        for (j = 0; j < 20 - i - 1; j++)
            if (x[j].age > x[j + 1].age)
            {
                temp = x[j];
                x[j] = x[j + 1]; // You can swap a whole structure at one
                x[j + 1] = temp; // time, instead of a field at a time.
            }
} // End of bubble sort

void shellSort(struct file data[])
{
    int i, jump = 20;
    bool swapped = false;
    struct file temp;
    for (jump = jump / 2; jump > 0; swapped = true, jump = jump / 2)
    {
        while (swapped)
        {
            swapped = false;
            for (i = 0; i < 20 - jump; i++)
                ;
            if (data[i].age < data[i + jump].age)
            {
                temp = data[i];
                data[i] = data[i + jump];
                data[i + jump] = temp;
                swapped = true;
            }
        }
    }
} // End of shell sort

int findIt(struct file x[], int tmp) //This is binary search (BROKEN)
{
    // int frst = 0, last = 19, mid;

    // while (frst <= last)
    // {
    //     mid = (frst + last) / 2;
    //     if (x[mid].age == tmp)
    //         return mid;
    //     else
    //         if (x[mid].age > tmp)
    //             frst = mid + 1;
    //         else
    //             last = mid - 1;
    // }
    // return -1;

    bool found = false; // Test passes with sequential search
    int index = 0;
    int tmpZip = 0;
    for (int i = 0; i < 20; i++)
    {
        if (x[i].age == tmp)
        {
            found = true;
            index = i;
        }
    }

    if (found)
        return index;
    else
        return -1;


}

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

int main()
{
    int i, j, loc, tgt;
    char more = 'Y', buff;
    struct file temp;
    struct file data[] =
        {
            {"John J. Doe", "202 Harvey Rd", "College Station", "TX", "77450", 29},
            {"Tama Martin", "202 College Main", "Houston", "TX", "72002", 10}, 
            {"Dick Simmons", "Box 1010", "El Paso", "TX","72081", 55}, 
            {"Udo Pooch", "1984 Windwood", "Houston", "AR", "02400", 80}, 
            {"Aarron Stein", "1000 Spicewood", "New York", "NY", "23932", 90}, 
            {"Steve Jobs", "2082 RainTree", "College Station", "TX", "30020", 45}, 
            {"Robert Ricks", "8378 University DR.", "Bryan", "TX", "72001", 25}, 
            {"Richard Ticks", "2498 C. Main", "Los Angeles", "CA", "20020", 18}, 
            {"Tim Safferd", "3303 George Bush Dr.", "Bryan", "TX", "20200", 12}, 
            {"Rickard Thamos", "7438 RoseMerry", "Salt Lake", "UT", "83298", 73}, 
            {"Mary Hart", "3998 Hallow St", "Anthem", "CA", "00329", 30}, 
            {"Todd Hoffer", "2939 Univ. Blvd", "Huntsville", "AL", "23890", 63}, 
            {"Shannon Shoumaker", "2300 Decon", "Dallas", "TX", "73999", 24}, 
            {"Mike Meeks", "Box 2839", "Paris", "TX", "72990", 43}, 
            {"Mikey Monique", "Box 3899", "Kansas City", "MO", "38982", 65}, 
            {"Joe Motana", "10000 Hardwood", "San Franciso", "CA", "83999", 33}, 
            {"Tom Landry", "48923 Software", "Seattle", "WN", "43223", 13}, 
            {"Larry Bird", "3298 Hilow Ln", "Kauffman", "AK", "84920", 39}, 
            {"Denis Cohen", "Box 2399", "Las Cruis", "NM", "73289", 28}, 
            {"Fay Maybree", "399 Harvey Rd", "Wisconsin", "MO", "48299", 32},
        };
    
    cout << "\n\tBefore any sorting: ";
    cout << "\n" << space(2) << "Name" << space(3) << "Zip" << space(1) << "Age";
    printIt(data);
    cout << "\nHit enter key to continue..."; cin.get();

    cout << "\n Sort them by age in increasing order. (BUBBLE SORT)\n";
    bubbleSort(data); // Bubble sort on AGE key, in the increasing order!
    cout << "\n" << space(2) << "Name" << space(3) << "Zip" << space(1) << "Age";
    printIt(data);
    cout << "\nHit enter key to continue..."; cin.get();

    while (more == 'y' || more == 'Y')
    {
        cout << "\n\nPlease input an age to search: ";
        cin >> tgt;
        loc = findIt(data, tgt);
        if (loc > -1)
        {
            cout << "\n\n" << space(2) << "I am lucky, data at position " << loc + 1;
            cout << "\n" << space(1) << data[loc].name << " " 
            << data[loc].address << " " << data[loc].st << " " << data[loc].zip
            << " " << data[loc].age;
        }
        else
            cout << "\n\n" << space(2) << "Sorry! Your input is not found in his array...";
        cout << "\n\n" << space(2) << "Do more (Y/N) ?";
        cin >> more;
    }
    return 0;
}