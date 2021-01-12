#include <bits/stdc++.h>
#include "castle.h"

using namespace std;

set<int> sp;
int N,M,Q,Y;
vector<int> A,B;

int p[100100];
int find (int u) {
  if (u == p[u]) return u;
  return find (p[u]);
}

vector<int> g[100100];

void dfs (int u, int pa) {
  if (u >= N) return;
  p[u] = pa;
  for (auto x : g[u]) {
    if (x == pa) continue;
    dfs(x, u);
  }
}

int visited[100100];

stack<int> cleaner;

bool go (int x, int y) {
  if (x == y) return true;
  bool s = false;
  visited[x] = 1;
  cleaner.push(x);
  for (auto i : sp) {
    int a = find(A[i]);
    int b = find(B[i]);
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

int e[100100];
int check (int u) {
  if (u == e[u]) return u;
  return e[u] = check (e[u]);
}
bool merge (int a, int b) {
  if (check(a) == check(b)) return false;
  e[check(a)] = check(b);
  return true;
}

int main() {
  castle_init(N,M,Q,Y);
  castle_read_map(A,B);

  // assert(N==M);

  int start = 0;
  for (int i = 0; i < N; i++) {
    e[i] = i;
  }
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
      // cerr << A[X] << ' ' << B[X] << endl;
      if (sp.find(X) != sp.end()) {
        A[X] = B[X] = -1;
        continue;
      }
      if (p[B[X]] == A[X]) { // A is p
        p[B[X]] = B[X];
        // cerr << "B " << B[X] << endl;
      }
      else { // B is p
        p[A[X]] = A[X];
        // cerr << "A " << A[X] << endl;
      }
    }

    if (T == 2) {
      int status = 0;
      int x = find(X);
      int y = find(Y);
      // cerr << X << ' ' << Y << ' ' << x << ' ' << y << endl;
      if (x == y) {
        status = 1;
      }
      
      // if (A[sp[0]] != -1 and B[sp[0]] != -1) {
      //   // cerr << A[i] << ' ' << B[i] << endl;
      //   int a = find(A[sp[0]]);
      //   int b = find(B[sp[0]]);
      //   if ((x == a and y == b) or (x == b and y == a)) status = 1;
      // }

      status |= go (x, y);
      while (!cleaner.empty()) {
        visited[cleaner.top()] = 0;
        cleaner.pop();
      }
      castle_answer(status);
    }
  }

}