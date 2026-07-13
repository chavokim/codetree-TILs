#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, int> um;
string s;

void answer() {
    for(char c: s) {
        if(um[c] == 1) {
            cout << c;
            return;
        }
    }

    cout << "None";
}

int main() {
    cin >> s;

    for (char c : s) {
        um[c]++;
    }

    answer();
    
    return 0;
}