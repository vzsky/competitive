#include<bits/stdc++.h>
using namespace std;

int mx[1600100], lazy[1600100], range[1600100], L[1600100], R[1600100];

void build (int l = 1, int r = 200000, int now = 1) {
    if (l == r) {
        L[now] = R[now] = 0;
        range[now] = 1;
        return;
    }

    int mid = (l+r)/2;
    build(l, mid, now*2);
    build(mid+1, r, now*2+1);
    range[now] = range[now*2] + range[now*2+1];
    if (R[now*2] == L[now*2+1] && L[now*2+1] == mx[now]) range[now]--;
    L[now] = L[now*2];
    R[now] = R[now*2+1];
}

void update(int a, int b, int val, int l = 1, int r = 200000, int now = 1) {
    // cerr << "upd" << endl;
    if (lazy[now]) {
        lazy[now*2] += lazy[now];
        lazy[now*2+1] += lazy[now];
        mx[now]+=lazy[now];
        L[now] += lazy[now];
        R[now] += lazy[now];
        lazy[now] = 0;
    }
    if (r < a || b < l) return ;
    if (a <= l && r <= b) {
        lazy[now*2] += val;
        lazy[now*2+1] += val;
        mx[now]+=val;
        L[now] += val;
        R[now] += val;
        return;
    }

    // cerr << "rec" << endl;
    int mid = (l+r)/2;
    update(a, b, val, l, mid, now*2);
    update(a, b, val, mid+1, r, now*2+1);

    mx[now] = max(mx[now*2], mx[now*2+1]);
    range[now] = range[now*2] + range[now*2+1];
    if (R[now*2] == L[now*2+1] && L[now*2+1] == mx[now]) range[now]--;
    L[now] = L[now*2];
    R[now] = R[now*2+1];

    if (mx[now*2] > mx[now*2+1]) {
        range[now] = range[now*2];
        mx[now] = mx[now*2];
        return;
    }
    if (mx[now*2+1] > mx[now*2]) {
        range[now] = range[now*2+1];
        mx[now] = mx[now*2+1];
        return;
    }

    assert(now <= 800000);
}

int main(){
    int n, m, a, b, x;
    scanf("%d %d", &n, &m);
    build();
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &x);
        update(a, b, x);
        printf("%d %d\n", mx[1], range[1]);
    }
    return 0;
}

/*
6 5
2 3 4
4 6 1
5 5 3
1 4 1
2 3 -1
*/