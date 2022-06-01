#include<bits/stdc++.h>
using namespace std;

int p[100100];
int mark[100100];

int dfs (int root, int par) {
  if (root == par) return 1;
  mark[root] = 1;
  return 1 + dfs(p[root], par);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) mark[i] = 0;
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
      if (mark[i]) continue;
      int s = dfs(p[i], i);
      mark[i] = 1;
      if (s == 1) ans = max(ans, 1);
      else if (s % 2 == 0) ans = max(ans, 2);
      else ans = max(ans, 3);
    }
    cout << ans << endl;
  }
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE
3
2
1 2
3
2 3 1
6
2 3 1 6 4 5
*/