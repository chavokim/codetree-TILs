#include <iostream> 
#include <unordered_set>

using namespace std;

#define MAX_N 100000

unordered_set<int> s[MAX_N+1];
int n, k;

int arr[MAX_N+1][2];
int seat[MAX_N + 1];

void sit(int person, int pos) {
    s[person].insert(pos);
    seat[pos] = person;
    // cout << person << " " << pos << endl;
}

int main() {
    cin >> n >> k;

    for(int i = 0; i < k; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    for(int i = 1; i <= n; i++) {
        sit(i, i);
    }

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < k; j++) {
            int tmp = seat[arr[j][1]];
            sit(seat[arr[j][0]], arr[j][1]);
            sit(tmp, arr[j][0]);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << (int)s[i].size() << endl;
    }

    return 0;
}