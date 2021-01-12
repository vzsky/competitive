#include<bits/stdc++.h>
using namespace std;

vector<int> g[100100];
struct A {
  long long self, child, grand, super, sub;
} store[100100];
int q[100100];

const long long inf = 1e18;

void dfs (int u, int p) {
  store[u] = {-inf, -inf, -inf, -inf, -inf};
  vector<A> a;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u);
    store[u].child = max(store[u].child, store[x].self);
    store[u].grand = max(store[u].grand, store[x].child);
    store[u].super = max(store[u].super, store[x].grand);
    store[u].sub = max(store[u].sub, max(store[x].sub, q[u] + store[x].super));
    a.push_back({store[x].self, store[x].child, store[x].grand, 0, 0});
  }
  store[u].self = q[u];
  if (a.size() <= 1) return;
  // store[u].sub keep max of itself and all cases produced
  pair<int,int> mself, mchild, mgrand;
  if (a[0].self > a[1].self) mself = {0, 1}; else mself = {1, 0};
  if (a[0].child > a[1].child) mchild = {0, 1}; else mchild = {1, 0};
  if (a[0].grand > a[1].grand) mgrand = {0, 1}; else mgrand = {1, 0};

  for (int i = 2; i < a.size(); i++) {
    if (a[i].self > a[mself.first].self) mself = {i, mself.first};
    else if (a[i].self > a[mself.second].self) mself = {mself.first, i};
    if (a[i].child > a[mchild.first].child) mchild = {i, mchild.first};
    else if (a[i].child > a[mchild.second].child) mchild = {mchild.first, i};
    if (a[i].grand > a[mgrand.first].grand) mgrand = {i, mgrand.first};
    else if (a[i].grand > a[mgrand.second].grand) mgrand = {mgrand.first, i};
  }
  if (mself.first != mgrand.first) store[u].sub = max(store[u].sub, a[mself.first].self + a[mgrand.first].grand);
  store[u].sub = max(store[u].sub, max(a[mself.first].self + a[mgrand.second].grand, a[mself.second].self + a[mgrand.first].grand));
  store[u].sub = max(store[u].sub, a[mchild.first].child + a[mchild.second].child);
  // cerr << u << ' ' << store[u].self << ' ' << store[u].child << ' ' << store[u].grand << ' ' << store[u].super << ' ' << store[u].sub << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> q[i];
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
      int u, v; cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(1, 1);
    cout << (store[1].sub < 0? -1: store[1].sub) << endl; 
  }
  return 0;
}