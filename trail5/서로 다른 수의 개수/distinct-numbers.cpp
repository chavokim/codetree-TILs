#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;
int n;
int ans;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if(s.find(t) == s.end()) {
            ans++;
        }

        s.insert(t);
    }

    cout << ans;

    return 0;
}