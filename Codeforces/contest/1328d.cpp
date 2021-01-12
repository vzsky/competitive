#include<bits/stdc++.h>
using namespace std;

int t[400100];
int k[400100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int c; cin >> c;
    while (c--) {

        memset(k, -1 ,sizeof k);
        int n; cin >> n;
        for (int i = 0;i < n ;i ++) {
            cin >> t[i];
            t[i+n] = t[i];
        }
        int ans = 1;
        int s = 0;
        for (int i = 1; i < n; i++) {
            if (t[i] == t[i-1]) {
                s = i;
                break;
            }
            s = 0;
        }
        k[s] = 0;
        for (int i = 1; i < n; i++) {
            if (t[i+s] == t[i-1+s]) k[i+s] = k[i-1+s];
            else { k[i+s] = k[i-1+s]^1; ans = 2; }
        }
        if (k[n-1+s] == k[s] and t[n-1+s] != t[s]) k[n-1+s] = 2, ans = 3;
        cout << ans << endl;
        for (int i = 0; i < n; i++) cout << max(k[i], k[i+n])+1 << ' '; cout << endl;
    }
    return 0;
}