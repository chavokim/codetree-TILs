#include <iostream>
#include <climits>

#define MAX_NUM 1000000

using namespace std;

int n, q;

int arr[MAX_NUM + 2];
int pf[MAX_NUM + 2];

int main() {
    cin >> n >> q;

    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        arr[tmp + 1] = 1;
    }

    for(int i = 0; i < MAX_NUM + 2; i++) {
        pf[i+1] = pf[i] + arr[i];
    }

    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;

        cout << pf[b + 1 + 1] - pf[a + 1] << endl;
    }

    return 0;
}