#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n;

pair<int,int> a[70100];
int root[70100];

struct SEG {
    long long cnt, qs;
    int l, r;
} seg[1750100];
int tot = 0;

int clone (int now) {
    seg[++tot] = seg[now];
    return tot;
}

int update (int now, int pos, int val, int l = 1, int r = n) {
    if (r < pos or pos < l) return now;
    if (l == r) {
        int nw = clone(now);
        assert(!seg[nw].cnt and !seg[nw].qs);
        seg[nw].cnt = 1;
        seg[nw].qs = val;
        return nw; 
    }
    int mid = (l+r)/2;
    int nw = clone(now);
    seg[nw].l = update(seg[now].l, pos, val, l, mid);
    seg[nw].r = update(seg[now].r, pos, val, mid+1, r);
    seg[nw].cnt = seg[seg[nw].l].cnt + seg[seg[nw].r].cnt;
    seg[nw].qs = seg[seg[nw].l].qs + seg[seg[nw].r].qs;
    return nw;
}

void leaves (int now, int l = 1, int r = n) {
    if (l == r) {
        // cout << seg[now].qs << ' ';
        cout << seg[now].cnt << ' ';
        return;
    }
    int mid = (l+r)/2;
    leaves(seg[now].l, l, mid); leaves(seg[now].r, mid+1, r);
}

pair<long long, long long> query (int now, int a, int b, int l = 1, int r = n) {
    if (r < a or b < l) return {0, 0};
    if (a <= l and r <= b) {
        return {seg[now].cnt, seg[now].qs};
    }
    int mid = (l+r)/2;
    auto q1 = query(seg[now].l, a, b, l, mid);
    auto q2 = query(seg[now].r, a, b, mid+1, r);
    return {q1.x + q2.x, q1.y + q2.y};
}

long long sum (int vers, int l, int r) { return query(root[vers], l, r).y; }
long long cnt (int vers, int l, int r) { return query(root[vers], l, r).x; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q, e; cin >> n >> q >> e;
    for (int i = 1; i <= n; i++) { cin >> a[i].x; a[i].y = i; }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++) root[i] = update(root[i-1], a[i].y, a[i].x);

    long long z = 0;
    while (q--) {
        long long a, b; cin >> a >> b;
        if (e) { a ^= z; b ^= z; }
        int k = (b-a+1)/2;

        int l = 1, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            if (cnt(mid, a, b) < k) l = mid+1;
            else r = mid;
        }

        // cerr << "kth num is " << l << endl;

        z = sum(n, a, b) - 2*sum(l, a, b);
        cout << z << endl;
    }
    return 0;
}