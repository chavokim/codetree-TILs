#include <iostream>
#include <set>

using namespace std;

int n;

int main() {
    cin >> n;

    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        set<int> s;
        for(int j = 0; j < t; j++) {
            char q; 
            int tmp;
            cin >> q >> tmp;

            if(q == 'I') {
                s.insert(tmp);
                continue;
            }

            if((int)s.size() == 0) {
                continue;
            }

            if(tmp == 1) {
                s.erase(*s.rbegin());
            }

            if(tmp == -1) {
                s.erase(*s.begin());
            }
        }

        if((int)s.size() > 0) {
            cout << *s.rbegin() << " " << *s.begin() << endl;
        } else {
            cout << "EMPTY" << endl;
        }
    }

    return 0;
}