#include<bits/stdc++.h>
using namespace std;

long long a[300100], b[300100];
long long del[300300];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        long long bul = __LONG_LONG_MAX__;

        long long sum = 0;
        del[0] = a[0]-b[n-1];
        del[0] = del[0]<0?0:del[0];
        sum += del[0];
        for (int i = 1; i < n; i++) {
            del[i] = a[i]-b[i-1];
            del[i] = del[i]<0?0:del[i];
            sum += del[i];
        }

        for (int i = 0; i < n; i++) {
            bul = min(a[i]-del[i]+sum, bul);
        }

        cout << bul << '\n';

    }
    return 0;
}