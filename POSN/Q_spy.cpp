#include<bits/stdc++.h>
using namespace std;

struct E {
    int u, v, w;
    bool operator < (const E & o) const {
        return w < o.w;
    }
};
vector <E> edge;

int p[1010];

int find(int i){
    if (i == p[i]) return i;
    return p[i] = find(p[i]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            int a;
            scanf("%d", &a);
            if (i==j) continue;
            edge.push_back({i,j,a});
        }
    }
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        edge.push_back({i, n+1, a});
    }

    sort(edge.begin(), edge.end());
    int ans = 0;

    for(int i = 0; i < n; i++){
        p[i] = i;
    }
    for(int i = 0; i < n; i++){
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if (u == v) continue;
        p[u] = v;
        cout << edge[i].w << ' ' << edge[i].u << ' ' << edge[i].v;
        ans+=edge[i].w;
    }
    printf("%d", ans);
return 0;
}