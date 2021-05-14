#include<bits/stdc++.h>
using namespace std;

int cost[510][510], dp[510][510];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) for (int j = i+1; j <= n; j++) cin >> cost[i][j];
  for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dp[i][j] = 1e9;

  dp[2][1] = cost[1][2];
  int ans = 1e9;
  for (int i = 3; i < n; i++) {
    for (int k = 1; k < i-1; k++) dp[i][i-1] = min(dp[i][i-1], dp[i-1][k]+cost[k][i]);
    for (int j = 1; j < i-1; j++) dp[i][j] = dp[i-1][j]+cost[i-1][i];
    if (i == n-1) for (int j = 1; j < n-1; j++) ans = min(ans, dp[i][j]+cost[i][n]+cost[j][n]);
  } cout << ans << endl;
}