#include<bits/stdc++.h>
using namespace std;

int a[200100], qs[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) { cin >> a[i]; a[i+n] = a[i]; }
  pair<int,int> ans = {-1, -1};
  for (int i = 1; i <= 2*n; i++) qs[i] = qs[i-1]+a[i];
  for (int i = 1; i <= n; i++) {
    if (ans.first != -1) continue;
    int l = i, r = i+n-1;
    while (l < r) {
      int mid = (l+r+1)/2;
      if (qs[mid]-qs[i-1] <= qs[i+n-1]-qs[mid]) l = mid;
      else r = mid-1;
    }
    if (qs[l]-qs[i-1] == qs[i+n-1]-qs[l]) ans = {i, l};
  }

  if (ans.first == 1) cout << ans.second;
  else if (ans.first == -1) cout << "NO";
  else cout << ans.first-1 << ' ' << ans.second;

  return 0;
}