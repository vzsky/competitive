#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
long long mic[2][1000100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  mic[0][1] = mic[1][1] =  1;
  for (int i = 2; i <= 1000000; i++) {
    mic[0][i] = (4*mic[0][i-1]+mic[1][i-1]) % mod;
    mic[1][i] = (mic[0][i-1]+2*mic[1][i-1]) % mod;
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << (mic[0][n]+mic[1][n])%mod << '\n';
  }
  return 0;
}