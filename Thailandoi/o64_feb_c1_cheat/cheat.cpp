#include "cheat.h"
#include <bits/stdc++.h>
using namespace std;

int p[200100], sz[200100], dep[200100], dis[200100], upd[200100];
vector<int> nd[200100];
int find(int u) {return u==p[u]?u:find(p[u]);}

bool initialized = false;
void init() {
  for (int i = 0; i < 200100; i++) {
    p[i] = i;
    upd[i] = 1;
    dis[i] = 0;
    nd[i].push_back(i);
    dep[i] = 0;
  }
  initialized = true;
}

int getMxToLca (int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int ans = -1;
  while (dep[a] != dep[b]) {
    ans = max(ans, dis[a]);
    a = p[a];
  }
  assert(dep[a] == dep[b]);
  while (a != b) {
    ans = max(ans, max(dis[a], dis[b]));
    a = p[a];
    b = p[b];
  }
  assert(a == b);
  return ans;
}

int t = 0;
void cheat(int a, int b) {
  if (t == 0) init();
  t++;
  a = find(a); b = find(b);
  if (a == b) return;
  if (nd[a].size() > nd[b].size()) swap(a, b); // merge a to b
  p[a] = b;
  dis[a] = t;
  for (auto node : nd[a]) {
    dep[node]++;
    nd[b].push_back(node);
  }
}

int investigate(int a, int b) {
  if (!initialized) return -1;
  if (find(a) != find(b)) return -1;
  return getMxToLca(a, b);
}