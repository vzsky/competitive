#include<bits/stdc++.h>
using namespace std;

char ans[110][110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n&1 and m&1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ((i+j)&1?'W':'B');
                } cout << endl;
            }
        }
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    ans[i][j] =  ((i+j)&1?'B':'W');
                }
            }
            ans[0][0] = ans[1][0] = ans[0][1] = 'B';
            ans[1][1] = 'W';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    cout << ans[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}