#include <bits/stdc++.h>
using namespace std;
 
#define max(x,y) (x>y)?x:y
#define min(x,y) (x>y)?y:x
 
vector<long long> g[200200];
 
long long dp[2][200200];
long long db[2][200200];
long long mx[200200];
long long mn[200200];
 
int main () {
  int t; cin >> t; 
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      while(!g[i].empty()) g[i].pop_back();
    }

    for (int i = 1; i <= n; i++) {
      g[i].push_back(0);
      for (int j = 0; j < m; j++) {
        long long x; cin >> x; g[i].push_back(g[i].back() + x);
      }
    }

    for (int i = 0; i <= m+1; i++) dp[0][i] = db[0][i] = 0;

    for (int j = 1; j <= n; j++) {

      mx[m] = g[j][m];
      mn[0] = g[j][0];
      for (int i = m-1; i >= 1; i--) mx[i] = max(mx[i+1], g[j][i]);
      for (int i = 1; i <= m; i++)   mn[i] = min(mn[i-1], g[j][i]);

      for (int i = 0; i <= m+1; i++) dp[j&1][i] =  db[j&1][i] = -1e15;

      for (int i = m-1; i >= 1; i--) {
        dp[j&1][i] = max(dp[j&1][i], dp[1-(j&1)][i+1] + mx[i+1] - g[j][i-1]);
        dp[j&1][i] = max(dp[j&1][i], db[1-(j&1)][i-1] + mx[i+1] - g[j][i-1]);
        dp[j&1][i] = max(dp[j&1][i], dp[j&1][i+1] + g[j][i] - g[j][i-1]);
        if (j == 2) dp[j&1][i] = max(dp[j&1][i], mx[i+1] - g[j][i-1] + g[j-1][i] - g[j-1][i-1]);
        if (j == 2) dp[j&1][i] = max(dp[j&1][i], mx[i+1] - g[j][i-1] + g[j-1][i+1] - g[j-1][i]);
      }

      for (int i = 1; i <= m-1; i++) {
        db[j&1][i] = max(db[j&1][i], dp[1-(j&1)][i+1] + g[j][i+1] - mn[i-1]);
        db[j&1][i] = max(db[j&1][i], db[1-(j&1)][i-1] + g[j][i+1] - mn[i-1]);
        db[j&1][i] = max(db[j&1][i], db[j&1][i-1] + g[j][i+1] - g[j][i]); 
        if (j == 2) db[j&1][i] = max(db[j&1][i], g[j][i+1] - mn[i-1] + g[j-1][i+1] - g[j-1][i]);
        if (j == 2) db[j&1][i] = max(db[j&1][i], g[j][i+1] - mn[i-1] + g[j-1][i] - g[j-1][i-1]);
      }

    }

    long long ans = -1e15;
    for (int i = 0; i <= m; i ++) {
      ans = max(ans, dp[n&1][i]);
      ans = max(ans, db[n&1][i]);
    } 
    if (n ==1) {
      for (int i = 1; i <= m; i++) {
        ans = max(ans, g[n][i] - g[n][i-1]);
      }
    }

    cout << ans << endl; 
  }
  return 0;
}

/*
  The indexing is not ideal, 
  - dp is the forward case (starting at i, i+1) and to the right
  - db is the backward case (ending at i, i+1) and to the left
  see https://codeforces.com/contest/2021/submission/284607478 for the absolute WTF
*/
