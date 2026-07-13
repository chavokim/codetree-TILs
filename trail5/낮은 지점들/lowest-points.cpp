#include <iostream>
#include <unordered_map>

using namespace std;
using ll = long long int;

unordered_map<int, int> um;

int n;
ll ans;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if(um.count(x) > 0) {
            um[x] = min(um[x], y);
        } else {
            um[x] = y;
        }
    }

    // Read-only iteration over keys
    for (const auto& [key, value] : um) {
        ans += value;
    }

    cout << ans;

    return 0;
}