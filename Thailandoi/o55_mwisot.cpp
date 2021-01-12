#include<bits/stdc++.h>
using namespace std;

int w[100100], dp[100100][2];
vector<int> g[100100];
void dfs (int u, int p) {
  int sum0 = 0, sum1 = 0;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u);
    sum0 += dp[x][0];
    sum1 += max(dp[x][1], dp[x][0]);
  }
  dp[u][1] = sum0 + w[u];
  dp[u][0] = sum1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> w[i]; 
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0,0);
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}