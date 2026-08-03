#include <iostream>
#include <climits>

using namespace std;

int arr[1001];
int prefix_sum[1001];

int n, k;

int main() {
    cin >> n >> k;
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        prefix_sum[i+1] = sum;
    }

    int ans = 0;

    for(int num = 1; num <= n; num++) {
        for(int i = 0; i <= n - num; i++) {
            if(prefix_sum[i + num] - prefix_sum[i] == k) {
                ans++;
            }
        }
    }

    cout << ans;
     
    return 0;
}
