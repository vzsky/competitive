#include<bits/stdc++.h>
using namespace std;

long long c[5010], qs[5010], dp[3][2][5010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n; 
  for (int i = 1; i <= n; i++) cin >> c[i];
  for (int i = 1; i <= n; i++) qs[i] = qs[i-1] + c[i];

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n+5; j++) {
      dp[0][i%2][j] = dp[1][i%2][j] = dp[2][i%2][j] = 0;
    }
    for (int j = 1; j <= n; j++) {
       if (j+i-1 > n) continue;
      long long cost = qs[j+i-1] - qs[j-1];
      if (j+i <= n) // after
        dp[0][i%2][j] = max(dp[0][i%2][j], dp[1][(i-1)%2][j+i] + cost);
      if (j-i+1 >= 1) // before
        dp[0][i%2][j] = max(dp[0][i%2][j], dp[2][(i-1)%2][j-i+1] + cost); 
      dp[0][i%2][j] = max(dp[0][i%2][j], dp[1][(i-1)%2][1] + cost/2); // best
    }
    for (int j = n; j >= 1; j--) dp[1][i%2][j] = max(dp[0][i%2][j], dp[1][i%2][j+1]);
    for (int j = 1; j <= n; j++) dp[2][i%2][j] = max(dp[0][i%2][j], dp[2][i%2][j-1]);
  } 
  cout << dp[1][n%2][1] << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/