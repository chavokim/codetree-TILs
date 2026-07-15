#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> s;
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string q;
        cin >> q;

        if(q == "add") {
            int t;
            cin >> t;
            s.insert(t);
        }

        if(q == "remove") {
            int t;
            cin >> t;
            s.erase(t);
        }

        if(q == "find") {
            int t;
            cin >> t;
            cout << ((s.find(t) != s.end()) ? "true" : "false") << endl;
        }

        if(q == "lower_bound") {
            int t;
            cin >> t;
            if(s.lower_bound(t) == s.end()) {
                cout << "None" << endl;
            } else {
                cout << *s.lower_bound(t) << endl;
            }
        }

        if(q == "upper_bound") {
            int t;
            cin >> t;
            if(s.upper_bound(t) == s.end()) {
                cout << "None" << endl;
            } else {
                cout << *s.upper_bound(t) << endl;
            }
        }

        if(q == "largest") {
            if((int)s.size() == 0) {
                cout << "None" << endl;
            } else {
                cout << *s.rbegin() << endl;
            }
        }

        if(q == "smallest") {
            if((int)s.size() == 0) {
                cout << "None" << endl;
            } else {
                cout << *s.begin() << endl;
            }
        }
    }

    return 0;
}