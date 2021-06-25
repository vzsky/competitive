#include "hoax.h"
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int vis[400100], compsz[200100], comp[200100];
vector<int> g[400100];
vector<tuple<int,int,int>> cod;
int n, cnt = 0;

void dfs (int u, int p) {
  if (vis[u]) return;
  vis[u] = 1;
  if (u < n) {
    comp[u] = cnt;
    compsz[cnt]++;
  }
  for (auto x : g[u]) if (x != p) {
    dfs(x, u);
  } 
}

void init(int N, int S, vector<int> T, vector<vector<int>> A, vector<vector<int>> B) {
  n = N;
  memset(comp, -1, sizeof comp);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < T[i]; j++) {
      cod.push_back({A[i][j], 1, i});
      cod.push_back({B[i][j]+1, 0, i});
    }
  }

  sort(all(cod));
  int oth = N+5; 
  set<int> q;

  for (auto [u, s, i] : cod) {
    if (q.empty()) oth++;
    if (s) {
      q.insert(i);
      g[i].push_back(oth);
      g[oth].push_back(i);
    } else {
      q.erase(i);
    }
  }
  
  for (int i = 0; i < N; i++) { dfs(i, i); cnt++; }
}

int count_users(int P) { return compsz[comp[P]]; }
