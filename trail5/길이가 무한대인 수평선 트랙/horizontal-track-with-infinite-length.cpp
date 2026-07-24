#include <iostream>
#include <utility>

#include <set>

using namespace std;

using ll = long long int;

int n, t;
set<ll> s;

int main() {
    cin >> n >> t;

    for(int i = 0; i < n; i++) {
        ll start, velo;
        cin >> start >> velo;

        ll point = start + velo * t;

        while(s.lower_bound(point) != s.end()) {
            ll p = *s.lower_bound(point);
            s.erase(p);
        }

        s.insert(point);
    }

    cout << s.size();
    

    return 0;
}