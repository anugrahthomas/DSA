#include <iostream>
#include <string>
using namespace std;

bool recurrsion(string &str, int i) {
    if(i >= str.length()) return true;
    if(str[i] != str[str.length()-i-1]) return false;

    return recurrsion(str, i+1);
}

bool isPalindrome(string &str) {
    return recurrsion(str, 0);
}

int main() {
    string str = "madam"; // racecar, anna, 
    
    if(isPalindrome(str)) {
        cout << str << " is palindrome" << endl;
    }else {
        cout << str << " is not palindrome" << endl;
    }
    return 0;
}