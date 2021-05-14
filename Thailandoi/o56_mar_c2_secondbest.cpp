#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

vector<tuple<int,int,int>> edges, mst, rest;
int p[100100], l[200100], r[200100];
long long mstcost = 0;
vector<int> mid[200100];
int find (int u) { return u==p[u]?u:p[u]=find(p[u]); }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) p[i] = i;
  for (int i = 1; i <= m; i++) {
    int a, b, c; cin >> a >> b >> c;
    edges.push_back({c, a, b});
  }
  sort(all(edges));
  for (auto [c, a, b] : edges) {
    if (find(a) == find(b)) {
      rest.push_back({c, a, b});
      continue;
    }
    p[find(a)] = find(b);
    mstcost += c;
    mst.push_back({c, a, b});
  }
  for (int i = 0; i < rest.size(); i++) {
    l[i] = 0, r[i] = mst.size();
  }
  bool done = false;
  while (!done) {
    done = true;
    for (int i = 0; i < rest.size(); i++) {
      if (l[i] == r[i]) continue;
      done = false;
      mid[(l[i]+r[i])>>1].push_back(i);
    }
    for (int i = 1; i < n; i++) p[i] = i;
    for (int i = 0; i < mst.size(); i++) {
      auto [c, a, b] = mst[i];
      if (find(a)!=find(b)) p[find(a)] = find(b);
      for (auto x : mid[i]) {
        auto [d, u, v] = rest[x];
        if (find(u) == find(v)) r[x] = i;
        else l[x] = i+1;
      } mid[i].clear();
    }
  }
  int mn = 1e9;
  for (int i = 0; i < rest.size(); i++) {
    mn = min(mn, get<0>(rest[i]) - get<0>(mst[l[i]]));
  }
  cout << mn+mstcost << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/