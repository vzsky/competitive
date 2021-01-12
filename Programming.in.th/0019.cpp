#include<bits/stdc++.h>
using namespace std;

int s[15], b[15];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n; int ans = 2e9;
  for (int i = 1; i <= n; i++) cin >> s[i] >> b[i];
  for (int i = 1; i < 1<<n; i++) {
    int prods = 1, sumb = 0;
    for (int j = 1; j <= n; j++) {
      if (i & 1<<(j-1)) {
        prods *= s[j];
        sumb += b[j];
      }
    }
    ans = min(ans, abs(prods - sumb));
  }
  cout << ans;
  return 0;
}