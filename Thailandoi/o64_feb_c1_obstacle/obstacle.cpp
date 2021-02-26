#include "obstacle.h"
#include <bits/stdc++.h> 
using namespace std;

vector<vector<long long>> dis, sid, row, col;
int n, m;

void initialize(int N, int M, int Q, vector<vector<int>>& rowlen, vector<vector<int>>& collen) {
  n = N; m = M;

  dis.resize(N, vector<long long>(M));
  sid.resize(N, vector<long long>(M));
  row.resize(N, vector<long long>(M));
  col.resize(N, vector<long long>(M));

  dis[0][0] = 0;
  sid[N-1][M-1] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (i == 0 and j == 0) continue;
      if (i == 0) dis[i][j] = dis[i][j-1] + rowlen[0][j-1];
      else if (j == 0) dis[i][j] = dis[i-1][j] + collen[i-1][0];
      else dis[i][j] = min(dis[i-1][j] + collen[i-1][j], dis[i][j-1] + rowlen[i][j-1]);
    }
  }
  for (int i = N-1; i >= 0; i--) {
    for (int j = M-1; j >= 0; j--) {
      if (i == N-1 and j == M-1) continue;
      if (i == N-1) sid[i][j] = sid[i][j+1] + rowlen[N-1][j];
      else if (j == M-1) sid[i][j] = sid[i+1][j] + collen[i][M-1];
      else sid[i][j] = min(sid[i+1][j] + collen[i][j], sid[i][j+1] + rowlen[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    long long mn = 1e15;
    for (int j = 0; j < m; j++) {
      mn = min(mn, dis[i][j]+sid[i][j]);
      row[i][j] = mn;
    }
  }
  for (int j = 0; j < m; j++) {
    long long mn = 1e15;
    for (int i = n-1; i >= 0; i--) {
      mn = min(mn, dis[i][j]+sid[i][j]);
      col[i][j] = mn;
    }
  }
}
 
int ask(int r, int c) {
  long long ans = 1e15;
  if (n < m) {
    for (int i = r+1; i < n; i++) if (c > 0) 
      ans = min(ans, row[i][c-1]);
  }
  else {
    for (int j = 0; j < c; j++) if (r < n-1)
      ans = min(ans, col[r+1][j]);
  }
  return ans == 1e15? -1: ans;
}