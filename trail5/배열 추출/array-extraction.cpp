#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> pq;

int n;

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

            cout << pq.top() << endl;
            pq.pop();
        } else {
            pq.push(tmp);
        }
    }

    return 0;
}