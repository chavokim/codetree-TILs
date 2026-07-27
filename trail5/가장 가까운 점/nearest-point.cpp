#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

using pii = pair<int, int>;

struct compare {
    bool operator()(const pii& a, const pii& b) {
        if(a.first + a.second != b.first + b.second) {
            return a.first + a.second > b.first + b.second;
        }

        if(a.first != b.first) {
            return a.first > b.first;
        }

        return a.second > b.second;
    }
};

priority_queue<pii, vector<pii>, compare> pq;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pq.push(make_pair(x, y));
    }

    for(int i = 0; i < m; i++) {
        pii p = pq.top();
        pq.pop();

        pq.push(make_pair(p.first + 2, p.second + 2));
    }

    pii p = pq.top();
    cout << p.first << " " << p.second;

    return 0;
}