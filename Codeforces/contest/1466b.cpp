#include<bits/stdc++.h>
using namespace std;

int a[100100];
int cnt[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    memset(cnt, 0, sizeof cnt);
    int ans = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (cnt[a[i]] == 0) ans++;
      cnt[a[i]]++;
    }
    bool mark = false;
    for (int i = 1; i <= 2*n+1; i++) {
      if (cnt[i] > 1 and mark == false) { mark = true; cnt[i]--; continue; }
      if (cnt[i] == 0 and mark == true) {
        mark = false; ans++;
        cnt[i] = 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}