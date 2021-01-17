#include<bits/stdc++.h>
using namespace std;

int qs[200100];
int a[200100];
int mxf[200100];
int mxb[200100];
int mnf[200100];
int mnb[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, qu;
    string s;
    cin >> n >> qu >> s;
    for (int i = 0; i < n; i++) {
      if (s[i] == '+') a[i] = 1;
      else a[i] = -1;
      qs[i+1] = qs[i] + a[i];
    }
    for (int i = 1; i <= n+1; i++) {
      mxf[i] = -1e9;
      mxb[i] = -1e9;
      mnf[i] = 1e9;
      mnb[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
      mxf[i] = max(mxf[i-1], qs[i]);
      mnf[i] = min(mnf[i-1], qs[i]);
    }
    for (int i = n; i >= 1; i--) {
      mxb[i] = max(mxb[i+1], qs[i]);
      mnb[i] = min(mnb[i+1], qs[i]);
    }
    mxf[0] = mnf[0] = mnb[n+1] = mxb[n+1] = 0; 
    // for (int i = 1; i <= n; i++) {
    //   cout << mnb[i] << ' ';
    // } cout << endl;
    while (qu--) {
      int l, r; cin >> l >> r;
      int change = -(qs[r] - qs[l-1]);

      // cerr << "C
      [l-1] << ' ' << mxf[l-1] << ' ' << mnb[r+1] << ' ' << mxb[r+1] << endl;

      if (r+1 > n) {
        cout << mxf[l-1] - mnf[l-1] + 1 << endl;
        continue;
      }

      l--; r++;

      if ((mnf[l] < mnb[r]+change and mxf[l] < mnb[r]+change) or (mnb[r]+change < mnf[l] and mxb[r]+change < mnf[l])) {
        // cerr << "here" << endl;
        cout << mxf[l] - mnf[l] + mxb[r] - mnb[r] + 2<< endl;
      }
      else {
        int mx = max(mxf[l], mxb[r]+change);
        int mn = min(mnf[l], mnb[r]+change);
        cout << mx-mn+1 << endl;
      }
    }
  }
  return 0;
}