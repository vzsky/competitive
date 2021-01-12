#include<bits/stdc++.h>
using namespace std;

int a[110][110], b[110][110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ':' << ' ';
        int n; cin >> n;
        int trace = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                if (i == j) trace += a[i][j];
                b[j][i] = a[i][j];
            }
        }
        int r = 0, c = 0;
        
        for (int i = 0; i < n; i++) {
            sort(a[i], a[i]+n);
            sort(b[i], b[i]+n);
            for (int j = 1; j < n; j++) {
                if (a[i][j] == a[i][j-1]) {
                    r++;
                    break;
                }
            }
            for (int j = 1; j < n; j++) {
                if (b[i][j] == b[i][j-1]) {
                    c++;
                    break;
                }
            }
        }
        cout << trace << ' ' << r << ' ' << c << '\n';
    }
    return 0;
}