#include <iostream>
using namespace std;

#define MAX_N 400

int n, k;
int arr[MAX_N + 1][MAX_N + 1];
int dp[MAX_N * 2 + 1][MAX_N + 1][MAX_N + 1];

bool inRange(int x, int y) {
    return x >= 0 and y >= 0 and x < n and y < n;
}

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
            dp[0][i][j] = arr[i][j];
        }
    }

    int dp[3][MAX_N][MAX_N];

    // c = 0
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            dp[0][x][y] = arr[x][y];

    // c = 1 (십자 모양)
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++) {
            int ret = arr[x][y];
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (inRange(nx, ny)) ret += arr[nx][ny];
            }
            dp[1][x][y] = ret;
    }

    // c = 2 .. k
    for (int c = 2; c <= k; c++) {
        int cur = c % 3, p1 = (c - 1) % 3, p2 = (c - 2) % 3;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++) {
                int ret = 0, cnt = 0;
                if (y + 1 < n) { ret += dp[p1][x][y + 1]; cnt++; }
                if (y - 1 >= 0) { ret += dp[p1][x][y - 1]; cnt++; }
                if (cnt >= 2)   ret -= dp[p2][x][y];

                if (x - c >= 0)     ret += arr[x - c][y];
                if (x - c + 1 >= 0) ret += arr[x - c + 1][y];
                if (x + c < n)      ret += arr[x + c][y];
                if (x + c - 1 < n)  ret += arr[x + c - 1][y];

                dp[cur][x][y] = ret;
            }
    }

    int ans = 0;
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++)
            ans = max(ans, dp[k % 3][x][y]);

    cout << ans;
    
    return 0;
}