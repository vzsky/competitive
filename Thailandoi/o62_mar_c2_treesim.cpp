#include<bits/stdc++.h>
using namespace std;

// why x in n=100000

vector<int> g[200100];
set<int> node[200100];
map<set<int>,int> remember;
int ans = 0;

int merge (int a, int b) {
  if (node[a].size() > node[b].size()) swap(a, b);
  for (auto x : node[a]) {
    node[b].insert(x);
  }
  node[a].clear();
  return b;
}

int dfs (int u, int p) {
  int now = u;
  for (auto x : g[u]) if (x != p) {
    int child = dfs(x, u);
    if (u != 1) {
      remember[node[child]] = 1;
      now = merge(now, child);
    }
  }
  return now;
}

int dfs2 (int u, int p) {
  int now = u;
  for (auto x : g[u]) if (x != p) {
    int child = dfs2(x, u);
    if (u != 1) {
      if (remember[node[child]] != 1) ans++;
      now = merge(now, child);
    }
  }
  return now;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) node[i].insert(i);
  for (int i = 0; i < 2*n-3; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1,1);

  for (int i = 0; i < 2*n; i++) {
    node[i].clear();
    g[i].clear();
  }
  for (int i = 1; i <= n; i++) node[i].insert(i);
  for (int i = 0; i < 2*n-3; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs2(1,1);
  cout << ans;
  return 0;
}