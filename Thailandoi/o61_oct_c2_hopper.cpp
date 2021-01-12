#include<bits/stdc++.h>
using namespace std;

int vis[3010], dp[3010], p[3010];
vector<int> g[3010];
int n, m;

int dfs(int root, int deg) {
    if (vis[root] == deg) return dp[root];
    vis[root] = deg;
    dp[root] = 1;
    for(auto x : g[root]) {
        dp[root] = max(dp[root], dfs(x, deg) + 1);
    }
    return dp[root];
}

int main(){
    int mn = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        if (p[i] < p[mn]) mn = i;
    }

    int l = 1, r = n; 
    int prep = 0;
    while(l < r) { 
        int mid = (l+r)/2;
        // cerr << mid << endl;

        if (prep < mid) {
            for(int i = prep+1; i <= mid; i++){
                for(int j = 0; j < n; j++){
                    if (p[j] < p[(j+i)%n]) g[j].push_back((i+j)%n);
                }
            }
        }
        if (prep > mid) {
           for(int i = 0; i < n; i++){
               while(!g[i].empty() and (g[i].back() - i + n)%n > mid) {
                   g[i].pop_back();
               }
           }
        }
        prep = mid;

        bool check = false;
        for(int i = 0; i < n; i++){
            if (vis[i] == mid) continue;
            if (dfs(i, mid) > m) { 
                check = true;
                break;
            }
        }

        if (check)   r = mid;
        else         l = mid+1;
    }

    printf("%d", l);

    return 0;
}