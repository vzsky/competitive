#include<bits/stdc++.h>
using namespace std;

int dp[101][101][101][101];
int n, m, a, b;
const int mod = 1e9+7;

int solve (int i, int j, int k, int l) {
    if (i < 0 or j < 0 or k < 0 or l < 0) return 0;
    if (dp[i][j][k][l] != -1) return dp[i][j][k][l];
    if (i == 0 and j == 0) return 1;
    return dp[i][j][k][l] = (solve(i-1, j, k-1, b)%mod + solve(i, j-1, a, l-1)%mod)%mod;
}

int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    a = min(a, n); b = min(b, m);
    memset(dp, -1, sizeof dp);
    printf("%d", solve(n, m, a, b));
    return 0;
}