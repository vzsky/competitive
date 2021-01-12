#include<bits/stdc++.h>
using namespace std;

int tab[305][305];
  

bool solve (int n, int m) {
  bool s = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> tab[i][j];
      if ((i == 1 and j == 1) or (i == 1 and j == m) or (i == n and j == 1) or (i == n and j == m)) {
        if (tab[i][j] > 2) s = false;
        tab[i][j] = 2;
      }
      else if (i == 1 or j == 1 or i == n or j == m) {
        if (tab[i][j] > 3) s = false;
        tab[i][j] = 3;
      }
      else {
        if (tab[i][j] > 4) s =  false;
        tab[i][j] = 4;
      }
    }
  }
  return s;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    bool s = solve(n, m);
    if (s) {
      cout << "YES" << endl;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << tab[i][j] << ' ';
        }
        cout << endl;
      }
    }
    else {
      cout << "NO" << endl;
    }
  }
  return 0;
}