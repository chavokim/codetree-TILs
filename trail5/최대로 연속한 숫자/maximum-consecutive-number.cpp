#include <iostream>
#include <set>
#include <utility>

using namespace std;

set<int> s;
set<pair<int, int> > ans;

void init(int end) {
    s.insert(-1);
    s.insert(end + 1);
    ans.insert(make_pair(end + 1, end + 1));
}

void remove(int t) {
    auto it = s.upper_bound(t);
    int end = *it;
    it--;
    int start = *it;

    int dist = end - start - 1;

    ans.erase(make_pair(dist, end));

    int dist1 = end - t - 1;
    if(dist1) {
        ans.insert(make_pair(dist1, end));
    }

    int dist2 = t - start - 1;
    if(dist2) {
        ans.insert(make_pair(dist2, t));
    }
    
    s.insert(t);

    auto p = *ans.rbegin();
    cout << p.first << endl;
}


int main() {
    int n, m;

    cin >> n >> m;

    init(n);

    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;

        remove(tmp);
    }

    return 0;
}