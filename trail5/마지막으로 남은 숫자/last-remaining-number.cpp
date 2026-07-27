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
        pq.push(tmp);
    }

    while(pq.size() >= 2) {
        int top = pq.top();
        pq.pop();

        int top2 = pq.top();
        pq.pop();

        if(top != top2) {
            pq.push(top - top2);
        }
    }

    if(pq.size())
        cout << pq.top();
    else
        cout << -1;

    return 0;
}