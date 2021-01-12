#include<bits/stdc++.h>
using namespace std;

#define n first 
#define d second

vector<int> vert;
vector<int> g[300100];
queue<pair<int,int>> q;

map<int,int> co;
vector<pair<int,int>> inp1;
vector<int> inp2;
vector<int> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int l, n, m;
  cin >> l >> n >> m;

  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    inp1.push_back({a, b});
    s.push_back(a); s.push_back(b);
  }
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    inp2.push_back(x);
    s.push_back(x);
  }
  sort(s.begin(), s.end());
  int cnt = 0;
  for (auto x : s) {
    co[x] = cnt++;
  }
  for (int i = 0; i < n; i++) {
    int a = co[inp1[i].first];
    int b = co[inp1[i].second];
    g[a].push_back(b);
  }
  for (int i = 0; i < m; i++) {
    int x = co[inp2[i]];
    vert.push_back(x);
  }
  sort(vert.begin(), vert.end());

  l = co[l];

  q.push({co[0], 0});
  int last = co[0];
  while (!q.empty()) {
    auto t = q.front();
    q.pop();

    for (auto u : g[t.n]) {
      if (u == l) {
        cout << t.d+1 << endl;
        return 0;
      }
      // cerr << u << endl;
      auto loc = upper_bound(vert.begin(), vert.end(), u);
      if (loc == vert.begin()) continue;
      int mxvert = *--loc;
      // cerr << "mxvert = " << mxvert << endl;
      if (last > mxvert) continue;
      for (int i = last+1; i <= mxvert; i++) {
        if (g[i].size() != 0) q.push({i, t.d+2});
      }
      last = mxvert;
    }
  }
  cout << "fuck god no ans" << endl;
  return 0;
}