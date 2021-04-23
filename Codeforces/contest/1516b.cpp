#include<bits/stdc++.h>
using namespace std;

int a[2020], qs[2010];

bool solve (int n) {
  map<int,int> past;
    if (qs[n] == 0 and n >= 2) return true;
    else {
      for (int i = 1; i <= n; i++) {
        if (qs[i] == 0 and past[qs[n]]) return true;
        past[qs[i]] = 1;
      }
    }
    return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      qs[i] = qs[i-1] ^ a[i];
    }
    cout << (solve(n)? "YES" : "NO") << '\n';
  }
  return 0;
}