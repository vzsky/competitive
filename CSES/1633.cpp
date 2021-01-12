#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int a[1000100];
long long ans (int n) {
  if (n <= 0) return 0;
  if (a[n]) return a[n];
  if (n <= 6) a[n]=1;
  for (int i = 1; i <= 6; i++) {
    a[n] += ans(n-i); a[n] %= mod;
  }
  return a[n];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << ans(n);
  return 0;
}