#include <iostream>
using namespace std;

#define MAX_NUM 1000

int n, m, k;

char arr[MAX_NUM + 1][MAX_NUM + 1];
int pf[3][MAX_NUM + 1][MAX_NUM + 1];

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int k = 0; k < 3; k++){
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int isChar = arr[i][j] == 'a' + k ? 1 : 0;
                pf[k][i][j] = pf[k][i-1][j] + pf[k][i][j-1] - pf[k][i-1][j-1] + isChar;
            }
        }
    }

    for(int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for(int k = 0; k < 3; k++){
            cout << pf[k][c][d] - pf[k][a-1][d] - pf[k][c][b-1] + pf[k][a-1][b-1] << " ";
        }

        cout << endl;
    }

    return 0;
}