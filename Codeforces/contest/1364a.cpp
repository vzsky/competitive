#include<bits/stdc++.h>
using namespace std;

int a[100100];
int qs[100100];
int first[1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    bool flag = false;
    cin >> n >> x;
    // mn = 1
    int mn = -1;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      a[i] %= x;
      if (a[i] != 0) flag = true;
      qs[i] = a[i] + qs[i-1];
      qs[i] %= x;
      if (mn == -1 and qs[i] != 0) { mn = i; }
    }
    if (!flag) cout << -1 << endl;
    else {
      int ans = 1;
      // cerr << "mn " << mn << endl;
      for (int i = 1; i <= n; i++) {
        if (0 == qs[i]) {
          // cerr << i-mn << endl;
          ans = max(ans, i-mn);
        }
        else {
          // cerr << i << endl;
          ans = max(ans, i);
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}