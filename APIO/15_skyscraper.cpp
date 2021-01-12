#include<bits/stdc++.h>
using namespace std;

struct A {
  long long n, w;
  bool operator < (const A & o) const {
    return w > o.w;
  } 
};

vector<int> P[30100];
int visited[30100];
long long dis[30100];
priority_queue<A> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, s, e;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int b, p;
    cin >> b >> p;
    P[b].push_back(p);
    if (i == 0) s = b;
    if (i == 1) e = b;
  }

  for (int i = 0; i <= n; i++) dis[i] = 1e18;

  heap.push({s, 0});

  while (!heap.empty()) {
    auto t = heap.top(); heap.pop();
    if (visited[t.n]) continue;
    visited[t.n] = 1;
    dis[t.n] = t.w;

    if (t.n == e) {
      cout << t.w << endl;
      return 0;
    }

    for (auto p : P[t.n]) {
      for (int j = 1; t.n - j*p >= 0; j++) {
        if (t.w+j < dis[t.n-j*p]) {
          dis[t.n-j*p] = t.w+j;
          heap.push({t.n - j*p, t.w+j});
          // cerr << "push " << t.n - j*p << ' ' << t.w+j;
        }
      }
      for (int j = 1; t.n + j*p < n; j++) {
        if (t.w+j < dis[t.n+j*p]) {
          dis[t.n+j*p] = t.w+j;
          heap.push({t.n + j*p, t.w+j});
          // cerr << "push " << t.n + j*p << ' ' << t.w+j;
        }
      }
    }
  }
  cout << -1 << endl;
  return 0;
}