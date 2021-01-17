#include<bits/stdc++.h>
using namespace std;

int a[200];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, d; cin >> n >> d;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      cnt += (a[i] > d);
    }
    bool have = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (a[i]+a[j] <= d) have = 1;
      }
    }
    if (cnt == 0) {
      cout << "Yes" << endl;
      continue;
    }
    if (have) cout << "Yes" << endl;
    if (!have) cout << "No" << endl;
  }
  return 0;
}