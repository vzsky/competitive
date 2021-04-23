#include<bits/stdc++.h>
using namespace std;

set<int> g[100100];
int sz[100100];

void dfs (int u, int p) {
  sz[u] = 1;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u);
    sz[u] += sz[x];
  }
}

int centroid (int u, int p, int n) {
  for (auto x : g[u]) {
    if (x == p) continue;
    if (sz[x] > n/2) return centroid(x, u, n);
  }
  return u;
}

map<int,int> dis[100100];
void finddis (int c, int u, int p, int d = 0) {
  dis[c][u] = d;
  for (auto x : g[u]) {
    if (x == p) continue;
    finddis(c, x, u, d+1);
  }
}

int par[100100];
void build (int u, int p) {
  dfs(u, p);
  int c = centroid(u, p, sz[u]);
  par[c] = p;
  // store distance of c to every node in the tree since c is their ancestor.
  finddis(c, c, p);
  // remove c from the tree
  auto tmp = vector<int>(g[c].begin(), g[c].end()); // so that erasing from g[c] doesn't affect the iteration
  for (auto x : tmp) {
    g[x].erase(c);
    g[c].erase(x);
    build(x, c);
  }

}

int closest[100100];
void paint (int u) {
  for (int p = u; p != 0; p=par[p]) {
    closest[p] = min(closest[p], dis[p][u]);
  } 
}

int findClosest (int u) {
  int mn = 1e9;
  for (int p = u; p != 0; p=par[p]) {
    mn = min(mn, closest[p] + dis[p][u]);
  } 
  return mn;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    g[a].insert(b);
    g[b].insert(a);
  }
  build(1, 0);
  for (int i = 1; i <= n; i++) closest[i] = 1e9;

  paint(1);

  while (m--) {
    int t, v; cin >> t >> v;
    if (t == 1) paint(v);
    if (t == 2) cout << findClosest(v) << endl;
  }
  
  return 0;
}