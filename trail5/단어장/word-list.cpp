#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> m;
int n;

int main() {
    cin >> n;

    for(int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        m[t]++;
    }

    for(const auto& [k, v]: m) {
        cout << k << " " << v << endl;
    }

    return 0;
}