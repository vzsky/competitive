#include<bits/stdc++.h>
using namespace std;

int fw[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a; cin >> a;
    if (a == 1) {
      int b, c, d; cin >> b >> c >> d;
      for (int i = b; i <= n; i+=(i&-i)) fw[i] += d;
      for (int i = c+1; i <= n; i+=(i&-i)) fw[i] -= d;
    }
    if (a == 2) {
      int b; cin >> b;
      int ans = 0;
      for (int i = b; i > 0; i-=(i&-i)) ans += fw[i];
      cout << ans << '\n';
    }
  }
  return 0;
}