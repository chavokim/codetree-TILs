#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<int> s;
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string t;
        int a;
        cin >> t >> a;

        if(t == "find") {
            cout << ((s.find(a) != s.end()) ? "true" : "false") << endl;
        }

        if(t == "add") {
            s.insert(a);
        }

        if(t == "remove") {
            s.erase(a);
        }
    }

    return 0;
}