#include<bits/stdc++.h>
using namespace std;

int a[310];
int dp[310][310];

int solve (int l, int r) {
  if (r < l) return 0;
  if (l == r) return a[l];
  if (dp[l][r] != 0) return dp[l][r];
  dp[l][r] = 1e9;
  for (int i = l; i <= r; i++) {
    dp[l][r] = min(dp[l][r], a[i] + max(solve(l, i-1), solve(i+1, r)));
  }
  return dp[l][r];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  cout << solve (1, n);
  return 0;
}