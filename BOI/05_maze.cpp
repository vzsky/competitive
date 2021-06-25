#include<bits/stdc++.h>
using namespace std;
 
struct A {
  int x, y, s, d;
  bool operator < (const A & o) const {return d > o.d;}
};
priority_queue<A> heap;
int vis[510][510][3];
vector<pair<pair<int,int>, int>> g[510][510];
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int w, h; cin >> w >> h;
  pair<int,int> s, e; cin >> s.first >> s.second >> e.first >> e.second;
  for (int i = 0; i < 2*h+1; i++) {
    int c; string s; cin >> s;
    for (int j = 0; j < (i&1?2*w+1:w); j++) {
      if (s[j] == 'n') continue;
      if (i&1) {
        g[(j+1)/2][i/2].push_back({{(j+1)/2-(j&1), i/2+1}, s[j] == 'b'?1:0});
        g[(j+1)/2-(j&1)][i/2+1].push_back({{(j+1)/2, i/2}, s[j] == 'b'?1:0});
      }
      else {
        g[j][i/2].push_back({{j+1, i/2}, s[j] == 'b'?1:0});
        g[j+1][i/2].push_back({{j, i/2}, s[j] == 'b'?1:0});
      }
    }
  }
  heap.push({s.first, s.second, 0, 0});
  heap.push({s.first, s.second, 1, 0});
  while (!heap.empty()) {
    auto [x, y, s, d] = heap.top(); heap.pop();
    if (vis[x][y][s]) continue;
    vis[x][y][s] = 1;
    if (e.first == x and e.second == y) { cout << d << endl; break; }
    for (auto [n, c] : g[x][y]) {
      if (c == s) continue;
      if (!vis[n.first][n.second][s^1]) heap.push({n.first, n.second, s^1, d+1});
    }
  }
  return 0;
}