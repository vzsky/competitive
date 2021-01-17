#include<bits/stdc++.h>
using namespace std;

int fw[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b, c; cin >> a >> b >> c;
    if (a == 1) {
      for (int i = c; i <= n; i+=(i&-i)) fw[i] += b;
    }
    if (a == 2) {
      int ans = 0;
      for (int i = c; i > 0; i-=(i&-i)) ans += fw[i];
      for (int i = b-1; i > 0; i-=(i&-i)) ans -= fw[i];
      cout << ans << '\n';
    }
  }
  return 0;
}