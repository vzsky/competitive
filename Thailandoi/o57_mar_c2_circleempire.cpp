#include<bits/stdc++.h>
using namespace std;

long long dis[10010][10010];
vector<pair<int,int>> g[10010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k, l, m, q; cin >> k >> l >> m >> q;
  for (int i = 0; i <= 10000; i++) for (int j = 0; j <= 10000; j++) dis[i][j] = 1e9;
  for (int i = 0; i <= 10000; i++) dis[i][i] = 0;
  
  for (int i = 0; i < m; i++) {
    long long a, b, c; cin >> a >> b >> c;
    dis[a][b] = min(dis[a][b], c);
    dis[b][a] = min(dis[b][a], c);
    g[a].push_back({b, c});
    g[b].push_back({a, c});
  }
  for (int i = 0; i < k; i++) {
    for (int z = 0; z <= l; z++) {
      for (int x = 0; x <= l; x++) {
        for (int y = 0; y <= l; y++) {
          int nx = x+l*i, ny = y+l*i, nz = z+l*i;
          if (nx == 0) nx = k*l;
          if (ny == 0) ny = k*l;
          if (nz == 0) nz = k*l;
          dis[nx][ny] = min(dis[nx][ny], dis[nx][nz]+dis[nz][ny]);
        }
      }
    }
  }

  for (int i = 1; i <= k; i++) {
    int next = (i+1)*l;
    if (i == k) next = l;
    for (auto x : g[i*l]) {
      dis[i*l][next] = min(dis[i*l][next], x.second+dis[x.first][next]);
      dis[next][i*l] = min(dis[next][i*l], x.second+dis[x.first][next]);
    }
  }
  for (int z = 1; z <= k; z++) {
    for (int x = 1; x <= k; x++) {
      for (int y = 1; y <= k; y++) {
        dis[x*l][y*l] = min(dis[x*l][y*l], dis[x*l][z*l]+dis[z*l][y*l]); 
      }
    }
  }

  while (q--) {
    int x, y; cin >> x >> y;
    long long ans = dis[x][y];
    int ex = (x-1)/l, ey = (y-1)/l;
    int bex = ex+1, bey = ey+1;
    if (ex == 0) ex = k;
    if (ey == 0) ey = k;
    ans = min(ans, dis[x][ex*l]+dis[ex*l][ey*l]+dis[ey*l][y]);
    ans = min(ans, dis[x][bex*l]+dis[bex*l][ey*l]+dis[ey*l][y]);
    ans = min(ans, dis[x][ex*l]+dis[ex*l][bey*l]+dis[bey*l][y]);
    ans = min(ans, dis[x][bex*l]+dis[bex*l][bey*l]+dis[bey*l][y]);
    cout << ans << '\n';
  }
  
  return 0;
}