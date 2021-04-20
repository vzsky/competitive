#include<bits/stdc++.h>
using namespace std;

struct A {
  int u, v, d;
  bool operator < (const A & o) const {
    return d < o.d;
  }
};

vector<A> edge;
int ans [5010], p[5010];
int find (int u) { return u==p[u]?u:p[u]=find(p[u]); }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, q; cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    p[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    edge.push_back({a, b, c});
  }

  memset(ans, -1, sizeof ans);
  int comp = n;
  ans[comp] = 0;
  sort(edge.begin(), edge.end());
  for (auto [u, v, d] : edge) {
    if (find(u) == find(v)) continue;
    p[find(u)] = find(v); comp--;
    if (ans[comp] == -1) ans[comp] = d;
  }
  
  while (q--) {
    int d; cin >> d;
    cout << ans[d] << endl;
  }

  return 0;
}