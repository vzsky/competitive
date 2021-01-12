#include<bits/stdc++.h>
using namespace std;

char a[7010][7010];
int cnt[7010], dp[7010][7010];

int main(){
  int n, m, tot = 0;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++){
    scanf(" %s", a[i]+1);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '1')
        dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
      cnt[dp[i][j]]++;
      if (dp[i][j]) tot++;
    }
  }

  for (int i = 1; i <= min(n, m); i++) {
    cout << tot << endl;
    tot -= cnt[i];
  }
  return 0;
}