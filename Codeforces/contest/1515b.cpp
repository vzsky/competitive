#include<bits/stdc++.h>
using namespace std;

bool isSquare(long long n) {
  
  for (int i = 1; i <= sqrt(n); i++) {
    if (i*i == n) return true;
  }
  return false;
}

bool solve (long long n) {
  if (isSquare(n)) return true;
  if (n&1) return 0;
  return solve (n/2);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  // for (int i = 1; i <= t; i++) {
  //   if (isSquare(i)) cout << i << endl;
  // }
  while (t-- ){
    long long n; cin >> n;
    // if (n%2==0 and solve(n/2))
    cout << ((n%2==0 and solve(n/2))?"YES":"NO") << endl;
  }
  return 0;
}