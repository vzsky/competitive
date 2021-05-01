#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> e;
vector<pair<int,int>> g[50100];
int visited[50100];
struct A {
  int u, d; 
  bool operator < (const A & o) const {
    return d > o.d;
  }
};
priority_queue<A> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    e.push_back({a, b, c});
  }
  int l = 1, r = m+1;
  while (l < r) {
    int mid = (l+r)/2;
    for (int i = 0; i <= n; i++) g[i].clear();
    for (int i = 0; i < mid; i++) {
      auto [a, b, c] = e[i];
      g[a].push_back({b, c});
      g[b].push_back({a, c});
    }
    memset(visited, 0, sizeof visited);
    while (!heap.empty()) heap.pop();
    heap.push({1, 0});
    int ans = 1e9;
    while (!heap.empty()) {
      auto [u, d] = heap.top(); heap.pop();
      if (visited[u]) continue;
      visited[u] = 1;
      if (u == n) {
        ans = d;
        break;
      }
      for (auto [x, c] : g[u]) {
        heap.push({x, d+c});
      }
    }
    if (ans <= k) r = mid;
    else l = mid+1;
  }
  cout << (l==m+1?-1:l) << endl;
  return 0;
}