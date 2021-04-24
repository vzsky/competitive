#include<bits/stdc++.h>
using namespace std;
int t[300100], a[300100], b[300100], c[300100];
vector<int> g[20100], head[20100];
int p[20100], in[20100];
int find (int u) { return u == p[u]? u : p[u] = find(p[u]); }
stack<int> ans;
void topo (int u) {
  ans.push(u);
  for (auto x : g[u]) {
    in[x]--;
    if (in[x] == 0) topo(x);
  }
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, w; cin >> n >> w;
  iota(p, p+n+1, 0);
  for (int i = 0; i < w; i++) {
    cin >> t[i] >> a[i] >> b[i] >> c[i];
    if (t[i] == 3) {
      if (find(a[i]) != find(b[i])) p[find(b[i])] = find(a[i]);
      if (find(a[i]) != find(c[i])) p[find(c[i])] = find(a[i]);
    }
  }
  for (int i = 0; i < w; i++) {
    if (t[i] == 1) {
      g[find(a[i])].push_back(find(b[i]));
      g[find(a[i])].push_back(find(c[i]));
      in[find(b[i])]++;
      in[find(c[i])]++;
    }
    if (t[i] == 2) {
      g[find(b[i])].push_back(find(a[i]));
      g[find(c[i])].push_back(find(a[i]));
      in[find(a[i])]+=2;
    }
  }
  for (int i = 1; i <= n; i++) if (in[find(i)] == 0) {
    topo(find(i)); 
    break; 
  }
  for (int i = 1; i <= n; i++) head[find(i)].push_back(i);
  cout << ans.size() << endl;
  while(!ans.empty()) {
    int x = ans.top(); ans.pop();
    cout << head[x].size() << ' ';
    for (auto e : head[x]) cout << e << ' ';
    cout << endl;
  }
  return 0;
}