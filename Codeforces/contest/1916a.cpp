#include<bits/stdc++.h>
using namespace std;

int b[10];

int main () {
  int t; cin >> t; 
  while (t--) {
    int n, k; cin >> n >> k;
    int sev = 0, svt = 0;
    int now = 1;
    int oth = 1;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      // cout << "here"  << b[i] << endl;
      while (b[i] % 7 == 0) {sev++; b[i]/=7; now*=7;}
      while (b[i] % 17 == 0) {svt++; b[i]/=17; now*=17;}
      oth *= b[i];
    }

    // cout << sev << ' ' << svt << ' ' << oth << ' ' << now << endl;

    if (sev > 1 || svt > 2 || oth != 1) cout << "NO\n"; 
    else {
      cout << "YES\n"; cout << 2023/now << " "; 
      for (int i = 0; i < k-1; i++) cout << 1 << " ";
      cout << "\n";
    }
  }
  return 0;
}
