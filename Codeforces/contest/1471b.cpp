#include<bits/stdc++.h>
using namespace std;

int a[100100], b[100100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
      ans += a[i];
    }
    while (true) {
      for (int i = 0; i < n; i++) {
        if (b[i] % k != 0) goto end;
        // cout <h< b[i] << endl;
        if (b[i] % k == 0) {
          ans += a[i];
          b[i] /= k;
        }
      }
    }
    end :
    cout << ans << endl;
  }
  return 0;
}