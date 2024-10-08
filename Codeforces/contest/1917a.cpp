#include<bits/stdc++.h>
using namespace std;

int a[110];

int main () {
  int t; 
  cin >> t;
  while (t--) {
    int cn = 0;
    int cz = 0;
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) cz++;
      if (a[i] < 0) cn++;
    }
    if (cz) cout << "0\n";
    else if (cn&1) cout << "0\n";
    else cout << "1\n1 0\n";
    
  }
  return 0;
}
