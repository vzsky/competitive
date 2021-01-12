#include<bits/stdc++.h>
using namespace std;

struct E {
    int u, v;
    double w;
    bool operator < (const E & o) const{
        return w < o.w;
    }
};

int p[600000];

int find(int i){
    if (i==p[i]) return i;
    return p[i] = find(p[i]);
}

double ans = 0;

vector <E> edge;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        double w;
        scanf("%d %d %lf", &u, &v, &w);
        edge.push_back({u,v,w});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < m; i++) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if (u!=v){
            ans+= edge[i].w;
            p[u] = v;
        }
    }
    printf("%.3lf", ans);
return 0;
}