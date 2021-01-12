#include<bits/stdc++.h>
using namespace std;

int a[1010];
int sum[1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
   
  string s;
  cin >> s;

  sum[0] = 0;
  for (int i = 0; i < s.size(); i++) {
    a[i+1] = s[i] == '1';
    sum[i+1] = a[i+1];
    sum[i+1] += sum[i]; 
  }

  int n = s.size();

  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    // i is breakpoint;
    // 1 0 
    ans = min(ans, i - sum[i] + sum[n] - sum[i]);
    // 0 1
    ans = min(ans, sum[i] + n - i - sum[n] + sum[i]);
  }
  cout << ans << endl;
  }
  return 0;
}