// real solution but use 2x mem
#include <bits/stdc++.h>
using namespace std;

struct A {
  int node; long dis; short speed, last;
  bool operator < (const A & o) const {
    return (dis==o.dis) ? speed < o.speed : dis > o.dis;
  }
};

vector<pair<int,int>> g[80002];
priority_queue<A> heap;
map<int,short> num;
bool room[80002];
long dis[80002][9][11];

int main(){
  int n, m, l, q;
  scanf("%d %d %d %d", &n, &m, &l, &q);
  for(int i = 0; i < m; i++){
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    g[a].push_back({b, c});
  }
  for(int i = 0; i < l; i++){
    int a; scanf("%d", &a);
    room[a] = 1; num[a] = i+1;
  }

  for(int i = 0; i <= n; i++) 
    for(int j = 0 ; j <= q; j++) 
      for (int k = 0; k <= l; k++)
        dis[i][j][k] = 1e18;

  heap.push({1, 0, 0, 0});
  dis[1][0][0] = 0;

  while(!heap.empty()){
    auto t = heap.top(); heap.pop();

    if (t.node == n) {
      printf("%lld", t.dis);
      return 0;
    }

    for(auto x : g[t.node]) {
      if (room[t.node] && t.speed+1 <= q && t.last != t.node) {
        long long newdis = t.dis + x.second/(1<<(t.speed+1));
        if (dis[x.first][t.speed+1][num[t.node]] < newdis) continue;
        dis[x.first][t.speed+1][num[t.node]] = newdis;
        heap.push({x.first, newdis, t.speed+1, t.node});
      }
      long long newdis = t.dis + x.second/(1<<(t.speed));
      if (dis[x.first][t.speed][num[t.last]] < newdis) continue;
      dis[x.first][t.speed][num[t.last]] = newdis;
      heap.push({x.first, newdis, t.speed, t.last});
    }
  }
  return 0;
}