#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    long long mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mx += (a/k);
      if (a % k != 0) mx++;
      mn += a;
    }
    if (mn % k != 0) {
      mn = (mn/k);
      mn++;
    }
    else {
      mn /= k;
    }
    cout << mn << ' ' << mx << endl;
  }
  return 0;
}