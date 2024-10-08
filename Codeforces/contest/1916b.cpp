#include<bits/stdc++.h>
using namespace std;


int main () {
  
  int t; cin >> t; 
  while (t--) {
    long long a, b; cin >> a >> b;
    long long g = gcd(a, b);
    long long p = -1;
    // for (int i = 2; i <= b; i++) {
      // if (b % i == 0) {
        // p = i; break;
      // }
    // }

    if (a == 1) cout << b*b << '\n';
    else if (a*b/g == b) cout << a*b/g * (b/a) << '\n';
    else cout << a*b/g << '\n';

  }

  return 0;
}
