#include <iostream>
#include <climits>
using namespace std;

int n;

#define MAX_N 300

int arr[MAX_N + 1][MAX_N + 1];
int pf[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1][MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n;

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

    int ans = INT_MIN;

    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            for(int y = 1; y <= n; y++) {
                dp[a][b][y] = max(dp[a][b][y-1], 0) + pf[b][y] - pf[a-1][y] - pf[b][y-1] + pf[a-1][y-1];
                ans = max(ans, dp[a][b][y]);
            }
        }
    }

    cout << ans;
    
    return 0;
}