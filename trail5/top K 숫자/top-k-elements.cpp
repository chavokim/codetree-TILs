#include <iostream>
#include <set>
using namespace std;

int n, k;
set<int> s;

int main() {
    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        s.insert(tmp);
    }

    for(int i = 0; i < k; i++) {
        auto it = prev(s.end());
        cout << *it << " ";
        
        s.erase(it);
    }

    return 0;
}