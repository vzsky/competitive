// GRADER NOT WORKING
#include<bits/stdc++.h>
using namespace std;

int g[310][310], comp[310], mark[310], n, cnt = 1, reach[310];
void dfs (int u, int p) {
  if (comp[u]) return;
  comp[u] = cnt;
  for (int i = 1; i <= n; i++) if (g[u][i]) {
    if (comp[i]) continue;
    dfs(i, u);
  }
}

vector<int> ans;
void get (int u) {
  memset(reach, 0, sizeof reach);
  int next = u;
  while (true) {
    ans.push_back(next);
    for (int i = 1; i <= n; i++) if (g[next][i]) reach[i] = 1;
    next = -1;
    for (int i = 1; i <= n; i++) if (!reach[i]) next = i;
    if (next == -1) break;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    int f; cin >> f;
    for (int j = 1; j <= f; j++) {
      int d; cin >> d; g[i][d] = 0;
    }
  }
  for (int i = 1; i <= n; i++) if (!comp[i]) dfs(i, i); cnt++;
  for (int i = 1; i <= n; i++) if (!mark[comp[i]]) {
    mark[comp[i]] = 1; get(i);
  }
  cout << ans.size() << endl;
  for (auto x : ans) cout << x << ' ';
  return 0;
}