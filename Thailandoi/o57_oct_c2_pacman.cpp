#include<bits/stdc++.h>
using namespace std;

int tab[1010][1010];
long long dp[5][1010][1010], ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> tab[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[0][i][j] = max(max(max(dp[2][i-1][j], dp[2][i][j-1]), max(dp[1][i-1][j], dp[1][i][j-1])), max(dp[0][i-1][j], dp[0][i][j-1]));
      dp[1][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]) + tab[i][j];
      dp[2][i][j] = max(dp[1][i-1][j], dp[1][i][j-1]) + tab[i][j];
      ans = max(ans, max(dp[0][i][j], max(dp[1][i][j], dp[2][i][j])));
    }
  }
  cout << ans;
  return 0;
}