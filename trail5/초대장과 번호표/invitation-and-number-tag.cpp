#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

#define MAX_G 250000

using namespace std;

unordered_set<int> us;
vector<int> arr[MAX_G + 1];

bool visited[MAX_G + 1];

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;

        for(int j = 0; j < tmp; j++) {
            int tmp2;
            cin >> tmp2;
            arr[i].push_back(tmp2);
        }
    }

    us.insert(1);
    bool success = true;

    while(success) {
        success = false;

        for(int i = 0; i < m; i++) {
            if(visited[i] || (int) arr[i].size() > (int)us.size() + 1) {
                continue;
            }

            int uninvited = 0;
            int cnt = 0;

            for(int j = 0; j < arr[i].size(); j++) {
                if(us.find(arr[i][j]) == us.end()) {
                    cnt++;
                    uninvited = arr[i][j];
                }
            }

            if(cnt == 1) {
                us.insert(uninvited);
            
                visited[i] = true;
                success = true;
            }
        }
    }

    // vector<int> sortedVec(us.begin(), us.end());

    // sort(sortedVec.begin(), sortedVec.end());

    // for (int num : sortedVec) {
    //     cout << num << " ";
    // }
    // cout << endl;

    cout << us.size();

    return 0;
}