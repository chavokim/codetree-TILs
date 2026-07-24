#include <iostream>
#include <set>
using namespace std;

set<int> s;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        s.insert(tmp * -1);
    }

    for(int i= 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        auto it = s.lower_bound(tmp * -1);

        if(it == s.end()) {
            cout << -1 << endl;
        } else {
            int p = (*it) * -1;
            cout << p << endl;
            s.erase(p * -1);
        }
    }

    return 0;
}