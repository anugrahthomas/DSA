#include <iostream>
using namespace std;



// Enter the number: 5
// *****
// ****
// ***
// **
// *

void printPattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++) // also j=0; j<n-i+1; j++
        {
            cout << "*";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printPattern(n);
}