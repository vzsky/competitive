#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int a1, a2, a3; cin >> a1 >> a2 >> a3;
    int c1, c2, c3, c4, c5; cin >> c1 >> c2 >> c3 >> c4 >> c5;
    a1 -= c1; a2 -= c2; a3 -= c3;
    if (a1 < 0 || a2 < 0 || a3 < 0) {
      cout << "NO" << endl; continue;
    }
    int m = min(a1, c4);
    a1 -= m;
    a3 -= (c4-m);
    m = min(a2, c5);
    a2 -= m;
    a3 -= (c5-m);
    if (a1 < 0 || a2 < 0 || a3 < 0) {
      cout << "NO" << endl; continue;
    }
    cout << "YES" << endl;
  }
  return 0;
}