#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n, m;

int main() {
    cin >> n >> m;

    for(int i = 1; i <= m; i++) {
        s.insert(i);
    }

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.erase(tmp);
        cout << *s.rbegin() << endl;
    }

    return 0;
}