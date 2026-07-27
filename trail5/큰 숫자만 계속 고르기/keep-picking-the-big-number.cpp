#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    for(int i = 0; i < m; i++) {
        int m = pq.top();
        pq.pop();
        pq.push(m-1);
    }
    
    cout << pq.top();

    return 0;
}