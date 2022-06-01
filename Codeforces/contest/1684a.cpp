#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    string a; cin >> a; 
    if (a.size() == 2) cout << a[1];
    else {
      int x = 1000000;
      for (char i : a) {
        x = min(i-'0', x);
      }
      cout << x;
    }
    cout << '\n';
  }
  return 0;
}