#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[100100];
long long sz[100100], chaos[100100], n;

long long build (int u, int p) {
  sz[u] = 1;
  for (auto [x, i] : g[u]) if (x != p) {
    sz[u] += build(x, u);
    chaos[i] = (sz[x]*(n-sz[x]));
  }
  return sz[u];
}

pair<long long,long long> dfs (int u, int p) {
  long long ans = 0, ind = u;
  for (auto [x, i] : g[u]) if (x != p) {
    auto d = dfs(x, u);
    long long idx = d.second, now = d.first+chaos[i];
    if (now > ans) ans = now, ind = idx;
  }
  return {ans, ind};
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back({b, i});
    g[b].push_back({a, i});
  }
  build(1,1);
  cout << dfs(dfs(1, 1).second, -1).first << endl;
  return 0;
}
