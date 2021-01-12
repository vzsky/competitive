#include<bits/stdc++.h>
using namespace std;

int a[200100], rof[200100];
map<int, int> cnt;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, q; cin >> n >> k >> q;
  for (int i = 1; i <= n ; i++) cin >> a[i];
  
  int l = 1, r = 1; cnt[a[1]]++;
  while (l <= n) {
    while (cnt.size() < k && r < n) 
      if (a[++r] <= k) cnt[a[r]]++;
    rof[l] = cnt.size() < k ? -1 : r;
    if (--cnt[a[l]] <= 0) cnt.erase(a[l]);
    l++;
  }

  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    cout << ((rof[l] == -1 || rof[l] > r) ? "NO\n" : "YES\n");
  }

  return 0;
}