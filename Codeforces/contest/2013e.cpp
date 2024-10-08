#include<bits/stdc++.h>
using namespace std;

#define min(x, y) (x>y?y:x)

int a[100100];

int main () {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    long long ans = 0;  
    long long g = 0;
    long long now = 0;
    
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i == 0) g = a[i];
      g = gcd(g, a[i]);
    }

    sort(a, a+n);

    ans += a[0];
    now = a[0];
    int c = 1;
    while (now != g) {
      for (int i = c; i < n; i++) {
        a[i] = gcd(a[i], now);
      }
      sort(a+c, a+n);
      ans += a[c];
      now = a[c];
      c++;
    }
    ans += (n-c) * g;

    cout << ans << endl;

    
  }
  return 0;
}
