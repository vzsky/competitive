#include<bits/stdc++.h>
using namespace std;

struct A {
    int pre, suf, sum, ans;
    A operator + (const A & o) const {
        A temp;
        temp.pre =max(max(pre, sum), sum+o.pre);
        temp.suf =max(max(o.suf, o.sum), o.sum+suf);
        temp.sum = sum+o.sum;
        temp.ans = max(max(temp.pre, temp.suf), max(max(ans, o.ans), suf + o.pre));
        return temp;
    }
} seg[400100];

int n, m, a[100100];

void build (int l = 1, int r = n, int now = 1) {
    if (l == r) {
        seg[now] = {a[l], a[l], a[l], a[l]};
        return;
    }
    int mid = (l+r)>>1;
    build (l, mid, now*2);
    build (mid+1, r, now*2+1);
    seg[now] = seg[now*2]+seg[now*2+1];
}
void update (int idx, int val, int l = 1, int r = n, int now = 1) {
    if (idx < l || r < idx) return;
    if (l == r) {
        seg[now] = {val, val, val, val};
        return;
    }
    int mid = (l+r)>>1;
    update (idx, val, l, mid, now*2);
    update (idx, val, mid+1, r, now*2+1);
    seg[now] = seg[now*2]+seg[now*2+1];
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    build();
    printf("%d\n", seg[1].ans);
    for(int i = 0; i < m; i++){
        int idx, val;
        scanf("%d %d", &idx, &val);
        update(idx+1, val);
        printf("%d\n", seg[1].ans);
    }
    return 0;
}