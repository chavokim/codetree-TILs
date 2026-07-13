#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<string, int> um;
int n;
int ans;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        um[s]++;
        ans = max(um[s], ans);
    }

    cout << ans;

    return 0;
}