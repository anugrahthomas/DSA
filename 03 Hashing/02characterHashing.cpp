// there are only 256 ascii characters so we can make array of size 256 if there is both uppercase and lowercase characters if only lowercase or uppercase we can make 26 logic

#include <iostream>
#include <string>
using namespace std;


// Enter String: anugrah
// key: a value: 2
// key: g value: 1
// key: h value: 1
// key: n value: 1
// key: r value: 1
// key: u value: 1

int main(){
    string str;
    int hashTable[26] = {0};
    int n = sizeof(hashTable) / sizeof(hashTable[0]);

    cout << "Enter String: ";
    getline(cin, str);

    for(int i=0; i<str.length(); i++){
        int temp = (int)str[i] - 97;
        hashTable[temp]++;
    }

    for(int i=0; i<n; i++){
        char ch = i + 97;
        if(hashTable[i] == 0) continue;
        cout << "key: " << ch << " value: " << hashTable[i] << endl;
    }
}