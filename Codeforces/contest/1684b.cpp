#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int a, b, c; cin >> a >> b >> c;
    cout << 2*c + b + a << ' ' << 2*c + b << ' ' << c << '\n';
  }
  return 0;
}