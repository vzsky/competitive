#include "supertrees.h"
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> answer;
void connect (int u, int v) { answer[u][v] = answer[v][u] = 1; }

int p[2000];
int find (int u) { return u==p[u]? u:p[u]=find(p[u]); }
bool merge (int i, int j) {
  if (find(i) == find(j)) return false;
  p[find(i)] = find(j);
  connect(i, j);
  return true;
}

vector<int> c;
vector<vector<int>> r;
int n;
void relax(int i) {
  for (int j = i+1; j < n; j++) {
    if (r[i][j] != 0) c.push_back(j);
  }
  c.push_back(i);
  for (auto x : c) {
    for (auto y : c) {
      r[x][y] = r[y][x] = 0;
    }
  }
}

int construct(vector<vector<int>> req) {
  r = req; n = req.size();
	for (int i = 0; i < n; i++) {
		vector<int> row = vector<int>(n);
		answer.push_back(row);
	}
  iota(p, p+n+1, 0);

  for  (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (req[i][j] == 1) merge(i, j);
    }
  }

  for  (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (r[i][j] == 2) {
        c.clear();
        relax(i);
        int first = -1, last = 0;
        for (int x = 1; x < c.size(); x++) {
          if (merge(c[last], c[x])) {
            if (first == -1) first = last;
            last = x;
          }
        } 
        if (first == -1 or c.size() <= 2) return 0;
        connect(c[last], c[first]);
      }
    }
  }

  for  (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (req[i][j] == 0 and find(i) == find(j)) return 0;
      if (req[i][j] == 3) return 0;
    }
  }

  build(answer);
  return 1;
}