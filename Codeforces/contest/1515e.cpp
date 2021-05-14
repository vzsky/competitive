#include<bits/stdc++.h>
using namespace std;

int n, m; 
long long dp[410][410], fact[410], ifac[410], ch[410][410];

long long power (int a, int k) {
  if (k == 0) return 1;
  long long h = power(a, k/2);
  long long e = (h*h) % m;
  if (k&1) return (e*a) % m;
  return e;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = (fact[i-1] * i) % m;
    ifac[i] = power(fact[i], m-2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ch[i][j] = (((fact[i] * ifac[j]) % m) * ifac[i-j]) % m;
    }
  }
  for (int i = 1; i <= n; i++) dp[i][i] = power(2, i-1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 1; k < j; k++) {
        dp[i][j] += (((dp[i-1-k][j-k] * power(2, k-1)) % m) * ch[j][k]) % m;
        dp[i][j] %= m;
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += dp[n][i];
    ans %= m;
  }
  cout << ans << endl;
  return 0;
}