#include <iostream>
#include <unordered_map>

using namespace std;

int n, m;

int main() {
    unordered_map<int, int> um;

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        um[t]++;
    }

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << um[t] << " ";
    }

    return 0;
}