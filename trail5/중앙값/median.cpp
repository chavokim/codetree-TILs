#include <iostream>
#include <queue>

using namespace std;

int t;

int main() {
    cin >> t;

    for(int i = 0; i < t; i++) {
        priority_queue<int> up;
        priority_queue<int> down;

        up.push(-100001);
        down.push(-1);

        int m, tmp;
        cin >> m >> tmp;

        cout << tmp << " ";
        up.push(tmp * -1);

        for(int j = 0; j < m / 2; j++) {
            int a, b;
            cin >> a >> b;
            
            int t = up.top() * -1;

            if(a > t) {
                up.pop();
                up.push(a * -1);
                down.push(t);
            } else {
                down.push(a);
            }

            int r = up.top() * -1;
            int l = down.top();

            if(b > r) {
                cout << r << " ";
                up.push(b * -1);
            } else if(l > b) {
                cout << l << " ";
                down.pop();
                down.push(b);
                up.push(l * -1);
            } else {
                cout << b << " ";
                up.push(b * -1);
            }
        }

        cout << endl;
    }

    return 0;
}