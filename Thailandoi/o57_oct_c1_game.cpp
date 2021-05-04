#include<bits/stdc++.h>
using namespace std;

vector<int> g[5010], r[5010];
set<int> c[5010];
stack<int> st;
int vis[5010], ind[5010], in[5010], ans[5010];
queue<pair<int,int>> q;
vector<int> com[5010];

void dfs (int u, int p) {
  if (vis[u] == 1) return;
  vis[u] = 1;
  for (auto x : g[u]) if (x != p) dfs (x, u);
  st.push(u);
}

int idx = 0;
void scc (int u, int p) {
  if (vis[u] == 1) return;
  vis[u] = 1;
  com[idx].push_back(u);
  ind[u] = idx;
  for (auto x : r[u]) if (x != p) scc(x, u);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p; cin >> n >> p;
  for (int i = 0; i < p; i++) { 
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    r[b].push_back(a);
  }
  for (int i = 0; i < n; i++) if (!vis[i]) dfs(i, i);
  memset(vis, 0, sizeof vis);
  while (!st.empty()) {
    int t = st.top(); st.pop();
    if (!vis[t]) { idx++; scc(t, t); }
  }

  for (int i = 0; i < n; i++) {
    for (auto x : g[i]) if (ind[i] != ind[x]) {
      if (c[ind[i]].find(ind[x]) == c[ind[i]].end()) in[ind[x]]++;
      c[ind[i]].insert(ind[x]);
    }
  }
  for (int i = 1; i <= idx; i++) if (in[i] == 0) q.push({i, 0});
  
  int mxans = 0;
  while (!q.empty()) {
    auto [t, l] = q.front(); q.pop();
    ans[l]+=com[t].size();
    mxans = max(mxans, l);
    for (auto u : c[t]) if (--in[u] == 0) q.push({u, l+1});
  }
  for (int i = 0; i <= mxans; i++) cout << ans[i] << ' ';
  return 0;
}