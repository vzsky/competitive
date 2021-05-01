#include<bits/stdc++.h>
using namespace std;

int l, w, m;
int tab[35][35], cnt[910], gcnt[910];
int costa[35][35][35], costb[35][35][35];
int mem[35][35][35][35];

int solve (int a, int b, int c, int d) {
  if (mem[a][b][c][d] != -1) return mem[a][b][c][d];
  if (a == c) return costa[c][b][d];
  if (b == d) return costb[d][a][c];
  int ret = 0;
  ret = max(ret, costa[a][b][d]+solve(a+1, b, c, d));
  ret = max(ret, costb[b][a][c]+solve(a, b+1, c, d));
  ret = max(ret, costa[c][b][d]+solve(a, b, c-1, d));
  ret = max(ret, costb[d][a][c]+solve(a, b, c, d-1));
  return mem[a][b][c][d] = ret;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> l >> w >> m;
  for (int i = 1; i <= l; i++) {
    for (int j = 1; j <= w; j++) {
      cin >> tab[i][j];
      gcnt[tab[i][j]]++;
    }
  }
  memset(mem, -1, sizeof mem);
  for (int a = 1; a <= l; a++) {
    for (int b = 1; b <= w; b++) {
      for (int d = b; d <= w; d++) {
        costa[a][b][d] = 0;
        for (int i = 1; i <= m; i++) cnt[i] = 0;
        for (int i = b; i <= d; i++) cnt[tab[a][i]]++;
        for (int i = 1; i <= m; i++) if (cnt[i] == gcnt[i]) costa[a][b][d]++;
      }
    }
  }
  for (int b = 1; b <= w; b++) {
    for (int a = 1; a <= l; a++) {
      for (int c = a; c <= l; c++) {
        costb[b][a][c] = 0;
        for (int i = 1; i <= m; i++) cnt[i] = 0;
        for (int i = a; i <= c; i++) cnt[tab[i][b]]++;
        for (int i = 1; i <= m; i++) if (cnt[i] == gcnt[i]) costb[b][a][c]++;
      }
    }
  }
  cout << solve (1, 1, l, w);
  return 0;
}