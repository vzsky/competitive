#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100], tree;
int vis[100100], in[100100], cir;
set<vector<int>> s;

int mark (int u, int p = 0, int d = 0) {
  int cnt = 1;
  if (vis[u]) { cir = max(cir,d); return 0; }
  vis[u] = 1;
  for (auto x : g[u]) {
    if (x == p) continue;
    cnt += mark(x, u, d+1);
  }
  if (cnt == 1) tree.push_back(d); 
  return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    in[u]++; in[v]++;
  }
  for (int i = 1; i <= n; i++) if (in[i] == 3 and !vis[i]) {
    tree.clear(); cir = 0;
    int cnt = mark(i);
    tree.resize(3);
    sort(tree.begin(), tree.end());
    tree.push_back(cir);
    tree.push_back(cnt);
    s.insert(tree);
  }
  for (int i = 1; i <= n; i++) if (!vis[i]) {
    cir = 0;
    int cnt = mark(i);
    s.insert({cir, cnt});
  }

  cout << s.size() << endl;
  return 0;
}