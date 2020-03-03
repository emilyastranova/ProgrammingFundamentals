#include <iostream>
using namespace std;


int amount;

int main(){

    cout << "Input the amount: ";
    cin >> amount;
    int nums[amount];

    cout << "Fibonacci Sequence" << endl;

    for(int x = 0; x < amount; x++){

        if(x > 1){  // Fill nums[x] with the summation of the previous 2 values
            nums[x] = nums[x-1] + nums[x-2];
        }
        else{   // Fill first two with 1
            nums[x] = 1;
        }
        
        cout << nums[x] << " "; // Print the current number followed by a space

    }

    return 0;
}