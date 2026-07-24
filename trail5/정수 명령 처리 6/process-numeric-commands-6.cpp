#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue<int> pq;

int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        string q;
        cin >> q;

        if(q == "size") {
            cout << pq.size() << endl; 
        }

        if(q == "empty") {
            cout << (pq.empty() ? 1 : 0) << endl;
        }

        if(q == "top") {
            cout << pq.top() << endl;
        }

        if(q == "pop") {
            cout << pq.top() << endl;
            pq.pop();
        }

        if(q == "push") {
            int tmp;
            cin >> tmp;
            pq.push(tmp);
        }
    }

    return 0;
}