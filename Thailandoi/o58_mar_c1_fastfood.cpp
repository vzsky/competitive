#include<bits/stdc++.h>
using namespace std;

int a[55][3010], dp[52][52][4][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, ans = -1; cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
  for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) for (int s = 0; s < 4; s++) dp[i][j][s][1] = -1e9;
  dp[0][n-1][0][1] = dp[n-1][0][0][1] = a[0][1] + a[n-1][1];

  for (int i = 2, ind = 0; i <= m; i++, ind^=1) {
    for (int j = 0; j < n; j++) for (int k = 0; k < n; k++) {
      for (int s = 0; s < 4; s++) dp[j][k][s][ind] = -1e9;
      int cost = (j==k) ? a[j][i] : a[j][i]+a[k][i];
      for (int x = -1; x <= 1; x++) for (int y = -1; y <= 1; y++) {
        if (j+x < 0 or k+y < 0 or j+x >= n or k+y >= n) continue;
        if (x == 0 and y == 0) {
          dp[j][k][3][ind] = max(dp[j][k][3][ind], dp[j][k][0][!ind]);
        }
        else if (x == 0 and y != 0) {
          dp[j][k][2][ind] = max(dp[j][k][2][ind], dp[j][k+y][0][!ind]);
          dp[j][k][2][ind] = max(dp[j][k][2][ind], dp[j][k+y][1][!ind]);
        }
        else if (x != 0 and y == 0) {
          dp[j][k][1][ind] = max(dp[j][k][1][ind], dp[j+x][k][0][!ind]);
          dp[j][k][1][ind] = max(dp[j][k][1][ind], dp[j+x][k][2][!ind]);
        }
        else {
          for (int s = 0; s < 4; s++) 
            dp[j][k][0][ind] = max(dp[j][k][0][ind], dp[j+x][k+y][s][!ind]);
        }
      }
      for (int s = 0; s < 4; s++) dp[j][k][s][ind] += cost;
      for (int s = 0; s < 4; s++) ans = max(ans, dp[j][k][s][ind]);
    }
  }
  cout << ans;
  return 0;
}