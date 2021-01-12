#include<bits/stdc++.h>
using namespace std;

long long dp[1000][1000];

const int mod = 29947;

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int mx = max(a+b, c);
    //TODO construct dp[mx][mx];

    dp[1][1] = 2;
    for(int i = 0; i <= mx; i++) dp[0][i] = dp[i][0] = 1;

    for(int i = 1; i <= mx; i++){
        for(int j = 1; j <= mx; j++){
            if (dp[i][j]) continue;
            if (dp[j][i]) { dp[i][j] = dp[j][i]; continue; }
            dp[i][j] = dp[i][j-1];
            for(int k = 1; k <= i; k++){
                dp[i][j] += dp[i-k][j-1];
                dp[i][j] %= mod;
            }

            // cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    a--;
    b--;
    c--;

    if (a==0 || b==0 || c == 0) {
        if (a == 0) { printf("%lld", dp[b][c]); return 0;}
        if (b == 0) { printf("%lld", dp[a][c]); return 0;}
        if (c == 0) { printf("%lld", dp[b][a]); return 0;}
    }

    long long ans = 0;
    for(int i = 1; i <= a; i++){
        for(int j = 1; j <= b; j++){ 
            // cerr << dp[i-1][j-1] << ' ' << dp[c][a-i+b-j] << endl;
            ans += (dp[i-1][j-1]*dp[c][a-i+b-j])%mod;
            ans %= mod;
        }
    }
    ans += dp[a+b][c];
    ans %= mod;

    printf("%lld", ans);
    return 0;
}