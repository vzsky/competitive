#include<bits/stdc++.h>
using namespace std;
struct A {
  int v, d, s;
  bool operator < (const A & o) const {
    return d > o.d;
  }
};
int visited[10100][70];
vector<A> g[10100];
priority_queue<A> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, l; cin >> n >> m >> s >> l;
  for (int i = 0; i < m+s; i++) {
    int u, v, c; cin >> u >> v >> c;
    g[u].push_back({v, c, i>=m});
  }
  heap.push({1, 0, 0});
  while (!heap.empty()) {
    auto [v, d, s] = heap.top(); heap.pop();
    if (visited[v][s]) continue;
    visited[v][s] = 1;
    if (v == n) { cout << d << endl; return 0; }
    for (auto [x, c, b] : g[v]) {
      if (visited[x][s+b]) continue;
      if (s+b <= l) heap.push({x, d+c, s+b});
    }
  }
  return 1;
}