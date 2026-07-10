#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> intmap;
unordered_map<int, string> stringmap;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        string c;
        cin >> c;
        intmap[c] = i;
        stringmap[i] = c;
    }

    for(int i = 0; i < m; i++) {
        string t;
        cin >> t;

        if(t[0] >= 'a' && t[0] <= 'z') {
            cout << intmap[t] << endl;
        } else {
            int a = stoi(t);
            cout << stringmap[a] << endl;
        }
    }

    return 0;
}