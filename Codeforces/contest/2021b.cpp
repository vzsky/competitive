#include <bits/stdc++.h>
#include <iostream>
using namespace std;

#define min(x, y) (x>y)?y:x

int main () {
  int t; cin >> t;
  while (t--) {
    map<int,int> m;
    int n; cin >> n;
    long long x; cin >> x;
    for (int i = 0; i < n; i++) {
      int aaa; cin >> aaa; 
      m[aaa]++;
    }

    for (int i = 0; i < n+5; i ++) {
      if (i%x != i) m[i % x] += m[i];
      if (m[i % x] == 0) {
        cout << i << '\n';
        break;
      }
      m[i % x]--;
    }

  
  }
  return 0;
}
