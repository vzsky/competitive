#include<bits/stdc++.h>
using namespace std;

long long a[2][100100], h[2][100100];
long long cal[2][100100];
long long idx[2][100100];

long long b (int i, int j) { return a[0][i] + a[1][j] - abs(h[0][i]-h[1][j]); }

int main(){
    int n;
    scanf("%d", &n);
    a[0][0] = a[0][n+1] = a[1][0] = a[1][n+1] = -2e9;
    cal[0][0] = cal[1][n+1] = -2e9;
    idx[1][n+1] = n+1;
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &h[0][i], &a[0][i]);
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &h[1][i], &a[1][i]);
    for(int i = 1; i <= n; i++) cal[0][i] = a[1][i]+h[1][i];
    for(int i = n; i >= 1; i--) cal[1][i] = a[1][i]-h[1][i];
    for(int i = 1; i <= n; i++) idx[0][i] = cal[0][idx[0][i-1]]>cal[0][i]? idx[0][i-1] : i;
    for(int i = n; i >= 1; i--) idx[1][i] = cal[1][idx[1][i+1]]>cal[1][i]? idx[1][i+1] : i;

    for(int i = 1; i <= n; i++) {
        int id = lower_bound(h[1]+1, h[1]+n+1, h[0][i])-&h[1][1];
        // cerr << id << ' ' << idx[1][id] << ' ' << b(i, idx[1][id]) << ' ' << idx[0][id-1] << ' ' << b(i, idx[0][id-1]) << endl;
        printf("%lld\n", max(b(i, idx[1][id+1]), b(i, idx[0][id])));
    }
    return 0;
}