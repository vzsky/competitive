#include<bits/stdc++.h>
using namespace std;

struct S {
  int x, y, d;
  bool operator < (const S & o) const {
    return d > o.d;
  }
};

int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};

char tab[110][110];
int dis[35][110][110];
bool vis[35][33000];
vector<S> key;
queue<S> q;
priority_queue<S> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, k; cin >> r >> c >> k;
  int s, e;
  for (int i = 0; i < r; i++) cin >> tab[i];
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (tab[i][j] == 'z') s = key.size();
      if (tab[i][j] == 'Z') e = key.size();
      if (tab[i][j] != '.' and tab[i][j] != '#') {
        int bit = 0;
        if (tab[i][j] >= 'a' and tab[i][j] != 'z') bit = (1<<(tab[i][j]-'a'));
        key.push_back({i, j, bit});
      }
    }
  }
  memset(dis, -1, sizeof dis);
  for (int i = 0; i < key.size(); i++) {
    q.push({key[i].x, key[i].y, 0});
    while (!q.empty()) {
      auto t = q.front(); q.pop();
      if (dis[i][t.x][t.y] != -1) continue;
      dis[i][t.x][t.y] = t.d;
      // cerr << i << ' ' << t.x << ' ' << t.y << ' ' << t.d << endl;
      if (tab[t.x][t.y] != '.' and !(t.x == key[i].x and t.y == key[i].y)) continue; 
      for (int d = 0; d < 4; d++) {
        if (tab[t.x+dx[d]][t.y+dy[d]] == '#') continue;
        if (t.x+dx[d] < 0 or t.x+dx[d] >= r or t.y+dy[d] < 0 or t.y+dy[d] >= c) continue;
        if (dis[i][t.x+dx[d]][t.y+dy[d]] == -1) q.push({t.x+dx[d], t.y+dy[d], t.d+1});
      }
    }
  }
  // cerr << dis[2][1][0] << "?" << endl;
  // for (auto ele : key) cerr << tab[ele.x][ele.y] << ' '; cerr << endl;
  heap.push({s, 0, 0});
  while (!heap.empty()) {
    auto t = heap.top(); heap.pop();
    if (vis[t.x][t.y]) continue;
    vis[t.x][t.y] = 1;
    // cerr << t.x << ' ' << t.y << ' ' << t.d << endl;
    if (t.x == e) {
      cout << t.d; return 0;
    }
    for (int i = 0; i < key.size(); i++) {
      if (i == t.x) continue;
      // cerr << "dis " << dis[t.x][key[i].x][key[i].y] << endl;
      if (dis[t.x][key[i].x][key[i].y] == -1) continue;
      if (tab[key[i].x][key[i].y] >= 'A' and tab[key[i].x][key[i].y] < 'Z') {
        if (1<<(tab[key[i].x][key[i].y] - 'A') & t.y)
        heap.push({i, t.y|key[i].d, t.d+dis[t.x][key[i].x][key[i].y]});
      }
      else {
        // cerr << "c " << i << ' ' << key[i].x << ' ' << key[i].y << endl;
        heap.push({i, t.y|key[i].d, t.d+dis[t.x][key[i].x][key[i].y]});
      }
    }
  }
  cout << -1;
  return 0;
}