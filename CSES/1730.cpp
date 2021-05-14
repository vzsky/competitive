#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int s = 0;
    while (n--) {
      int x; cin >> x;
      s ^= x;
    }
    cout << (s?"first":"second") << endl;
  }
  return 0;
}
