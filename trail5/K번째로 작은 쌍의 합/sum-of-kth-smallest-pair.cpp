#include <iostream>
#include <queue>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

int a_arr[100001];
int b_arr[100001];

priority_queue<int> ans_up;

priority_queue<int> a;
priority_queue<int> b;

int n, m, k;
int cnt;

int ans = INT_MAX;

void insert(int num) {
    if(cnt < k) {
        ans_up.push(num);
        cnt++;
    } else {
        int l = ans_up.top();

        if(l > num) {
            ans_up.pop();
            ans_up.push(num);
        }
    }
}

int main() {
    cin >> n >> m >> k;

    for(int i = 0; i < n; i++) {
        cin >> a_arr[i];
        a.push(a_arr[i] * -1);
    }

    for(int i = 0; i < m; i++) {
        cin >> b_arr[i];
        b.push(b_arr[i] * -1);
    }

    bool cont = true;

    while(cont) {
        if(!a.size() || !b.size()) {
            break;
        }

        int a_top = a.top() * -1;
        int b_top = b.top() * -1;

        a.pop(); b.pop();

        if(a_top + b_top > ans) {
            break;
        }

        insert(a_top + b_top);

        for(int i = 0; i < n; i++) {
            if(a_arr[i] <= a_top) {
                continue;
            }

            insert(b_top + a_arr[i]);
        }

        for(int i = 0; i < m; i++) {
            if(b_arr[i] <= b_top) {
                continue;
            }

            insert(a_top + b_arr[i]);
        }

        ans = ans_up.top();
    }

    cout << ans;

    return 0;
}