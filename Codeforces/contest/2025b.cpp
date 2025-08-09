#include<bits/stdc++.h>

using namespace std;

int mod = 1e9+7;
long long pw[200200];
long long n[200200];
long long k[200200];

int main () {
  int q; cin >> q;
  pw[0] = 1;
  pw[1] = 2;
  for (int i = 2; i < 100100; i++) {
    pw[i] = pw[i-1] + pw[i-1];
    pw[i] %= mod;
  }
  for (int i = 0; i < q; i++) 
    cin >> n[i];
  for (int i = 0; i < q; i++) 
    cin >> k[i];

  for (int i = 0; i < q; i++){ 
    if (n[i] == k[i]) { cout << "1\n"; continue; }
    cout << pw[k[i]] << "\n";
  }
  return 0;
}
