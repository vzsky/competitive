#include<bits/stdc++.h>
using namespace std;

// handle the add and mul operations: with mod
// use the library

int dp[310][310][310];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, x, y;
  int c = 0;
  cin >> n >> x >> y;

  if (x == 1) c = dp[1][1][0] = 1;
  else dp[1][1][1] = 1;

  for (int i = 2; i <= n; i++){
    for (int j = 1; j <= i; j++){
      for (int l = 0; l <= 300; l++){
        if (i == x or i == y) dp[i][j][l] = dp[i-1][j-1][l] + dp[i-1][j][l];
        else dp[i][j][l] = (2*j-c)*dp[i-1][j][l] + (j-c)*dp[i-1][j-1][l-1] + j*dp[i-1][j+1][l-1];
      }
    }
    if (i == x or i == y) c++;
  }

  while (true) {
    int a;
    cin >> a;
    cout << dp[n][1][a] << endl;
  }

  return 0;
}