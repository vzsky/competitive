#include<bits/stdc++.h>
using namespace std;

#define min(x, y) (x>y?y:x)
#define max(x, y) (x>y?x:y)

long long a[200100];

int main () {
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    long long l = 0, r = 1e12 + 5;
    while (l < r) {
      long long k = (l+r)/2;

      // cout << "do " << k << endl;

      long long ll = 1, rr = 1e12 + 5;
      bool status = false;
      while (ll < rr) {
        status = false;
        long long s = (ll+rr)/2;
        
        // cout << s << " to " << s+k << endl;

        long long low = 0, high = 0;
        long long bot = s, top = s+k;
        for (int i = 1; i <= n; i++) {

          low = (a[i] + low - top);
          high = (a[i] + high - bot);

          // cout << "lh " << low << ' ' << high << endl; 

          if (high < 0) { rr = s; break; }

          low = max(0, low);

        }
        if (low < 0) continue;
        else if (low > 0) { ll = s+1; }
        else {ll = rr = s; status = true;}
        
      }

      if (status) r = k; 
      else l = k+1;

    }

    cout << l << endl;

  }

  return 0;
}
