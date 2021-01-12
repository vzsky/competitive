#include<bits/stdc++.h>
using namespace std;

int t[10100], deg[10100], mx[10100];
vector<int> g[10100];
queue<int> q;
int ans = 0;

int main(){
    freopen("msched.in", "r", stdin);
    freopen("msched.out", "w", stdout);
    int n, m;
    scanf("%d %d",&n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
    for(int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        deg[b]++;
        g[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) if (deg[i] == 0) q.emplace(i);
    while(!q.empty()) {
        auto f = q.front(); q.pop();
        int time = mx[f] + t[f];
        bool c = false;
        for(auto x : g[f]) {
            c = true;
            deg[x]--;
            mx[x] = max(mx[x], time);
            if (deg[x] == 0) q.emplace(x);
        }
        if (!c) ans = max(ans, time);
    }
    printf("%d", ans);
    return 0;
}