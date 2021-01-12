#include<bits/stdc++.h>
using namespace std;
int a[100100], tp[100100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) tp[i] = 2e9;
  int mx = 1;
  for (int i = 0; i < n; i++) {
    int f = lower_bound(tp, tp+n, a[i]) - tp;
    tp[f] = a[i]; mx = max(f, mx);
  }
  cout << mx << endl;
  return 0;
}