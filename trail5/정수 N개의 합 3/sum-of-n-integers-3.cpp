#include <iostream>
using namespace std;

int n, k;

int arr[501][501];
int pf[501][501];

int main() {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pf[i][j] = pf[i-1][j] + pf[i][j-1] - pf[i-1][j-1] + arr[i][j];
        }
    }

    int ans = 0;

    for(int i = 0; i <= n - k; i++) {
        for(int j = 0; j <= n - k; j++) {
            ans = max(ans, pf[i+k][j+k] - pf[i][j+k] - pf[i+k][j] + pf[i][j]);            
        }
    }

    cout << ans;
    
    return 0;
}