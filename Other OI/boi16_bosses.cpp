#include<bits/stdc++.h>
using namespace std;

vector<int> g[5010];
int visited[5010];
int dep[5010];

int dfs (int u, int n) {
  int sum = 0, cnt = 0;
  queue<pair<int,int>> q;
  q.push({u, u});
  while (!q.empty()) {
    auto [u, p] = q.front(); q.pop();
    if (visited[u]) continue;
    visited[u] = 1;
    dep[u] = dep[p] + 1;
    cnt ++;

    for (auto x : g[u]) {
      if (visited[x]) continue;
      q.push({x, u});
    }

    sum += dep[u];
  }
  if (cnt != n) return 1e9;
  return sum;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int k; cin >> k;
    while(k--) {
      int a; cin >> a;
      g[a].push_back(i); // a is bossable to i 
    }
  }
  int mn = 1e9;
  for (int i = 1; i <= n; i++) {
    // i is root
    memset(visited, 0, sizeof visited);
    memset(dep, 0, sizeof dep);
    mn = min(mn, dfs(i, n));
  }
  cout << mn << endl;
  return 0;
}