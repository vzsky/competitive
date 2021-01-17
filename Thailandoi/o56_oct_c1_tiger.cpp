#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int,int> point;

int dist (point a, point b) { return abs(a.x - b.x) + abs(a.y - b.y); }
point a[1010];
map<int,int> mp;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, mx = 0; cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
  for (int i = 0; i < m; i++) {
    int mn = 1e9;
    point p; cin >> p.x >> p.y;
    for (int j = 0; j < n; j++) mn = min(mn, dist(a[j], p));
    mx = max(mx, ++mp[mn]);
  }
  cout << mx;
  return 0;
}