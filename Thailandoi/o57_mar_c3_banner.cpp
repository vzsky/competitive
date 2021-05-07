// This should be correct, but to get AC, use the commented incorrect part
// Conflicting case - 3 2 1 2 2 3 
#include<bits/stdc++.h>
using namespace std;

int a[310][310], dp[310][310];

int solve (int l, int r) {
  if (l == r) return 0;
  if (l+1 == r) return dp[l][r] = a[l][r];
  if (dp[l][r] != -1) return dp[l][r];
  int ans = 0;
  for (int k = l+1; k < r; k++) {
    ans = max(ans, solve(l, k)+solve(k, r)+a[l][r]);
  }
  // for (int k = l; k < r; k++) {
  //   ans = max(ans, solve(l, k)+solve(k+1, r)+a[l][r]);
  // }
  return dp[l][r] = ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    assert(x < y);
    a[x][y]++;
  }
  memset(dp, -1, sizeof dp);
  cout << m-solve(1, n);
  return 0;
}