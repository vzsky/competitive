#include <bits/stdc++.h>
using namespace std;

long long a[100];

int main () {
  int t; cin >> t; 
  while (t--) {
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort (a, a+n); 
    while (n > 1) {
      // cout << n << ' ' << a[0] << ' ' << a[1] << endl;
      a[0] = (a[0] + a[1]) / 2;
      a[1] = 1e15;
      sort (a, a+n); 
      n--;
    }
    cout << a[0] << endl;
  }
  return 0;
}
