#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(tmp == 0) {
            if(pq.size() == 0) {
                cout << 0 << endl;
                continue;
            }
            int a = pq.top();
            pq.pop();
            cout << a * -1 << endl;
        } else {
            pq.push(tmp * -1);
        }
    }

    return 0;
}