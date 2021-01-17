#include<bits/stdc++.h>
using namespace std;

int di[] = {1, -1, 0, 0}, dj[] = {0, 0, 1, -1};
char a[50][50];
int vis[50][50], cnt, n, m;

bool offbound(int i, int j) {return (i < 0 or i >= n) and (j < 0 or j >= m);}

void fill(int i, int j) {
  if (vis[i][j]) return;
  cnt++; vis[i][j] = 1;
  for (int d = 0; d < 4; d++) {
    int ni = i+di[d], nj = j+dj[d];
    if (offbound(ni, nj) or a[ni][nj] != '.') continue;
    fill(ni, nj);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != '#') continue;
      for (int d = 0; d < 4; d++) {
        int ni = i+di[d], nj = j+dj[d];
        if (offbound(ni, nj)) continue;
        if (a[ni][nj] == '.') a[ni][nj] = '@';
      }
    }
  }
  int mx = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' and !vis[i][j]) {
        cnt = 0;
        fill(i, j);
        mx = max(mx, cnt);
      }
    }
  }
  cout << mx;
  return 0;
}