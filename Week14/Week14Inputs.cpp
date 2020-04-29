//Name: Tyler Harrison

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

void print(ostream x, ostream y, const string &str)
{
    x << str;
    y << str;
}

int main()
{
    ofstream outFile("Week14Inputs.out");
    cout << setprecision(3) << fixed;

    Person test("Test","0", "0", {0,0,0}, 0.0); //Initiazlized

    char more = 'y';
    char buff ;
    int i = 0;
    outFile << "\n\n\t\tAll output were saved in disk file!!\n\n";
    outFile << "\n" << "       Name" << "\t\t Phone" << "         Height" << "\t B-Date"
            << "\t       Weight";
    do
    {

        string name;
        cout << "Name: ";
        getline(cin, name);

        string phone;
        cout << "Phone: ";
        getline(cin, phone);

        struct date BDay;
        cout << "BDay: ";
        cin >> BDay.mm >> buff >> BDay.dd >> buff >> BDay.yy;

        string height;
        cout << "Height: ";
        cin >> height;

        int weight;
        cout << "Weight: ";
        cin >> weight;

        test = Person(name, phone, height, BDay, weight);
        i++;

        outFile << "\n    " << setw(15) << left << test.getName() << "   "
         << test.getPhone() << " " << setw(9) << right << test.getHeight() << "   "
         << setw(2) << test.getBDay().mm << "/" << setw(2) << test.getBDay().dd
         << "/" << setw(4) << test.getBDay().yy << "      " << fixed
         << setprecision(2) << test.getWeight();

        cout << "\nInput a new person (Y/N) ? ";
        cin >> more;
        cin.ignore(256, '\n');
    } while (more == 'Y' || more == 'y');
    
    outFile << "\n\n\t\t\tProgramming is FUN!  It is done by Tyler A. Harrison";
    outFile << "\n--------------------------------";
    outFile.close();
    ifstream f("Week14Inputs.out");

    if (f.is_open())
        cout << f.rdbuf();
    f.close();
}