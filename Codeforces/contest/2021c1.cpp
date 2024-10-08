#include <bits/stdc++.h>
using namespace std;

int a[200200], b[200200];
int done[200200];

bool check (int m) {
    int now = 0;
    for (int i = 0; i < m; i++) {
      if (done[b[i]]) continue;
      if (b[i] == a[now]) {
        done[a[now]] = 1; now++;
        continue;
      }
      return false; 
  } return true;
}

int main () {
  int t; cin >> t;
  while (t--) {
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; i++) { cin >> a[i]; done[a[i]] = 0; }
    for (int i = 0; i < m; i++) { cin >> b[i]; }

    cout << (check(m)? "YA": "TIDAK") << '\n';
  }
  return 0;

}
