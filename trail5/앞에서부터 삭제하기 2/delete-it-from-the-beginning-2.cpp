#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

priority_queue<int> pq;

int arr[100001];

float ans;
int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    float sum;

    for(int i = 0; i < n; i++) {
        int tar = arr[n - 1 - i];

        pq.push(tar * -1);
        sum += tar;

        if(i > 1) {
            int ex = pq.top() * -1;
            ans = max((sum - ex) / i, ans);
        }
    }

    cout << fixed << setprecision(2) << ans;

    return 0;
}