#include<bits/stdc++.h>
using namespace std;

struct A {
    int l, r, val;
} seg[1700100];

int n, q;
int a[300100], p[300100], l[300100], s[1000100], root[300100];

int tot = 0;
int clone(int now) {
    seg[++tot] = seg[now];
    return tot;
}

int update(int ind, int now, int l = 1, int r = n+1){
    if (l > ind || r < ind) return now;
    if (l == r) {
        int nw = clone(now);
        seg[nw].val += 1;
        return nw;
    }
    int mid = (l+r)/2;
    int nw = clone(now);
    seg[nw].l = update(ind, seg[now].l, l, mid);
    seg[nw].r = update(ind, seg[now].r, mid+1, r);
    seg[nw].val = seg[seg[nw].l].val + seg[seg[nw].r].val;
    return nw;
}

int query(int a, int b, int now, int l = 1, int r = n+1){
    if (l > b || r < a) return 0;
    if (r <= b && l >= a) return seg[now].val;
    int mid = (l+r)/2;
    return query(a, b, seg[now].l, l, mid)+query(a, b, seg[now].r, mid+1, r);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        p[i] = s[a[i]]+1;
        s[a[i]] = i;
        root[i] = update(p[i], root[i-1]);
    }
    scanf("%d", &q);
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", query(1, l, root[r])-query(1, l, root[l-1]));
    }
    return 0;
}