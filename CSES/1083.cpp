#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x = 1; cin >> n;
  for (int i = 2; i <= n; i++) { int a; cin >> a; x ^= a ^ i; }
  cout << x;
  return 0;
}