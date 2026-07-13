#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, int> um;

int n, k;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        um[t]++;
    }

    // 1. Copy elements to a vector of pairs
    vector<pair<int, int>> vec(um.begin(), um.end());

    // 2. Sort using a lambda expression
    sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first > b.first; // Secondary sort: alphabetically by key if values match
        }
        return a.second > b.second;   // Primary sort: descending order of values
    });

    for(int i = 0; i < k; i++) {
        cout << vec[i].first << " ";
    }

    return 0;
}