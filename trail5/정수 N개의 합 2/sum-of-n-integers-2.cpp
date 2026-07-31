#include <iostream>
#include <climits>

using namespace std;

int arr[100001];
int prefix_sum[100001];

int n, k;

int main() {
    cin >> n >> k;
    
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        prefix_sum[i+1] = sum;
    }

    int ans = INT_MIN;

    for(int i = 0; i <= n - k; i++) {
        ans = max(ans, prefix_sum[i + k] - prefix_sum[i]);
    }

    cout << ans;
     
    return 0;
}
