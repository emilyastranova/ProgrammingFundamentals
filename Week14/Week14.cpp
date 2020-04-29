//Name: Tyler Harrison

#include <iostream>
#include <iomanip>
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

int main()
{
    cout << setprecision(3) << fixed;

    Person p1, // No value
           p2("Mary M. Smith","(222) 222-2222", "5'07\"", {10,10,1988}, 120.32); //Initiazlized
    
    //Init for object p1 in the following
    p1.setName("John D. Doe");
    p1.setPhone("(111) 111-1111");
    p2.setHeight("6'02\"");
    p1.setBDay({10, 1, 2000});
    p1.setWeight(293.49);

    cout << "\n" << "       Name" << "\t\t Phone" << "         Height" << "\t B-Date"
         << "\t       Weight";
    cout << "\n  " << setw(15) << left << p1.getName() << "   "
         << p1.getPhone() << " " << setw(9) << right << p1.getHeight() << "   "
         << setw(2) << p1.getBDay().mm << "/" << setw(2) << p1.getBDay().dd
         << "/" << setw(4) << p1.getBDay().yy << "      " << fixed
         << setprecision(2) << p1.getWeight();
    cout << "\n  " << setw(15) << left << p2.getName() << "   "
         << p2.getPhone() << " " << setw(9) << right << p2.getHeight() << "   "
         << setw(2) << p2.getBDay().mm << "/" << setw(2) << p2.getBDay().dd
         << "/" << setw(4) << p2.getBDay().yy << "      " << fixed
         << setprecision(2) << p2.getWeight();
}