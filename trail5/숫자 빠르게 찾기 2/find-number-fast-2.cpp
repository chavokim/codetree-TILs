#include <iostream>
#include <set>

int n, m;

using namespace std;

set<int> s;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        
        if(s.lower_bound(t) != s.end()) {
            cout << *s.lower_bound(t) << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}