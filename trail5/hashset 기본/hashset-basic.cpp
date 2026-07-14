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
            string ret = (s.find(a) != s.end()) ? "true" : "false";
            cout << ret << endl;
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