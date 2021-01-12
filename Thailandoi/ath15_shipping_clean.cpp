#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

vector<int> g[100100];
long long s[100100][5];
int q[100100];

const long long inf = 1e18;

void dfs (int u, int p) {
  for (int i = 0; i < 5; i++) s[u][i] = -inf;
  vector<vector<long long>> a;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u);
    for (int i = 0; i <= 2; i++) s[u][i+1] = max(s[u][i+1], s[x][i]);
    s[u][4] = max(s[u][4], max(s[x][4], q[u] + s[x][3]));
    a.push_back({s[x][0], s[x][1], s[x][2]});
  }
  s[u][0] = q[u];
  if (a.size() <= 1) return;

  pair<int,int> big[3];
  for (int i = 0; i <= 2; i++) if (a[0][i] > a[1][i])
    big[i] = {0, 1}; else big[i] = {1, 0};

  for (int i = 2; i < a.size(); i++)
    for (int j = 0; j <= 2; j++) 
      if (a[i][j] > a[big[j].x][j]) big[j] = {i, big[j].x};
      else if (a[i][j] > a[big[j].y][j]) big[j] = {big[j].x, i};

  if (big[0].x != big[2].x) s[u][4] = max(s[u][4], a[big[0].x][0] + a[big[2].x][2]);
  s[u][4] = max(s[u][4], max(a[big[0].x][0] + a[big[2].y][2], a[big[0].y][0] + a[big[2].x][2]));
  s[u][4] = max(s[u][4], a[big[1].x][1] + a[big[1].y][1]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i];
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 1);
    cout << (s[1][4] < 0? -1: s[1][4]) << endl; 
  }
  return 0;
}