#include <iostream>
#include <climits>

using namespace std;

int n, k, b;

int arr[100002];
int pf[100002];

int main() {
    cin >> n >> k >> b;

    for(int i = 0; i < b; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp] = 1;
    }

    for(int i = 1; i < n + 1; i++) {
        pf[i+1] = pf[i] + arr[i];
    }

    int ans = INT_MAX;

    for(int i = 1; i <= n - k + 1; i++) {
        ans = min(ans, pf[i+k] - pf[i]);
    }

    cout << ans;

    return 0;
}