#include <iostream>
#include <set>
#include <utility>
#include <string>

using namespace std;

set<pair<int, int> > s;

int n, m;

int main() {
    cin >> n;

    for(int i= 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        s.insert(make_pair(b, a));
    }

    cin >> m;

    for(int i= 0 ; i<m; i++) {
        string q;

        cin >> q;

        if(q == "rc") {
            int t;

            cin >> t;

            if(t == 1) {
                auto p = *s.rbegin();
                cout << p.second << endl;
            } else {
                auto p = *s.begin();
                cout << p.second << endl;
            }
        }

        if(q == "ad") {
            int a, b;

            cin >> a >> b;
            s.insert(make_pair(b, a));
        }

        if(q == "sv") {
            int a, b;

            cin >> a >> b;
            s.erase(make_pair(b, a));
        }
    }
    
    return 0;
}