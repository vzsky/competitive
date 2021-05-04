#include<bits/stdc++.h>
using namespace std;

map<int,int> m, s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t; 
  while(t--) {
    int n, l, r; cin >> n >> l >> r;
    m.clear();
    s.clear();
    int cntl = 0, cntr = 0;
    for (int i = 0; i < l; i++) {
      int a; cin >> a;
      m[a]++;
      cntl++;
    }
    for (int i = 0; i < r; i++) {
      int a; cin >> a;
      if (m[a] != 0) {
        m[a]--;
        cntl--;
      }
      else {
        cntr++;
        s[a]++;
      }
    }
    int ans = 0;
    if (cntr == cntl) {
      ans += cntl;
      cout << ans << endl;
      goto next;
    } 
    else {
      for (int i = 1; i <= n; i++) {
        while (m[i] >= 2 and cntl > cntr) {
          m[i]-=2;
          cntl-=2;
          ans += 1;
          if (cntr == cntl) {
            ans += cntl;
            cout << ans << endl;
            goto next;
          }
        }
        while (s[i] >= 2 and cntr > cntl) {
          s[i]-=2;
          ans += 1;
          cntr-=2;
          if (cntr == cntl) {
            ans += cntl;
            cout << ans << endl;
            goto next;
          }
        }
      }
      // cerr << cntr << ' ' << cntl << endl;
      ans += max(cntr, cntl);
      cout << ans << endl;
      goto next;
    }
    next : continue;
  }
  return 0;
}