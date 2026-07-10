#include <iostream>
#include <unordered_map>

#define MAX_N 5000

using namespace std;

unordered_map<int, int> cnt;

int n, m;
int arr[MAX_N + 1];

int ans;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for(int i = 0; i < n; i++) {
        cnt[arr[i]]--;
        
        for (int j = 0; j < i; j++) {
            auto freq = cnt.find(m - (arr[i] + arr[j]));
            if (freq != cnt.end()) {
                ans += freq->second;
            }
        }
    }

    cout << ans;

    return 0;
}