#include <iostream>
#include <string>

#include <unordered_set>

#define MAX_N 500

using namespace std;

int n, m;

string string_arr[MAX_N * 2 + 1];
int selected[3];

int ans;

void debug() {
    for(int i = 0; i < 3; i++) {
        cout << selected[i];
    }
    cout << endl;
}

bool check() {
    unordered_set<string> us;

    for(int i = 0; i < n; i++) {
        string h;

        for(int j = 0; j < 3; j++) {
            h.push_back(string_arr[i][selected[j]]);
        }

        us.insert(h);
    }

    for(int i = n; i < 2*n; i++) {
        string h;

        for(int j = 0; j < 3; j++) {
            h.push_back(string_arr[i][selected[j]]);
        }

        if(us.find(h) != us.end()) {
            return false;
        }
    }

    return true;    
}

void dfs(int idx, int cnt) {
    if(cnt == 3) {
        if(check())
            ans++;

        return;
    }

    if(idx == m) {
        return;
    }

    selected[cnt] = idx;
    dfs(idx + 1, cnt + 1);

    dfs(idx + 1, cnt);
}

int main() {
    cin >> n >> m;
    
    for(int i = 0; i < n * 2; i++) {
        cin >> string_arr[i];
    }

    dfs(0, 0);

    cout << ans;
    
    return 0;
}