#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int a[100100];

int main () {
  int t; cin >> t;
  while (t--) {

    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < m; i++) { a[i] = 0; cin >> a[i]; }
    sort(a, a+m);

    for (int i = 0; i < q; i++) {
      int p; cin >> p;

      int c;
      c = lower_bound(a, a+m, p) - a;

      if (p < a[0]) cout << a[0] - 1 << "\n";
      else if (p > a[m-1]) cout << n - a[m-1] << "\n";
      else {
        cout << (a[c] - a[c - 1]) / 2<< "\n";
      } 

    }

  }
}

