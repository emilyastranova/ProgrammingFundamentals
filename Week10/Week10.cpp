#include <iostream>
using namespace std;

int stoi(char a[])
{
    int i = 0, sum = 0;

    while (a[i])
        sum = sum * 10 + a[i++] - '0';

    return sum;
}

void reverse(char* str, int len) {
  for(int i=0; i<len/2; i++) {
    char temp=str[i];
    str[i]=str[len-i-1];
    str[len-i-1]=temp;
  }
}

void itos(int x, char y[])
{
    int i = 0;
    int length = 0;

    while (x > 0)
    {
        y[i++] = x % 10 + '0';
        x = x / 10;
        length++;
    }
    y[i] = '\0'; // This line is a must
    
    for(int i=0; i<length/2; i++) { // Reverse the char array
        char temp=y[i];
        y[i]=y[length-i-1];
        y[length-i-1]=temp;
  }
}

int main()
{
    char x[20], y[20], more;
    int ans;

    do
    {
        cout << "\n\t\tInput a digit string: ";
        cin >> x;
        ans = stoi(x);
        cout << "\n\t\tThe integer is " << ans;
        itos (ans, y);
        cout << "\n\t\tThe digitis is " << y;
        cout << "\n\t\t\tDo more (Y/N) ?";
        cin >> more;

    } while (more == 'y' || more == 'Y');
}