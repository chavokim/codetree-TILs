#include <iostream>
#include <set>
using namespace std;

set<int> s;
int n;

int ans = 1000000001;

int main() {
    s.insert(0);
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;

        auto it = s.upper_bound(tmp);

        if(it != s.end()){
            ans = min(ans, abs(tmp - *it));
        }

        it--;

        if(it != s.end()){
            ans = min(ans, abs(tmp - *it));
        }
        
        cout << ans << endl;
        s.insert(tmp);
    }

    return 0;
}