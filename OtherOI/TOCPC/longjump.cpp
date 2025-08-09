#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) x.begin(), x.end()

map<int, vector<int> > wallx, wally;
map<pair<int, int>, int> vis;
queue<pair<int, pair<int, int> > > q;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, w;           cin >> n >> m >> w;
  int sx, sy, ex, ey;    cin >> sx >> sy >> ex >> ey;
  
  for (int i = 0; i < w; i++) {
    int x, y; cin >> x >> y;
    wallx[x].push_back(y);
    wally[y].push_back(x);
  }

  q.push({0, {ex, ey}});
  int ans = -1;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    if (vis[t.y]) continue;
    vis[t.y] = 1;

    if (t.y == make_pair(sx, sy)) {
      ans = t.x; break;
    }

    int idx = upper_bound(all(wally[t.y.y]), t.y.x) - wally[t.y.y].begin();
    if (idx == wally[t.y.y].size())   q.push({t.x + 1, {n, t.y.y}});
    else                              q.push({t.x + 1, {wally[t.y.y][idx] - 1, t.y.y}});
    if (idx == 0)                     q.push({t.x + 1, {1, t.y.y}});
    else                              q.push({t.x + 1, {wally[t.y.y][idx - 1] + 1, t.y.y}});

    int idy = upper_bound(all(wallx[t.y.x]), t.y.y) - wallx[t.y.x].begin();
    if (idy == wallx[t.y.x].size())   q.push({t.x + 1, {t.y.x, m}});
    else                              q.push({t.x + 1, {t.y.x, wallx[t.y.x][idy] - 1}});
    if (idy == 0)                     q.push({t.x + 1, {t.y.x, 1}});
    else                              q.push({t.x + 1, {t.y.x, wallx[t.y.x][idy - 1] + 1}});
  }
  cout << ans << endl;
  return 0;
}
