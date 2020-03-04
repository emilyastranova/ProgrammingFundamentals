#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main(){

    cout << setprecision(2) << fixed;

    double list[] = {100.0, 200.0, 300.0};
    for (auto num : list)
        cout << num << " ";

    cout << endl << strlen("Tyler") << endl;

}