#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int N = 10010;
int n;
int heavy[N], dep[N], par[20][N], head[N], base[N], pos[N], dis[N];
pair<int,int> edge[N];
vector<pair<int,int>> g[N];
int seg[4*N];

int dfs(int u, int p){
    par[0][u] = p;
    dep[u] = dep[p]+1;
    int sz = 1;
    pair<int,int> big = {-1, -1};
    for (auto x : g[u]) {
        int v, w; 
        tie(v, w) = x;
        if (v == p) continue;
        int z = dfs(v, u);
        if (big.x < z) big = {z, v};
        sz += z;
    }
    heavy[u] = big.y;
    return sz;
}

void build(int l = 1, int r = n, int now = 1) {
    if (l == r) {seg[now] = dis[base[l]]; return;}
    int mid = (l+r)/2;
    build(l, mid, now*2);
    build(mid+1, r, now*2+1);
    seg[now] = max(seg[now*2], seg[now*2+1]);
}

void update(int ind, int val, int l = 1, int r = n, int now = 1) {
    if (l > ind || r < ind) return;
    if (l == r) {
        seg[now] = val;
        return;
    }
    int mid = (l+r)/2;
    update(ind, val, l, mid, now*2);
    update(ind, val, mid+1, r, now*2+1);
    seg[now] = max(seg[now*2], seg[now*2+1]);
}

int query(int a, int b, int l = 1, int r = n, int now = 1) {
    if (l > b || r < a) return -1;
    if (l >= a && r <= b) return seg[now];
    int mid = (l+r)/2;
    return max(query(a, b, l, mid, now*2), query(a, b, mid+1, r, now*2+1));
}

void init(){
    dfs(1, 0);
    int id = 0;
    for(int i = 1; i <= n; i++){
        if (heavy[par[0][i]] == i) continue; // not a head
        for(int j = i; j != -1; j = heavy[j]) {
            base[++id] = j;
            pos[j] = id;
            head[j] = i;
        }
    }
    assert(id == n);
    for(int i = 1; i <= n; i++){
        for(auto x : g[i]){
            int v, w;
            tie(v, w) = x;
            if (v == par[0][i]) {
                dis[i] = w;
            }
        }
    }
    for(int i = 1; i <= 15; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }
    build();
}

int lca(int a, int b) {
    if (dep[a] < dep[b]) {swap(a, b);}
    for(int i = 15; i >= 0; i--) {
        if (dep[par[i][a]] >= dep[b]) a = par[i][a];
    }
    if (a == b) return a;
    for(int i = 15; i >= 0; i--) {
        if (par[i][a] != par[i][b]) { a = par[i][a]; b = par[i][b]; }
    }
    return par[0][a];
}

// int branch (int a, int l) {
//     // cerr << a << ' ' << l << endl;
//     if (dep[l] > dep[a]) return 0;
//     if (head[a] = head[l]) return query(l, a); // same chain
//     return max(query(a, head[a]), branch(par[0][head[a]], l));
// }

int branch (int a, int l) {
    int mx = 0;
    while(1) {
        if (a == l) break;
        if (head[a] == head[l]) {
            assert(pos[l]+1 <= pos[a]);
            mx = max(mx, query(pos[l]+1, pos[a]));
            // cerr << "Qu " << pos[l]+1 << ' ' << pos[a] << endl;
            break;
        }
        assert(pos[head[a]] <= pos[a]);
        mx = max(mx, query(pos[head[a]], pos[a]));
        // cerr << "Qu " << pos[head[a]] << ' ' << pos[a] << endl;
        a = par[0][head[a]];
    }
    return mx;
}

int go (int a, int b) {
    if (a == b) return 0;
    int l = lca(a, b);
    return max(branch(a, l), branch(b, l));
}

char s[10];

int main(){
    int t, a, b;
    scanf("%d", &t);
    while(t--){

        for(int i = 0; i <= N; i++) g[i].clear();

        scanf("%d", &n);
        for(int i = 1; i < n; i++){
            int u,v,w;
            scanf("%d %d %d", &u, &v, &w);
            g[u].push_back({v, w});
            g[v].push_back({u, w});
            edge[i] = {u, v};
        }
        init();
        while(1) {
            scanf(" %s", s);
            if (s[0] == 'D') break;
            scanf("%d %d", &a, &b);
            if (s[0] == 'Q') {
                printf("%d\n", go(a, b));
            }
            if (s[0] == 'C') {
                int child = dep[edge[a].x] > dep[edge[a].y] ? edge[a].x : edge[a].y;
                update(pos[child], b);
            } 
        }
    }
    return 0;
}