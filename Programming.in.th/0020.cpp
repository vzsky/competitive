#include<bits/stdc++.h>
using namespace std;

int s[10], ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 1; i <= 5; i++) {
    for (int j = 0; j < 4; j++) {
      int x; cin >> x;
      s[i] += x;
    }
    ans = max(ans, s[i]);
  }
  for (int i = 1; i <= 5; i++) {
    if (ans == s[i]) cout << i << ' ' << ans;
  }
  return 0;
}