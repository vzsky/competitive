#include<bits/stdc++.h>
using namespace std;

#define min(x,y) (x>y?y:x)

int main () {
  int t; cin >> t;
  while (t--) {
    int n, m, k; cin >> n >> m >> k;
    int ans = (n / min(m, k)) + (n % min(m, k) != 0);
    cout << ans << endl;
  }

  return 0;
}
