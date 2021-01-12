#include<bits/stdc++.h>
using namespace std;

long long a[200100], b[200100], c[200100];
vector<int> g[200100];

struct A {
  long long cost, delb, delc;
  A operator + (const A & o) const {
    A temp = {cost + o.cost, delb + o.delb, delc + o.delc};
    return temp;
  }
};

long long value[200100];
void dfs (int u, int p) {
  value[u] = min(a[u], value[u]);
  for (auto x : g[u]) {
    if (x == p )continue;
    value[x] = min(a[x], value[u]);
    dfs(x, u);
  }
}

A solve (int u, int p) {
  A z = {0, b[u], c[u]};
  for (auto x : g[u]) {
    if (x == p) continue;
    auto now = solve(x, u);
    z = z + now;
  }
  // cerr << "fin " << u  << ' ' << z.delb << ' ' << z.delc << endl;
  if (z.delb and z.delc) {
    int mn = min(z.delb, z.delc);
    long long cost = 2*mn*value[u];
    z.delb -= mn;
    z.delc -= mn;
    z.cost += cost;
  }

  // cerr << "return " << u << ' ' << z.cost << ' ' << z.delb  << ' ' << z.delc << endl;
  return z;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i <= n; i++) value[i] = 1e15;
  for (int i = 1; i <= n; i++){
    cin >> a[i] >> b[i] >> c[i];
    if (b[i] and c[i]) {
      b[i] = c[i] = 0;
    }
  }
  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 1);
  // for (int i = 1; i <= n; i++) {
  //   cerr << value[i] << ' ';
  // }
  auto ans = solve(1, 1);
  if (ans.delb != 0 or ans.delc != 0) {
    cout << -1;
    return 0;
  }
  cout << ans.cost << endl;
  return 0;
}