#include<bits/stdc++.h>
using namespace std;

int ttw[110][110], tth[110][110], dp[2010][110][110];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, ans = 0; cin >> r >> c;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      int a; cin >> a;
      while (a % 2 == 0) { a/=2; ttw[i][j]++; }
      while (a % 3 == 0) { a/=3; tth[i][j]++; }
    }
  }
  for (int k = 0; k <= 2000; k++) for (int i = 0; i <= r; i++) for (int j = 0; j <= c; j++) {
    dp[k][i][j] = -1e9;
  }
  for (int i = 1; i <= r; i++) dp[0][i][0] = 0;
  for (int i = 1; i <= c; i++) dp[0][0][i] = 0;
  for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) for (int k = ttw[i][j]; k <= 2000; k++) {
    dp[k][i][j] = max(dp[k-ttw[i][j]][i-1][j],dp[k-ttw[i][j]][i][j-1]) + tth[i][j];
  } 
  for (int k = 0; k <= 2000; k++) ans = max(ans, min(k, dp[k][r][c]));
  cout << ans << endl;
  return 0;
}