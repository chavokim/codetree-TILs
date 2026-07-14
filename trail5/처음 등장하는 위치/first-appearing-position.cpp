#include <iostream>
#include <map>
using namespace std;

map<int, int> m;
int n;

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if(m.find(t) == m.end())
            m[t] = i;
    }

    for(const auto& [k, v]: m) {
        cout << k << " " << v << endl;
    }

    return 0;
}