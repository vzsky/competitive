#include<bits/stdc++.h>
#include <queue>
using namespace std;

#define max(x, y) (x>y?x:y)

vector<int> g[200100];
int from[200100];
int path[200100];

void dfs (int u, int v) {
  from[u] = v;
  for (auto x: g[u]) {
    if (x == v) continue;
    dfs(x, u);
  }
}

long long dfs2 (int u, int v) {
  long long now = 0;
  for (auto x: g[u]) {
    if (x == v) continue;
    if (path[x]) continue;
    now = max(now, dfs2(x, u));
  }
  return now + 1;
}

long long ca[200100], cb[200100];
vector<int> onpath, val;
priority_queue<pair<int,int>> A, B;

int main () {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;

    for (int i = 0; i <= n+5; i++) {
      ca[i] = cb[i] = path[i] = from[i] = 0;
      while(!g[i].empty()) g[i].pop_back();
    }

    while(!A.empty()) A.pop();
    while(!B.empty()) B.pop();
    while(!onpath.empty()) onpath.pop_back();
    while(!val.empty()) val.pop_back();

    for (int i = 0; i < n-1; i++) {
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    int u, v; cin >> u >> v;

    dfs(u, u);

    int now = 1;
    while (now != u) {
      path[now] = 1;
      onpath.push_back(now);
      now = from[now];
    }
    path[u] = 1;
    onpath.push_back(u);

    now = 1;
    while (now != u) {
      val.push_back(dfs2(now, now) -1);
      now = from[now];
    }
    val.push_back(dfs2(u, u) -1);

    int l = onpath.size();
    for (int i = 0; i < l; i++) {
      ca[i] = val[i] + i;
      cb[i] = val[i] + l-1-i;
      A.push({ca[i], i});
      B.push({cb[i], i});
    }
    pair<int,int> ma = A.top(); A.pop();
    pair<int,int> mb = B.top(); B.pop();

    int a = 0, b = l-1;
    while (1) {
      while (mb.second <= a || mb.second > b) { mb = B.top(); B.pop(); }
      if (ca[a++] > mb.first) { cout << "Alice\n"; break; }
      if (a == b) { cout << "Bob\n"; break; }

      while (ma.second < a || ma.second >= b) { ma = A.top(); A.pop(); }
      if (cb[b--] >= ma.first) { cout << "Bob\n"; break; }
      if (a == b) { cout << "Alice\n"; break; }
    }

  }

  return 0;
}
