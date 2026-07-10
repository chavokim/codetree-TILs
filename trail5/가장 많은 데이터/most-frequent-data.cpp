#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n;
int ans;

int main() {
    unordered_map<string, int> um;

    cin >> n;

    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        um[t]++;
        ans = max(um[t], ans);
    }

    cout << ans;

    return 0;
}