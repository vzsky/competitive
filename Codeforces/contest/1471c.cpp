#include<bits/stdc++.h>
using namespace std;

int a[300100], c[300100], mark[300100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {cin >> a[i]; a[i]--;}
    for (int i = 0; i < m; i++) cin >> c[i];
    sort(a, a+n);
    int ind = 0;
    long long ans = 0;
    for (int i = n-1; i >= 0; i--) {
      if (ind < a[i]) {
        ans += c[ind];
        ind++;
      }
      else {
        ans += c[a[i]];
      }
    }
    cout << ans << endl;
  }
  return 0;
}