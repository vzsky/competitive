#include "emergency.h"
#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<long long,int>,pair<long long,int>> ppp;

bool isHospital[200100], isCenter[200100];
vector<pair<int,int>> g[200100];
long long fur[200100];
int hos[200100];
int cen[200100];

void dfs(int u, int p) {
  bool isLeave = true;

  ppp furHos = {{-2e9,-1}, {-2e9,-1}}, furCen = {{-2e9,-1}, {-2e9,-1}};

  if (isHospital[u]) {
    hos[u] = 0;
    furHos = {{0, -2}, {-2e9, -1}};
  }
  if (isCenter[u]) {
    cen[u] = 0;
    furCen = {{0, -2}, {-2e9, -1}};
  }

  for (auto x : g[u]) {
    if (x.first == p) continue;
    dfs(x.first, u);

    hos[u] = max(hos[u], hos[x.first]+x.second);
    cen[u] = max(cen[u], cen[x.first]+x.second);

    if (hos[x.first]+x.second > furHos.first.first) {
      furHos.second = furHos.first;
      furHos.first = {hos[x.first]+x.second, x.first};
    }
    else if (hos[x.first]+x.second > furHos.second.first) {
      furHos.second = {hos[x.first]+x.second, x.first};
    }

    if (cen[x.first]+x.second > furCen.first.first) {
      furCen.second = furCen.first;
      furCen.first = {cen[x.first]+x.second, x.first};
    }
    else if (cen[x.first]+x.second > furCen.second.first) {
      furCen.second = {cen[x.first]+x.second, x.first};
    }

    fur[u] = max(fur[u], fur[x.first]);
    if (furHos.first.second != furCen.first.second) fur[u] = max(fur[u], furHos.first.first+furCen.first.first);
    if (furHos.first.second != furCen.second.second) fur[u] = max(fur[u], furHos.first.first+furCen.second.first);
    if (furHos.second.second != furCen.first.second) fur[u] = max(fur[u], furHos.second.first+furCen.first.first);
    if (furHos.second.second != furCen.second.second) fur[u] = max(fur[u], furHos.second.first+furCen.second.first);
  }

  if (hos[u] < 0) hos[u] = -2e9;
  if (cen[u] < 0) cen[u] = -2e9;
  if (fur[u] < 0) fur[u] = -2e9;
}

int furthest(int N, int H, int K, int e[][2], int w[], int h[], int c[]) {
  for (int i = 0; i < N-1; i++) {
    g[e[i][0]].push_back({e[i][1], w[i]});
    g[e[i][1]].push_back({e[i][0], w[i]});
  }
  for (int i = 0; i < H; i++) isHospital[h[i]] = true;
  for (int i = 0; i < K; i++) isCenter[c[i]] = true;
  for (int i = 0; i <= N; i++) hos[i] = cen[i] = fur[i] = -2e9; 
  dfs(1,1);
  assert(fur[1] > 0);
  return fur[1];
}
