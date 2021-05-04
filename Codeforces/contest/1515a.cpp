#include<bits/stdc++.h>
using namespace std;

int a[1010], qs[1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int x, n; cin >> n >> x;
    for (int i = 1; i <= n; i++ ){
      cin >> a[i];
    }
    sort(a+1, a+1+n);
    for (int i = 1; i <= n; i++) {
      qs[i] = qs[i-1]+a[i];
    }
    int s = -1;
    if (qs[n] == x) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      if (qs[i] == x) {
        // assert(s != -1);
        s = i; continue;
      }
      cout << a[i] << ' ';
    }
    if (s != -1) cout << a[s];
    cout << endl;
  }
  return 0;
}