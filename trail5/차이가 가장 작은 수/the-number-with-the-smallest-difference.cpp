#include <iostream>
#include <set>
#include <climits>

using namespace std;

int n, m;
set<int> s;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) { 
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    int ans = INT_MAX;

    for(const auto& v: s) {
        auto it = s.lower_bound(v + m);

        if(it != s.end()) {
            ans = min(*it - v, ans);
        }
    }

    if(ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans;
    }

    return 0;
}