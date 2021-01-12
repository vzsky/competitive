#include<bits/stdc++.h>
using namespace std;

map<long double, long long> umx, xmu;
long long up = 0, down = 0, l = 0, r = 0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    up = down = l = r = 0;
    umx.clear();
    xmu.clear();
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      long double x, y, u, v; cin >> x >> y >> u >> v;
      if (x == u) {
        if (v > y) {
          up++;
          ans += down;
        }
        else {
          down++;
          ans += up;
        }
      }
      else if (y == v) {
        if (u > x) {
          r++;
          ans += l;
        }
        else {
          l++;
          ans += r;
        }
      }
      else {
        long double s= (v-y)/(u-x);
        if (u > x) {
          umx[s]++;
          ans += xmu[s];
        }
        else {
          xmu[s]++;
          ans += umx[s];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}