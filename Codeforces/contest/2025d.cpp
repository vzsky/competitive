#include<bits/stdc++.h>
using namespace std;

int a[2000200]; 
int dp[5010], ndp[5010]; // pos = j
int r[2000200];

int fw[5050];
void add (int a, int v) {for (int i = a+1; i <= 5010; i+=(i&-i)) fw[i]+=v;}
int query (int a) {int r = 0; for (int i = a+1; i > 0; i-=(i&-i)) r+=fw[i]; return r;}
void st (int a, int v) { 
  int q = query(a); 
  // cout << "set " << a << " to " << q << endl;
  add(a, v-q); add(a+1, q-v);
}

int main () {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) r[i] = (int)(a[i] == 0) + r[i-1];

  for (int i = 1; i <= n; i++) {
    // cout << "now have " << r[i] << endl;
    if (a[i] == 0) {
      for (int j = r[i]; j >= 1; j--) {
        st(j, max(query(j), query(j-1)));
      }
      // cout << "set till" << r[i] << endl;
    }
    if (a[i] > 0) {
      if (a[i] <= r[i]) { add(a[i], 1); add(r[i]+1, -1); }
      // cout << "add" << a[i] << endl;
    }
    if (a[i] < 0) {
      if (r[i]+a[i]+1 > 0) { add(0, 1); add(r[i]+a[i]+1, -1); }
      // cout << "add to" << r[i]+a[i] << endl;
    }
  }

  int mx = 0;
  for (int i = 0; i <= m; i++) {
    // cout << query(i) << ' ';
    mx = max(mx, query(i));
  }
  cout << mx << endl;

  return 0;
}
