#include<bits/stdc++.h>
using namespace std;

int bita[65];
long long sum;
long long x[500100];
long long now[500100];
long long iandall[500100];

const long long mod = 1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--) {

    memset(bita, 0, sizeof bita);
    memset(now, 0, sizeof now);
    memset(iandall, 0, sizeof iandall);
    memset(x, 0, sizeof x);
    sum = 0;

    int n; cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> x[j];
      sum += (x[j] % mod);
      sum %= mod;
    
      for (int i = 0; i < 60; i++) {
        bita[i] += (bool)(x[j] & (1ll<<i));
      }
    }


    // cerr << sum << endl;

    for (int i = 0; i < n; i++) {
      now[i] = (sum + ((x[i] % mod) * n) % mod) % mod;
      for (int j = 0; j < 60; j++) {
        if (x[i] & (1ll<<j)) {
          iandall[i] += (bita[j] * ((1ll<<j) % mod)) % mod;
          iandall[i] %= mod;
        }
      }
      now[i] -= iandall[i];
      now[i] %= mod;
      now[i] += mod;
      now[i] %= mod;
      // cerr << iandall[i] << endl; 
      // cerr << now[i] << endl; 
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (iandall[i] * now[i]) % mod;
      ans %= mod;
    }
    cout << ans << endl;
  }
  
  return 0;
}