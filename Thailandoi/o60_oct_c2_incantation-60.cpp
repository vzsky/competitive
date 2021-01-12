#include <bits/stdc++.h>
using namespace std;

long long dp[10100][200];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    const int mxn = 1<<k;
    const int mxs = 1<<(k-1);

    for(int i = 0; i < mxn; i++){
        scanf("%lld", &dp[0][i]);
    }
    
    for(int j = 0; j < mxs; j++){
        //cerr << mxn << ' ' << j << ' ' << (mxs|j) << endl;
        //cout << dp[0][j] << ' ' << dp[0][mxs|j] << endl;
        dp[1][j] = max(dp[0][j], dp[0][mxs|j]);
        //cout << dp[1][j] << ' ' << j << endl;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < mxs; j++){
            // end with j comes from set i-1 ends with j >> 1 or j >> 1 ^ mxs
            //cerr << j << ' ' << (j>>1) << ' ' << (j|mxs) << ' ' << ((j|mxs)>>1) << endl;
            dp[i][j] = max(dp[0][j]+dp[i-1][j>>1], dp[0][j|mxs]+dp[i-1][(j|mxs)>>1]);
            //cout << "dp " << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }

    long long mx = 0;
    
    for(int i = 0; i <mxs; i++){
        mx = max(mx, dp[n-k+1][i]);
    }
    printf("%lld", mx);
    return 0;
}