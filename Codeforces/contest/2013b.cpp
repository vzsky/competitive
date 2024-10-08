#include<bits/stdc++.h>
using namespace std;


int main () {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    long long ans = 0;

    long long x, y; 
    if (n == 1) {
      cin >> x; cout << x << endl;
      continue;
    }

    for (int i = 0; i < n-2; i++) { cin >> x; ans += x; }
    cin >> x >> y;
    ans += y - x;
    cout << ans << endl;
  }

  return 0;
}
