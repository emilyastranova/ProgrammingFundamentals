#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct date
{
    int mm, dd, yy;
};

class Person
{
private:
    string name, phone, height;
    struct date bDay;
    double weight;

public:
    Person()
    {
        name = "No name";
        phone = "(000) 000-0000";
        height = "0'00\"";
        bDay = {1, 1, 1900};
        weight = 0.0;
    }

    Person(string aName, string aPhone, string aHeight,
           struct date aBDay, double aWeight)
    {
        name = aName;
        phone = aPhone;
        height = aHeight;
        bDay = aBDay;
        weight = aWeight;
    }

    void setName(string x)
    {
        name = x;
    }
    void setPhone(string x)
    {
        phone = x;
    }
    void setHeight(string x)
    {
        height = x;
    }

    void setBDay(struct date); // See line 67-72
    void setWeight(double);    // Do it outside of the Person

    string getName()
    {
        return name;
    }
    string getPhone()
    {
        return phone;
    }
    string getHeight()
    {
        return height;
    }
    struct date getBDay()
    {
        return bDay;
    }
    double getWeight()
    {
        return weight;
    }
};

void Person:: setBDay(struct date x)
{
    bDay = x;
}
void Person:: setWeight(double x)
{
    weight = x;
}

int i = 0;

int main()
{
        Person p2("Test","0", "0", {0,0,0}, 0.0); //Initiazlized
        Person people[] = {Person()};
        string name;
        cout << "Name: ";
        cin >> name;
        people[i].setName(name);

        for(int x = 0; x < i; x++)
    {
        cout << "\n  " << setw(15) << left << people[i].getName() << "   "
         << people[i].getPhone() << " " << setw(9) << right << people[i].getHeight() << "   "
         << setw(2) << people[i].getBDay().mm << "/" << setw(2) << people[i].getBDay().dd
         << "/" << setw(4) << people[i].getBDay().yy << "      " << fixed
         << setprecision(2) << people[i].getWeight();
    }
}