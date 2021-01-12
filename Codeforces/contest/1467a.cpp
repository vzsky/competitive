#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n == 1) cout << 9;
    else if (n == 2) cout << 98;
    else {
      cout << 989;
      int x = 0;
      for (int i = 3; i < n; i++) {
        cout << x;x++;x%=10;
      }
    }
    cout << endl;
  }
  return 0;
}