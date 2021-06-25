#include<bits/stdc++.h>
using namespace std;

int im[210][210];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    im[min(a, b)][max(a, b)] = 1;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i+1; j <= n; j++) {
      for (int k = j+1; k <= n; k++) {
        if (!im[i][j] and !im[i][k] and !im[j][k]) ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
