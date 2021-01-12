#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct A {
    int v, l, r;
} seg[500100];

int root[30100];
map<int,int> m;
pair<int,int> a[30100];

int tot = 0;
int clone(int now) {
    seg[++tot] = seg[now];
    return tot;
}

int n;

int update(int ind, int now, int val = 1, int l = 1, int r = n){
    if (l > ind || r < ind) return now;
    if (l == r) {
        int nw = clone(now);
        seg[nw].v += val;
        return nw;
    }
    int mid = (l+r)/2;
    int nw = clone(now);
    seg[nw].l = update(ind, seg[now].l, val, l, mid);
    seg[nw].r = update(ind, seg[now].r, val, mid+1, r);
    seg[nw].v = seg[seg[nw].l].v + seg[seg[nw].r].v;
    return nw;
}

int query(int a, int b, int now, int l = 1, int r = n) {
    if (l > b || r < a) return 0;
    if (l >= a && b >= r) return seg[now].v;
    int mid = (l+r)/2;
    return query(a, b, seg[now].l, l, mid) + query(a, b, seg[now].r, mid+1, r);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        a[i].y = i;
        scanf("%d", &a[i].x);
    }
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; i++){
        root[i] = update(a[i].y, root[i-1]);
    }
    int q;
    int ans = 0;
    scanf("%d", &q);
    while(q--) {
        int i, j, k;
        scanf("%d %d %d", &i, &j, &k);
        i ^= ans;
        j ^= ans;
        k ^= ans;
        if (i < 1) i = 1;
        if (j > n) j = n;
        if (i > j) {
            ans = 0;
            printf("%d\n", ans);
            continue;
        }
        int l = 0, r = n;
        while(l < r) {
            int mid = (l+r+1)/2;
            if (a[mid].x <= k) l = mid;
            else               r = mid-1;
        }
        ans = j-i+1-query(i, j, root[l]);
        printf("%d\n", ans);
    }
    return 0;
}