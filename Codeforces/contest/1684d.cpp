#include<bits/stdc++.h>
using namespace std;

int a[200200];
pair<int,int> dp[200200];
pair<int,int> rev[200200];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += i;
      dp[i] = {a[i], i};
    }
    sort(dp, dp+n);
    for (int i = 0; i < n-k; i++) {
      rev[i] = {dp[i].second, dp[i].first};
      // cout << rev[i].second << ' ';
    }
    // cout << endl;
    sort(rev, rev+n-k);

    long long ans = 0;
    long long count = 0;
    for (int i = 0; i < n-k; i++) {
      ans += rev[i].second - count;
      count ++;
    }
    cout << ans << '\n';
    
  }
  return 0;
}