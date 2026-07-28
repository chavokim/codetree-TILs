#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long> pq;

int main() {
    int n;
 
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp * -1);

        if(pq.size() < 3) {
            cout << -1 << endl;
        } else {
            long long ans = 1;
            long long tmp[3];
            for(int i = 0; i < 3; i++) {
                tmp[i] = pq.top();
                pq.pop();
                ans *= tmp[i] * -1;
            }
            cout << ans << endl;
            for(int i = 0; i < 3; i++) {
                pq.push(tmp[i]);
            }
        }
    }

    return 0;
}