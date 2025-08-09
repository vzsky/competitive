#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

pair<int, int> p[200];

struct Edge {
  int i, j, d, a;
  bool operator < (const Edge & o) const {
    return d < o.d;
  }
};

vector<Edge> v;
vector<int> qs;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int report; cin >> report;
      int dis = (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
      v.push_back({i, j, dis, report});
    }
  }

  sort(v.begin(), v.end());
  int n2 = v.size();
  qs.resize(n2);
  qs[0] = v[0].a;
  for (int i = 1; i < n2; i ++) {
    qs[i] = qs[i-1] + v[i].a;
  }
  
  int mn = 1e9;
  for (int i = 0; i < n2; i ++) {
    if (v[i].d == v[i+1].d) continue;
    int error = (i+1 - qs[i]) + (qs[n2-1] - qs[i]);
    mn = min(mn, error);
  }
  cout << mn;


  return 0;
}
