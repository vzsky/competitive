#include<bits/stdc++.h>
using namespace std;

struct A {
    int l, r, v;
} seg[1700100];
int root[100100];

int tot = 0;
int clone(int now){
    seg[++tot] = seg[now];
    return tot;
}

int a[100100], n, q;

int build (int l = 1, int r = n) {
    if (l == r) {
        int nw = clone(0);
        seg[nw].v = a[l];
        return nw;
    }
    int nw = clone(0);
    int mid = (l+r)/2;
    seg[nw].l = build(l, mid);
    seg[nw].r = build(mid+1, r);
    seg[nw].v = seg[seg[nw].l].v + seg[seg[nw].r].v;
    return nw;
}

int update(int ind, int val, int now, int l = 1, int r = n) {
    if (l > ind || r < ind) return now;
    if (l == r) {
        int nw = clone(now);
        seg[nw].v += val;
        return nw;
    }
    int nw = clone(now);
    int mid = (l+r)/2;
    seg[nw].l = update(ind, val, seg[now].l, l, mid);
    seg[nw].r = update(ind, val, seg[now].r, mid+1, r);
    seg[nw].v = seg[seg[nw].l].v + seg[seg[nw].r].v;
    return nw;
}

int query(int a, int b, int now, int l = 1, int r = n){
    if (l > b || r < a) return 0;
    if (l >= a && r <= b) return seg[now].v;
    int mid = (l+r)/2;
    return query(a, b, seg[now].l, l, mid)+query(a, b, seg[now].r, mid+1, r);
}
int v = 0;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    root[0] = build();
    scanf("%d", &q);
    while(q--){
        int opr, a, b, c;
        scanf("%d", &opr);
        scanf("%d %d %d", &a, &b, &c);
        if (opr == 1) root[++v] = update(b, c, root[a]);
        if (opr == 2) printf("%d\n", query(b, c, root[a]));
    }
    return 0;
}