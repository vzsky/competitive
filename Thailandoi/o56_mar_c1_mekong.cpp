#include<bits/stdc++.h>
using namespace std;

int c[410][410], dp[51][410][410], v[410];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, l, d, k; cin >> n >> m >> l >> d >> k;
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j < n; j++) { cin >> c[i][j]; c[i][j] = v[j]-c[i][j]; }
  }

  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= m; j++) {
      for (int a = 0; a < n; a++) {
        dp[i][j][a] = max(dp[i][j][a], dp[i][j-1][a]);
        dp[i][j][a] = max(dp[i][j][a], dp[i][j][a-1]);
        dp[i][j][a] = max(dp[i][j][a], dp[i-1][j][a]);
        if (j-d-1 >= 1 and a-k-1 >= 0)
        dp[i][j][a] = max(dp[i][j][a], dp[i-1][j-d-1][a-k-1] + c[j][a]);
        dp[i][j][a] = max(dp[i][j][a], c[j][a]);
      }
    }
  }
  cout << dp[l][m][n-1] << endl;

  return 0;
}
