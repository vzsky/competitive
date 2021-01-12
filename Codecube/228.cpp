#include<bits/stdc++.h>
using namespace std;

struct A { long long u, w, s; 
  bool operator < (const A & o) const {
    return w > o.w;
  }
};
vector<A> g[100100];
priority_queue <A> heap;

int visited[100100][2];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, m, t;
  cin >> n >> m >> k >> t;
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].push_back({v, w, -1});
    g[v].push_back({u, w, -1});
  }

  long long ans = 1e18;
  heap.push({1, 0, 0});
  while (!heap.empty()) {
    auto [u, w, s] = heap.top();
    heap.pop();
    if (visited[u][s]) continue;
    visited[u][s] = 1;
    
    if (u == n) {
      ans = min(w, ans);
    }

    for (auto x : g[u]) {
      if (visited[x.u][s]) continue;
      heap.push({x.u, w+x.w, s});
      if (s == 0 && !visited[x.u][1]) {
        heap.push({x.u, w+k, 1});
      }
    }
  }
  if (ans == 1e18 || ans > t) {
    cout << "No Honey TT\n";
  }
  else {
    cout << "Happy Winnie the Pooh :3\n";
    cout << ans;
  }
  return 0;
}