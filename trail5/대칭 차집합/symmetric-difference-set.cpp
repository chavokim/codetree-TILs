#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
unordered_set<int> us;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        us.insert(tmp);    
    }

    int ans = n;

    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        if(us.find(tmp) == us.end()) {
            ans += 1;
        } else {
            ans -= 1;
        }
    }

    cout << ans;

    return 0;
}