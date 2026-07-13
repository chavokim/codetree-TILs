#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_N 5000

int n;

unordered_map<int, int> um;

int arr[4][MAX_N+1];

int main() {
    cin >> n;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            um[arr[0][i] + arr[1][j]]++;
        }
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans += um[(arr[2][i] + arr[3][j]) * -1];
        }
    }

    cout << ans;

    return 0;
}

