#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int s = 0;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x;
      if (!(i&1)) s ^= x;
    }
    cout << (s?"first":"second") << endl;
  }
  return 0;
}
