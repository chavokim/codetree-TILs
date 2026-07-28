#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int enter_time[100001];
int duration[100001];
vector<pair<int, int>> que;

priority_queue<int> pq;

int curr_time = 0;
int past_idx = 0;

int ans;

int n;

void enter() {
    int idx = pq.top() * -1;
    pq.pop();
    ans = max(ans, curr_time - enter_time[idx]);
    curr_time += duration[idx];
}

void check_available() {
    if(past_idx == n) {
        return;
    }

    if(curr_time < que[past_idx].first && pq.size() == 0)
        curr_time = que[past_idx].first;

    for(int i = past_idx; i <= n; i++) {
        if(i == n) {
            past_idx = n;
            break;
        }

        if(curr_time < que[i].first) {
            past_idx = i;
            break;
        }

        pq.push(que[i].second * -1);
    }
}

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int ti, dur;
        cin >> ti >> dur;
        enter_time[i] = ti;
        duration[i] = dur;
        que.push_back(make_pair(ti, i));
    }

    sort(que.begin(), que.end());

    while(past_idx < n || pq.size() != 0) {
        check_available();
        enter();
    } 

    cout << ans;

    return 0;
}