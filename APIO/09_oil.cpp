#include<bits/stdc++.h>
using namespace std;

int tab[1510][1510], qs[1510][1510], dp[7][1510][1510];
int m, n, k, ans = 0;
int sum (int i, int j) { 
  if (i > m or j > n or i-k < 0 or j-k < 0) return -1e3;
  return qs[i][j]-qs[i-k][j]-qs[i][j-k]+qs[i-k][j-k]; 
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> m >> n >> k;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> tab[i][j];
      qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+tab[i][j];
    }
  }
  for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) 
    dp[1][i][j] = max(sum(i, j), max(dp[1][i-1][j], dp[1][i][j-1]));
  for (int i = m; i >= 1; i--) for (int j = 1; j <= n; j++)
    dp[2][i][j] = max(sum(i+k-1, j), max(dp[2][i+1][j], dp[2][i][j-1]));
  for (int i = 1; i <= m; i++) for (int j = n; j >= 1; j--)
    dp[3][i][j] = max(sum(i, j+k-1), max(dp[3][i-1][j], dp[3][i][j+1]));
  for (int i = m; i >= 1; i--) for (int j = n; j >= 1; j--) {
    dp[4][i][j] = max(sum(i+k-1, j+k-1), max(dp[4][i+1][j], dp[4][i][j+1]));
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) 
      dp[5][i][i] = max(dp[5][i][i], sum(i, j));
    for (int j = i+1; j <= m; j++) 
      dp[5][i][j] = max(dp[5][i][j], max(dp[5][i][j-1], dp[5][j][j]));
  }
  for (int i = 1; i <= n; i++) { 
    for (int j = 1; j <= m; j++) 
      dp[6][i][i] = max(dp[6][i][i], sum(j, i));
    for (int j = i+1; j <= n; j++) 
      dp[6][i][j] = max(dp[6][i][j], max(dp[6][i][j-1], dp[6][j][j]));
  }
  for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
    ans = max(ans, dp[1][i][n] + dp[2][i+1][j] + dp[4][i+1][j+1]);
    ans = max(ans, dp[1][i][j] + dp[3][i][j+1] + dp[2][i+1][n]);
    ans = max(ans, dp[1][m][j] + dp[3][i][j+1] + dp[4][i+1][j+1]);
    ans = max(ans, dp[1][i][j] + dp[2][i+1][j] + dp[3][m][j+1]);
  }
  for (int i = 1; i <= m; i++) for (int j = i+k+1; j <= m; j++)
    ans = max(ans, dp[1][i][n] + dp[2][j][n] + dp[5][i+k][j-1]);
  for (int i = 1; i <= n; i++) for (int j = i+k+1; j <= n; j++) 
    ans = max(ans, dp[1][m][i] + dp[3][m][j] + dp[6][i+k][j-1]);
  cout << ans << endl;
  return 0;
}
