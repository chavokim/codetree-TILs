#include <iostream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

map<string, int> m;
int n;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        m[t]++;
    }

    cout << fixed << setprecision(4);

    for(const auto& [k, v]: m) {
        cout << k << " " << ((float)v / (float)n) * 100 << endl;
    }

    return 0;
}