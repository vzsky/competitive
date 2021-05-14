#include<bits/stdc++.h>
using namespace std;

int tab[3010][3010];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int r, c, e; cin >> r >> c >> e;
  for (int i = 0; i < e; i++) { int a, b; cin >> a >> b; tab[a+1][b+1] = 1; }
  for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) tab[i][j] += max(tab[i-1][j], tab[i][j-1]);
  cout << tab[r][c] << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/