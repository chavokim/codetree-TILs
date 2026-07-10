#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;

unordered_map<int, int> um;
int list[100001];

int ans;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        um[t]++;
        list[i] = t;
    }

    for(int i =0; i < n;i++) {
        if (2 * list[i] == m) {
            ans += um[list[i]] * (um[list[i]] - 1) / 2;
        } else {
            ans += um[list[i]] * um[m - list[i]];
        }
        
        um[list[i]] = 0;
        um[m-list[i]] = 0;
    }

    cout << ans;

    return 0;
}