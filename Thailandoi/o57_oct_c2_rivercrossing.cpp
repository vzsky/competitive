#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const int N = 50010;
const int mod = 30011;

vector<int> hate[2][50100];
int dp[15][50100];
int fw[50100];
pair<int,int> to[2][50100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k, l; cin >> n >> m >> k >> l;
  for (int i = 0; i < l; i++) {
    int x, y; cin >> x >> y;
    hate[0][x].push_back(y);
    hate[1][y].push_back(x);
  }
  for (int i = 1; i <= max(n, m); i++) { sort(all(hate[0][i])); sort(all(hate[1][i])); }
  for (int x = 0; x < 2; x++) {
    for (int i = 1; i <= n; i++) {
      int a, b; cin >> a >> b;
      int l = b, r = x?n:m;
      while (l < r) {
        int mid = (l+r)/2;
        int bad = upper_bound(all(hate[x][i]), mid) - lower_bound(all(hate[x][i]), b);
        if (mid-b+1 - bad >= a) r = mid;
        else l = mid+1;
      }
      to[x][i] = {b, l};
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) dp[0][i] = 1;
  for (int i = 1, r = 1; i <= k; i++, r^=1) {
    memset(fw, 0, sizeof fw);
    memset(dp[r], 0, sizeof dp[r]);
    for (int j = 1; j <= (r?n:m); j++) {
      for (int i = to[!r][j].first; i <= N; i+=(i&-i)) { fw[i] += dp[!r][j]; fw[i] %= mod; }
      for (int i = to[!r][j].second+1; i <= N; i+=(i&-i)) { fw[i] += mod-dp[!r][j]; fw[i] %= mod; }
      for (auto x : hate[!r][j]) if (x <= to[!r][j].second and x >= to[!r][j].first) {
        dp[r][x] += mod - dp[!r][j];
        dp[r][x] %= mod;
      }
    }
    for (int j = 1; j <= (r?m:n); j++) { 
      for (int i = j; i > 0; i-=(i&-i)) { dp[r][j] += fw[i]; dp[r][j] %= mod; }
    }
    if (r) for (int j = 1; j <= m; j++) { ans+=dp[r][j]; ans %= mod; }
  }
  cout << ans;
  return 0;
}