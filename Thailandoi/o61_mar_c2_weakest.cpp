#include<bits/stdc++.h>
using namespace std;

int dp[20][100100], mx[20][100100], lev[100100];
vector<int> g[100100];

void dfs (int r = 0, int p = 0, int l = 1) {
    lev[r] = l;
    for(auto x : g[r]) {
        if (x == p) continue;
        dfs(x, r, l+1);
    }
}

int lca(int a, int b){
    int ans = 2e9;
    if (lev[a] < lev[b]) swap(a, b);
    for(int i = 19; i >= 0; i--){
        if (lev[dp[i][a]] >= lev[b]){
            ans = min(ans, mx[i][a]);
            a = dp[i][a]; 
        }
    }
    assert(lev[a] == lev[b]);
    if (a==b) return ans==2e9?0:ans;
    for(int i = 19; i >= 0; i--){
        if (dp[i][a] != dp[i][b]) {
            ans = min(ans, min(mx[i][a], mx[i][b]));
            a = dp[i][a];
            b = dp[i][b];  
        }
    }
    assert(dp[0][a] == dp[0][a]);
    return min(ans, min(mx[0][a], mx[0][b]))==2e9?0:min(ans, min(mx[0][a], mx[0][b]));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < 20; i++){
        for(int j = 0; j < n; j++){
            mx[i][j] = 2e9;
        }
    }
    for(int i = 1; i < n; i++){
        scanf("%d %d", &dp[0][i], &mx[0][i]);
        g[i].push_back(dp[0][i]);
        g[dp[0][i]].push_back(i);
    }
    dfs();
    for(int i = 1; i < 20; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
            mx[i][j] = min(mx[i-1][j], mx[i-1][dp[i-1][j]]);
        }
    }
    int q, k, m, a1, a2, ans;
    scanf("%d %d %d %d %d", &q, &k, &m, &a1, &a2);
    ans = lca(a1, a2);
    printf("%d\n", ans);
    for(int i = 2; i <= q; i++){
        a1 = a2;
        a2 = ((a2*k+ans)%m)%n;
        ans = lca(a1, a2);
        printf("%d\n", ans);
    }
    return 0;
}