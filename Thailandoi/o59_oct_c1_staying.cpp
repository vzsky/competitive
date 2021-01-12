#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long dp[5][10][3010];

int main(){
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    dp[3][1][0] = 1;
    
    for(int i = 0; i <= n; i++){
        for(int j = 1; j <= a; j++){
            // in a
            if (i+j > n) break;
            for(int k = 1; k <= 7; k++){
                dp[1][k|1][i+j] += dp[3][k][i];
                dp[1][k|1][i+j]%=mod;
               // cerr << "1 " << (k|1) << ' ' << i+j <<  " : " << dp[1][k|1][i+j] << endl;
            }
        }
        for(int j = 1; j <= b; j++){
            // in b
            if (i+j > n) break;
            for(int k = 1; k <= 7; k++){
                //cerr << "from " << dp[1][k][i] << endl;
                dp[2][k|2][i+j] += dp[1][k][i];
                dp[2][k|2][i+j]%=mod;
               // cerr << "2 " << (k|2) << ' ' << i+j <<  " : " << dp[2][k|2][i+j] << endl;
            }
        }
        for(int j = 1; j <= c; j++){
            // in c
            if (i+j > n) break;
            for(int k = 1; k <= 7; k++){
                dp[3][k|4][i+j] += dp[1][k][i];
                dp[3][k|4][i+j]%=mod;
                dp[3][k|4][i+j] += dp[2][k][i];
                dp[3][k|4][i+j]%=mod;
               // cerr << "3 " << (k|3) << ' ' << i+j <<  " : " << dp[3][k|4][i+j] << endl;
            }
        }
    }
    cout << (dp[1][7][n]+dp[2][7][n]+dp[3][7][n])%mod;
    return 0;
}