#include <iostream>
#include <utility>
#include <set>

using namespace std;

set<pair<int, int> > s;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(make_pair(x, y));
    }

    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        auto it = s.lower_bound(make_pair(x, 0));

        if(it == s.end()) {
            cout << -1 << " " << -1 << endl;
        } else {
            auto p = *it;
            cout << p.first << " " << p.second << endl;
            s.erase(p);
        }
    }

    return 0;
}