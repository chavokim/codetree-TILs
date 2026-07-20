#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, m;
int ans;

int main() {
    cin >> n >> m;
    
    for(int i = 1; i <= m; i++) {
        s.insert(i * -1);
    }

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if(s.lower_bound(tmp * -1) == s.end()) {
            break;
        }

        s.erase(*s.lower_bound(tmp * -1));
        ans++;
    }

    cout << ans;

    return 0;
}