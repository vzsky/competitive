// THIS ONLY SCORED 53 ;-;
#include "blindwalk.h"
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const long long DIS[4] = {1, 2596418101, 840634349, 590846489};

vector<pair<int,long long>> g[550];
int vis[550];

struct A {
  int x; long long d;
  bool operator < (const A & o) const { return d > o.d; }
};

long long dis (int x, int y) {
  priority_queue<A> heap;
  while (!heap.empty()) {
    auto x = heap.top().x, d = heap.top().d;
    heap.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    if (x == y) return d;
    for (auto u : g[x]) {
      if (!vis[u.first]) heap.push({u.first, d+u.second});
    }
  }
  return -1;
}


vector<vector<int>> build_graph_general(int N) {
  vector<vector<int>> ans;
  vector<vector<long long>> edges;

  for (int i = 0; i < N; i++) for (int j = i+1; j < N; j++) {
    edges.push_back({ask(i, j), i, j});
  }
  sort(all(edges));

  for (int i = 0; i < edges.size(); i++) {
    long long d = edges[i][0], x = edges[i][1], y = edges[i][2];
    memset(vis, 0, sizeof vis);
    if (dis(x, y) == d) continue;

    int choice = 0;
    for (int i = 1; i <= 3; i++) if (d == DIS[i]) choice = i;
    if (d != DIS[choice]) continue;

    ans.push_back(vector<int>({x, y, choice}));
    g[x].push_back({y, DIS[choice]});
    g[y].push_back({x, DIS[choice]});
  }

  return ans;
}

int deg[550];
vector<vector<int>> build_graph_linear_and_cycles(int N) {
  int n = N;
  vector<vector<int>> ans;
  vector<long long> dis;

  int choice;
  long long a = ask(0, n-1);
  for (int i = 1; i <= 3; i++) if (a % DIS[i] == 0) choice = i;
  dis.push_back(a);

  for (int i = 1; i < n-1; i++) dis.push_back(ask(n-1, i));

  queue<pair<int,long long>> q;
  for (int i = 0; i < dis.size(); i++) {
    for (int j = 1; j <= 3; j++) {
      if (dis[i] == DIS[j]) {
        q.push({i, DIS[j]});
        ans.push_back({n-1, i, j});
      }
    }
  }

  int reallast = -1;
  while (!q.empty()) {
    auto last = q.front().first, cumdis = q.front().second;
    reallast = last;
    q.pop();
    bool status = 0, asked = 0;
    for (int i = 0; i < dis.size(); i++) for (int x = 1; x <= 3; x++) {
      if (dis[i] - cumdis != DIS[x]) continue;
      if (asked and status != 1) {
        ans.push_back({i, last, x});
        q.push({i, dis[i]});
        continue;
      } 
      asked = 1;
      if (ask(i, last) == DIS[x]) {
        status = 1;
        ans.push_back({i, last, x});
        q.push({i, dis[i]});
      }
    }
  }

  for (int i = 0; i < ans.size(); i++) {
    deg[ans[i][0]]++; deg[ans[i][1]]++;
  }

  for (int i = 0; i < n; i++) if (deg[i] == 1) {
    for (int j = 1; j <= 3; j++) if (ask(reallast, i) == DIS[j]) ans.push_back({reallast, i, j});
  }
  return ans;
}

vector<vector<int>> build_graph(int N) {
  // for general graphs
  // return build_graph_general(N);
  // for linear and cycles
  // return build_graph_linear_and_cycles(N);
  return vector<vector<int>>();
}

/*
BEST from contest
[ 1 Type
  Any           : [(1225)(124750)(124750)]
  Line          : [(579)(568)(221)(57)]
  2-Reg         : [(297)(747)(747)(72)]
  Line or 2 Reg : [(635)(747)(747)(747)(72)(58)]
  Tree          : [(99233)(523)(25393)]
  3 Type
  Any           : [(1225)(124750)(124750)]
  Line          : [(224)(49)(577)(665)]
  2-Reg         : [(749)(74)(500)(299)]
  Line or 2 Reg : [(55)(74)(741)(738)(500)(611)]
  Tree          : [(1492)(101629)(25280)]
]
This code result
[ 1 Type
  Any           : [(1225)(124750)(124750)]
  Line          : [(997)(997)(397)(97)]
  2-Reg         : [(397)(997)(997)(97)]
  Line or 2 Reg : [(997)(997)(997)(997)(97)(97)]
  Tree          : [(130305)(1953)(32385)]
  3 Type
  Any           : [(1225)(124750)(124750)]
  Line          : [(398)(98)(998)(998)]
  2-Reg         : [(998)(98)(998)(398)]
  Line or 2 Reg : [(98)(98)(998)(998)(998)(998)]
  Tree          : [(1953)(130305)(32385)] 
]
*/