#include<bits/stdc++.h>

using namespace std;

int a[200200];

int main () {
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i =0; i< n; i++) cin >> a[i];
    sort(a, a+n);

    int left = 0;
    int ans = 1;
    int mx = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] == a[i-1]) ans++;
      else if (a[i] == a[i-1] + 1) ans++;
      else { ans = 1; left = i;}

      while (a[left] <= a[i] - k) {
        left++;
        ans--;
      }
      mx = max(mx, ans);
    }

    cout << mx << "\n";

  }
  return 0;
}
