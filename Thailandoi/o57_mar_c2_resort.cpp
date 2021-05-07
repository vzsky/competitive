#include<bits/stdc++.h>
using namespace std;

int a[1010][1010], qs[1010][1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, t; cin >> n >> m >> t;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a[x+1][y+1]++;
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      qs[i][j] = qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+a[i][j];
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= m; j++) {
      if (qs[i][j] >= t) {
        int l = 1, r = j; 
        while (l < r) {
          int mid = (l+r+1)/2;
          if (qs[i][j]-qs[i][mid-1] >= t) l = mid;
          else r = mid-1;
        }
        ans = min(ans, i*j - i*(l-1));
      }
    }
  }
  cout << ans << endl;
  return 0;
}