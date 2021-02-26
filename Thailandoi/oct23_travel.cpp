#include<bits/stdc++.h>
using namespace std;

vector<int> g[30100];
int n, par[22][30100], dep[30100];

void dfs (int u, int p, int d = 0) {
  par[0][u] = p;
  dep[u] = d;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u, d+1);
  }
}

void build () {
  for (int i = 1; i <= 15; i++) {
    for (int j = 1; j <= n; j++) {
      par[i][j] = par[i-1][par[i-1][j]];
    }
  }
}

int lca (int u, int v) {
  if (dep[u] > dep[v]) swap(u, v); // v > u
  for (int i = 15; i >= 0; i--) {
    if (dep[par[i][v]] >= dep[u]) v = par[i][v];
  }
  assert(dep[u] == dep[v]);
  if (u == v) return u;
  for (int i = 15; i >= 0; i--) {
    if (par[i][u] != par[i][v]) {
      u = par[i][u]; v = par[i][v];
    }
  }
  return par[0][u];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b); 
    g[b].push_back(a);
  }
  dfs(1, 1);
  build();
  int ans = 0, last = 1, m; cin >> m;
  for (int i = 0; i < m; i++) {
    int a; cin >> a;
    ans += dep[last] + dep[a] - 2 * dep[lca(last, a)];
    last = a;
  }
  cout << ans;
  return 0;
}