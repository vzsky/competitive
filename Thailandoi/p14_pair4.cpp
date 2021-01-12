#include<bits/stdc++.h>
using namespace std;

char a[1010];
int dp[1010][1010];

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf(" %c", &a[i]);
    }
    int p;
    for(int m = 1; m <= k; m++){
        for(int i = 1; i <= k; i++){
            int j = i+m; 
            if (j > k) continue;

            if (a[i-1] == a[j-1])   dp[i][j] = max(dp[i][j], dp[i+1][j-1]+1);
            dp[i][j] = max(max(dp[i][j], dp[i][j-1]), dp[i+1][j]);

            for(int l = i; l < j; l++){
                dp[i][j] = max(dp[i][j], dp[i][l]+dp[l+1][j]);
            }

            // cerr << i << ' ' << j << ' ' << dp[i][j] << endl;
        }
    }
    printf("%d", dp[1][k]);
    return 0;
}