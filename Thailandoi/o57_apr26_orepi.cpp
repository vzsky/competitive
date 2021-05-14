#include<bits/stdc++.h>
using namespace std;

long long a[40100], dp[105][40100], qs[40100];
long long cost (int i, int j) { return (qs[j]-qs[i-1]) * (j-i+1); }

void solve (int i, int l, int r, int mn, int mx) {
  if (l > r) return;
  int mid = (l+r)/2, s;
  dp[i][mid] = 9e18;
  for (int k = mn; k <= min(mx, mid); k++) {
    long long now = dp[i-1][k-1]+cost(k, mid);
    if (now < dp[i][mid]) { dp[i][mid] = now; s = k; }
  }
  solve(i, l, mid-1, mn, s); solve(i, mid+1, r, s, mx);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m; m++;
  if (m > n) m = n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) qs[i] = qs[i-1]+a[i];
  for (int i = 1; i <= n; i++) dp[1][i] = cost(1, i);
  for (int i = 2; i <= m; i++) solve(i, i, n, i, n);
  cout << dp[m][n];
  return 0;
}