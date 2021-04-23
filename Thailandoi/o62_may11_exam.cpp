#include<bits/stdc++.h>
using namespace std;

vector<int> g[100500], rev[100500], sccg[100500];
int in[100500], mark[100500], visited[100500], scc[100500];

stack<int> st;
void dfs1 (int u) {
  if (visited[u]) return;
  visited[u] = 1;
  for (auto x : g[u]) dfs1(x);
  st.push(u);
}

int group = 0;
void dfs2 (int u) {
  if (visited[u]) return;
  visited[u] = 1;
  scc[u] = group;
  for (auto x : rev[u]) dfs2(x);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    for (int j = 0; j < k; j++) {
      if (s[j] == '1') g[i].push_back(n+j+1), rev[n+j+1].push_back(i);
      if (s[j] == '0') g[n+j+1].push_back(i), rev[i].push_back(n+j+1);
    }
  }

  // make dag of scc;

  for (int i = 1; i <= n+k; i++) if(!visited[i]) dfs1(i);
  memset(visited, 0, sizeof visited);
  while (!st.empty()) {
    auto t = st.top(); st.pop();
    if (visited[t]) continue;
    group++;
    dfs2(t);
  }

  // toposort

  for (int i = 1; i <= n+k; i++) {
    for (auto x : g[i]) {
      if (scc[i] != scc[x]) sccg[scc[i]].push_back(scc[x]), in[scc[x]]++;
    }
  }

  queue<pair<int,int>> q;
  for (int i = 1; i <= group; i++) if (in[i] == 0) q.push({i, 0});
  for (int i = 1; i <= n; i++) mark[scc[i]] = 1;
  
  vector<pair<int,int>> sccans;
  while (!q.empty()) {
    auto [t, l] = q.front(); q.pop();
    if (mark[t]) sccans.push_back({t, l});
    for (auto x : sccg[t]) {
      in[x]--; if (in[x] == 0) q.push({x, l+1});
    }
  }

  if (sccans.size() == 0 or ( sccans.size() > 1 and sccans[0].second == sccans[1].second)) {
    cout << -1; return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (scc[i] == sccans[0].first) cout << i << ' ';
  }

  return 0;
}