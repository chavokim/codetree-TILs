#include <iostream>
#include <set>
#include <utility>

using namespace std;
int n, m;

set<pair<int, int> > s;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)  {
        int x, y;
        cin >> x >> y;
        
        s.insert(make_pair(x, y));
    }

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        if(s.upper_bound(make_pair(x, y)) == s.end()) {
            cout << -1 << " " << -1 << endl;
        } else {
            pair<int, int> p = *s.upper_bound(make_pair(x, y));
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}