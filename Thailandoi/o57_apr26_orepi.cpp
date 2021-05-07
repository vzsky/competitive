// 85 pts probably wrong judge
#include<bits/stdc++.h>
using namespace std;

long long a[40100], dp[105][40100], qs[40100];
long long cost (int i, int j) { return (qs[j]-qs[i-1]) * (j-i+1); }

void solve (int i, int l, int r, int mn, int mx) {
  if (l > r) return;
  int mid = (l+r)/2, s;
  dp[i][mid] = 1e18;
  for (int k = mn; k <= min(mx, mid-1); k++) {
    int now = dp[i-1][k]+cost(k+1, mid);
    if (now < dp[i][mid]) {
      dp[i][mid] = now; s = k;
    }
  }
  solve(i, l, mid-1, mn, s); solve(i, mid+1, r, s, mx);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m; m++;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) qs[i] = qs[i-1]+a[i];
  for (int i = 1; i <= n; i++) dp[1][i] = cost(1, i);
  for (int i = 2; i <= m; i++) solve(i, i, n, i, n);
  cout << dp[m][n];
  return 0;
}