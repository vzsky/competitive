#include <bits/stdc++.h>
#include "castle.h"
using namespace std;

set<int> sp;
int N,M,Q,Y;
vector<int> A,B;
vector<int> g[100100];

int p[100100], e[100100];
int find (int u) { return u==p[u]?u:find(p[u]); }
int check (int u) { return u==e[u]?u:e[u]=check(e[u]); }

void dfs (int u, int pa) {
  if (u >= N) return;
  p[u] = pa;
  for (auto x : g[u]) if (x != pa) dfs(x, u);
}

int visited[100100];
stack<int> cleaner;

bool go (int x, int y) {
  if (x == y) return true;
  bool s = false;
  visited[x] = 1;
  cleaner.push(x);
  for (auto i : sp) {
    int a = find(A[i]), b = find(B[i]);
    if (a == b) continue;
    else if (a == x) {
      if (!visited[b]) 
      s |= go (b, y);
    }
    else if (b == x) {
      if (!visited[a])
      s |= go (a, y);
    }
    if (s) break;
  }
  return s;
}

bool merge (int a, int b) {
  if (check(a) == check(b)) return false;
  e[check(a)] = check(b);
  return true;
}

int main() {
  castle_init(N,M,Q,Y);
  castle_read_map(A,B);

  int start = 0;
  for (int i = 0; i < N; i++) e[i] = i;
  
  for (int i = 0; i < M; i++) {
    if (merge(A[i], B[i]) == false) {
      sp.insert(i);
      continue;
    }
    start = A[i];
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }

  dfs(start, start);

  while (Q--) {
    int T,X,Y;
    castle_read_event(T,X,Y);

    if (T == 1) {
      if (sp.find(X) != sp.end()) {
        A[X] = B[X] = -1;
        continue;
      }
      if (p[B[X]] == A[X]) p[B[X]] = B[X];
      else  p[A[X]] = A[X];
    }

    if (T == 2) {
      int status = 0;
      int x = find(X), y = find(Y);
      if (x == y) status = 1;
      status |= go (x, y);

      while (!cleaner.empty()) {
        visited[cleaner.top()] = 0; cleaner.pop();
      }
      castle_answer(status);
    }
  }
}