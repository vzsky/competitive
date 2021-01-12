#include<bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
 
vector<int> eu, g[100100];
long long lazy[1600100];
int p[100100], s[100100];
pair<int,int> eunode[100100];
 
const long long inf = 1e18;
 
int n, q;
 
struct A {
    long long sum, mn;
    A operator + (const A & o) const {
        A temp;
        temp.sum = sum+o.sum;
        temp.mn = min(mn, o.mn);
        return temp;
    }
} seg[1600100];
 
void dfs(int r = 1) {
    eu.push_back(r);
    eunode[r].x = eu.size()-1;
    for(auto x : g[r]) {
        if (x == p[r]) continue;
        dfs(x);
    }
    eu.push_back(r);
    eunode[r].y = eu.size()-1;
}
void build(int l = 1, int r = eu.size(), int now = 1) {
    if (l == r) {
        seg[now] = {s[eu[l]], s[eu[l]]};
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, now*2);
    build(mid+1, r, now*2+1);
    seg[now] = seg[now*2]+seg[now*2+1];
}
void update(int a, int b, int val, int l = 1, int r = eu.size(), int now = 1) {
    if (lazy[now]) {
        lazy[now*2] += lazy[now];
        lazy[now*2+1] += lazy[now];
        seg[now].sum+=(lazy[now]*(r-l+1));
        seg[now].mn+=lazy[now];
        lazy[now] = 0;
    }
    if (r < a || b < l) return;
    if (a <= l && r <= b) {
        lazy[now*2] += val;
        lazy[now*2+1] += val;
        seg[now].sum+=(val*(r-l+1));
        seg[now].mn+=val;
        return;
    }
    int mid = (l+r)>>1;
    update(a, b, val, l, mid, now*2);
    update(a, b, val, mid+1, r, now*2+1);
    seg[now] = seg[now*2]+seg[now*2+1];
}
A query(int a, int b, int l = 1, int r = eu.size(), int now = 1) {
    if (lazy[now]) {
        lazy[now*2] += lazy[now];
        lazy[now*2+1] += lazy[now];
        seg[now].sum+=(lazy[now]*(r-l+1));
        seg[now].mn+=lazy[now];
        lazy[now] = 0;
    }
    if (r < a || b < l) return {0, inf};
    if (a <= l && r <= b) {
        return seg[now];
    }
    int mid = (l+r)>>1;
    return query(a, b, l, mid, now*2) + query(a, b, mid+1, r, now*2+1);
}
 
int main(){
    int  t;
    scanf("%d", &t);
    for(int cnt = 1; cnt <= t; cnt++){
 
        eu.clear();
        memset(lazy, 0, sizeof lazy);
        memset(seg, 0, sizeof seg);
        for(int i = 0; i <= n; i++) g[i].clear();
 
        printf("Case %d:\n", cnt);
        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &p[i], &s[i]);
            g[p[i]].push_back(i);
            g[i].push_back(p[i]);
        }
        eu.push_back(0);
        dfs();
        build();
        for(int i = 0 ; i < q; i++){
            int c,v;
            scanf("%d %d", &c, &v);
            if (c == 1) {
                printf("%lld\n", query(eunode[v].x, eunode[v].y).sum>>1);
            }
            else {
                update(eunode[v].x, eunode[v].y, min(query(eunode[v].x, eunode[v].y).mn, 1000ll));
            }
        }
    }
    return 0;
} 