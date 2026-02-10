#include <iostream>
using namespace std;


// Enter num: 5
// *
// **
// ***
// ****
// *****

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter num: ";
    cin >> n;
    printPattern(n);
}