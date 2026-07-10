#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n;

int main() {
    unordered_map<int, int> m;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s == "add") {
            int a, b;
            cin >> a >> b;
            m[a] = b;
        } else if(s == "find") {
            int a;
            cin >> a;
            if(m[a]){
                cout << m[a] << endl;
            } else {
                cout << "None" << endl;
            }
        } else {
            int a;
            cin >> a;
            m.erase(a);
        }
    }

    return 0;
}