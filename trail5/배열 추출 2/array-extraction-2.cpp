#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        if(abs(a) != abs(b)) {
            return abs(a) > abs(b);
        }

        return a > b;
    }
};

priority_queue<int, vector<int>, compare> pq;

int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        if(tmp != 0)
            pq.push(tmp);
        else {
            if(pq.size() == 0) {
                cout << 0 << endl;
                continue;
            }

            int ans = pq.top();
            pq.pop();
            cout << ans << endl;
        }

    }

    return 0;
}