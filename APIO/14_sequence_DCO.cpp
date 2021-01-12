#include<bits/stdc++.h>
using namespace std;

int a[100100];
long long s[100100], dp[2][100100];
int mxk[200][100100];

void solve (int i, int l, int r, int kmin, int kmax, int I) {
    if (r < l) return;
    int mid = (l+r)/2, m = -1;
    for (int k = kmin; k <= min(kmax, mid-1); k++) {
        long long nw = dp[i^1][k] + (s[mid]-s[k])*(s[k]-s[0]);
        if (nw >= dp[i][mid]) {
            dp[i][mid] = nw;
            m = k;
        }
    }
    mxk[I][mid] = m;
    solve(i, l, mid-1, kmin, m, I); solve(i, mid+1, r, m, kmax, I);
}

int main(){
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i-1]+a[i];
    for (int i = 1; i <= k; i++) solve(i%2, 1, n, 1, n-1, i);
    printf("%lld\n", dp[k%2][n]);
    for (int i = k, x = n; i > 0; i--) printf("%d ", x = mxk[i][x]);
    return 0;
}
// 7 3 4 1 3 4 0 2 3