#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];
int num[100100], maxdis[100100], mdis[100100], mark[100100];

void dfs (int root, int par, int id) {
  queue<tuple<int,int,int>> q;
  q.push({root, par, id});
  while(!q.empty()) {
    auto [root, par, id] = q.front();
    q.pop();
    if (num[root] != -1) continue;
    num[root] = id;
    for (auto x : g[root]) {
      if (num[x] != -1) continue;
      q.push({x, root, id+1});
    }
  }
}

void getmaxdis (int root, int par, int length = 0) {
  queue<tuple<int,int,int>> q;
  q.push({root, par, length});
  while (!q.empty()) {
    auto [root, par, length] = q.front();
    q.pop();
    if (mark[root]) continue;
    maxdis[num[root]] = max(maxdis[num[root]], length);
    mark[root] = 1;
    for (int x : g[root]) {
      if (mark[x]) continue;
      q.push({x, root, length+1});
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, p, a, b; cin >> n >> m >> p >> a >> b;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  for (int i = 0; i <= n; i++) num[i] = maxdis[i] = -1;
  dfs(b, b, 0);
  getmaxdis(a, a);
  for (int i = n; i >= 0; i--) mdis[i] = max(mdis[i+1], maxdis[i]);

  for (int i = 0; i < p; i++) {
    int x; cin >> x;
    cout << mdis[x+1] << '\n';
  }
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/