#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    int mx = max(a, b);
    int mn = min(a, b);
    
    int d = mx-mn;
    int ans = 0;
    if (mx >= 2*d and mn >= d) {
      ans += d;
      mx -= 2*d; 
      mn -= d;
      if (mn != 0 and mx != 0) {
        assert(mx == mn);
        ans += ( mx / 3 ) * 2;
        mx %= 3;
        mn %= 3;
        if (mx == 2) {
          ans ++;
        }
      }
    }
    else if (mn < d) {
      ans += mn;
      mx -= 2*mn;
      mn -= mn;
    }
    
    cout << ans << endl;
  }
  return 0;
}