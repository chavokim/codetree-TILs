#include <iostream>
#include <climits>

using namespace std;

#define MAX_N 100000

int arr[MAX_N + 1];
int prefix_sum[4][MAX_N + 1];

int n, q;

int main() {
    cin >> n >> q;
    
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    int sum[4];

    for(int i= 1; i <= 3; i++) {
        sum[i] = 0;
    }

    for(int j = 1; j <= n; j++) {
        sum[arr[j]]++;
        for(int i = 1; i <= 3; i++) {
            prefix_sum[i][j] = sum[i];
        }
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        for(int j = 1; j <= 3; j++) {
            cout << prefix_sum[j][b] - prefix_sum[j][a-1] << " ";
        }

        cout << endl;
    }

    return 0;
}
