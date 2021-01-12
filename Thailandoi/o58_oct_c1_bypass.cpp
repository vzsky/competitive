#include<bits/stdc++.h>
using namespace std;

long long mx[4][100100], cnt[100100];
vector<int> g[100100];
long long ans, n;

void dfs(int root = 1, int p = 0){
    for(auto x : g[root]) {
        if (x == p) continue;
        dfs(x, root);

        // cerr << root << ' ' << x << ' ' << mx[0][root] << ' ' << mx[1][root] << ' ' << mx[2][root] << ' ' << mx[0][x] << ' ' <<  mx[1][x] << ' ' <<  mx[2][x] << endl;
        cnt[root] += cnt[x]+1;
        ans = max(ans, mx[2][x]*(n-cnt[x]-1));
        ans = max(ans, mx[1][root]*mx[1][x]);
        ans = max(ans, mx[2][root]*mx[0][x]);
        mx[1][root] = max(mx[1][root], mx[0][x]);
        mx[2][root] = max(mx[2][root], mx[1][x]);
    }
    mx[0][root] = cnt[root]+1;
}

int main(){
    int a, b;
    scanf("%lld", &n);
    for(int i = 0; i < n-1; i++) {
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs();
    printf("%lld", ans);
    return 0;
}