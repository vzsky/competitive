#include<bits/stdc++.h>
using namespace std;

int cnt[5010];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int h, l, n, mx = 0; cin >> h >> l >> n;
  for (int i = 0; i < n; i++) {
    int a; cin >> a; 
    if (a >= l and a <= l+h) cnt[a]++;
    mx = max(cnt[a], mx);
  }
  cout << mx;
  return 0;
}