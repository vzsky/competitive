#include<bits/stdc++.h>
using namespace std;

int tab[30][30];
vector<pair<int,int>> door[30][30];

struct A {
  int x, y, used, d;
  bool operator < (const A & o) const {
    return d > o.d;
  }
};
priority_queue<A> heap;

int visited[30][30][30];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, p, k; cin >> n >> p >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> tab[i][j];
    }
  }
  memset(visited, 0, sizeof visited);
  for (int i = 1; i <= p; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    door[a][b].push_back({c, d});
  }
  int ans = 1e9;
  heap.push({0, 0, 0, 0});
  while (!heap.empty()) {
    auto [x, y, u, d] = heap.top(); heap.pop();
    if (x < 0 or y < 0 or x >= n or y >= n) continue;
    if (visited[x][y][u]) continue;
    visited[x][y][u] = 1;
    if (x == n-1 and y == n-1) {
      ans = d;
      break;
    }
    for (int i = 0; i < 4; i++) {
      int nx = x+dx[i], ny = y+dy[i];
      if (nx < 0 or ny < 0 or nx >= n or ny >= n) continue;
      heap.push({nx, ny, u, d+tab[nx][ny]});
    }
    if (u < k) {
      for (auto des : door[x][y]) {
        heap.push({des.first, des.second, u+1, d});
      }
    }
  }
  cout << ans << '\n';
  return 0;
}