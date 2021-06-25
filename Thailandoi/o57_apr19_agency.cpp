#include<bits/stdc++.h>
using namespace std;

int cr[310];
vector<int> g[310];
int dp[310][310];
int kps[500][500];
int n, k; 

void dfs (int u, int p) {
  for (auto x : g[u]) if (x != p) {
    dfs(x, u);
  }
  // vector<pair<int,int>> choices;
  vector<int> child;
  for (auto x : g[u]) if (x != p) {
    child.push_back(x);
  }

  if (child.size() == 0) {
    dp[u][1] = cr[u];
    return;
  }
  
  memset(kps, 0, sizeof kps);
  for (int j = 1; j <= k; j++) {
    for (int x = 1; x <= k; x++) {
      if (j >= x) kps[0][j] = max(kps[0][j], dp[child[0]][x]);
    }
  }
  for (int i = 1; i < child.size(); i++) {
    for (int j = 1; j <= k; j++) {
      kps[i][j] = kps[i-1][j];
      for (int x = 1; x <= k; x++) {
        if (x <= j) kps[i][j] = max(kps[i][j], kps[i-1][j-x]+dp[child[i]][x]);
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    dp[u][i] = kps[child.size()-1][i-1]+cr[u];
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> cr[i];
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = max(dp[i][k], ans);
  cout << ans << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE
5 3
1 10 10 1 10
1 2
1 3
1 4
4 5
*/