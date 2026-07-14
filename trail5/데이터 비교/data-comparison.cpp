#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> s;
int n, m;

int main() {
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        s.insert(t);
    }

    cin >> m;

    for(int i = 0; i < m; i++) {
        int t;
        cin >> t;
        cout << ((s.find(t) != s.end()) ? 1 : 0) << " ";
    }

    return 0;
}