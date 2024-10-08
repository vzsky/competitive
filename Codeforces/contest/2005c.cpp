#include <bits/stdc++.h>
using namespace std;

#define max(a, b) a>b?a:b

int scr[10][1010];
int stt[10][1010];
int dp[10][1010];

int main () {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) {
      char s[1010];
      scanf("%s", s);

      for (int og = 0; og < 5; og++) {
        int state = og;
        int score = 0;
        for (int j = 0; j < m; j++) {
          if (s[j] == 'n') {score--; if (state == 0) state++;}
          if (s[j] == 'a') {score--; if (state == 1) state++;}
          if (s[j] == 'r') {score--; if (state == 2) state++;}
          if (s[j] == 'e') {score--; if (state == 3) state++;}
          if (s[j] == 'k') {score--; if (state == 4) {state=0; score += 10;}}
        }
        scr[og][i] = score;
        stt[og][i] = state;
      }

    }

    for (int i = 0; i <= n; i++) {
      for (int k = 0; k < 5; k++) {
        dp[k][i] = -1e9; 
      }
    }

    dp[0][0] = 0;


    for (int i = 1; i <= n; i++) {
      for (int k = 0; k < 5; k++) {
        dp[k][i] = max(dp[k][i], dp[k][i-1]);
        int cand = max(dp[stt[k][i]][i-1], dp[k][i-1] + scr[k][i]);
        dp[stt[k][i]][i] = max(dp[stt[k][i]][i], cand);

        // cout << k << ' ' << i << ' ' << dp[k][i] << endl;
      }
    }

    int ans = 0; 
    for (int i = 0; i < 5; i++) {
      ans = max(ans, dp[i][n]);
    }
    cout << ans << "\n"; 

  }
  return 0;
}

