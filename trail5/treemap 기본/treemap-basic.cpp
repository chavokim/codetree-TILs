#include <iostream>
#include <map>
#include <string>

using namespace std;

map<int, int> m;
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if(s == "add") {
            int a, b;
            cin >> a >> b;
            m[a] = b;
        }

        if(s == "find") {
            int a;
            cin >> a;
            if(m.find(a) == m.end()) {
                cout << "None" << endl;
            } else {
                cout << m[a] << endl;
            }
        }

        if(s == "remove") {
            int a;
            cin >> a;
            m.erase(a);
        }

        if(s == "print_list") {
            if(m.size() == (int)0) {
                cout << "None" << endl;
                continue;
            }

            for(const auto& [key, value]: m) {
                cout << value << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}