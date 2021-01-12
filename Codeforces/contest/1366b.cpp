#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, x, m;
    cin >> n >> x >> m;
    int L = x, R = x;
    for (int j = 0; j < m; j++) {
      int l, r;
      cin >> l >> r;
      if ((l <= L and L <= r) or (l <= R and R <= r)) L = min(L, l), R = max(R, r);
    }
    cout << R-L+1 << endl;
  }
  return 0;
}