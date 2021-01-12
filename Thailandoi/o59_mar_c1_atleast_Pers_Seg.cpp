#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

struct A {
    long long sum, cnt, l, r;
} seg[1800100];
long long n, m;
long long root[100100];
pair<long long,long long> a[100100];

long long cnt = 0;
long long clone(long long n) {
    seg[++cnt] = seg[n];
    return cnt;
}

long long update(long long now, long long a, long long val, long long l = 1, long long r = n){
    if (r < a || a < l ) return now;
    if (l == r ) {
        long long nw = clone(now);
        // cerr  << ' ' << l << ' ' <<  val << endl;
        seg[nw].sum = val;
        seg[nw].cnt = 1;
        return nw;
    }
    long long nw = clone(now);
    long long mid = (l+r)/2;
    seg[nw].l = update(seg[now].l, a, val, l, mid);
    seg[nw].r = update(seg[now].r, a, val, mid+1, r);
    seg[nw].sum = seg[seg[nw].l].sum + seg[seg[nw].r].sum;
    seg[nw].cnt = seg[seg[nw].l].cnt + seg[seg[nw].r].cnt;
    // cerr << nw << endl;
    // cerr << seg[nw].l << ' ' <<  seg[nw].r << endl;
    // cerr << seg[seg[nw].l].sum << ' ' << seg[seg[nw].r].sum << endl;
    // cerr << "sum " << seg[nw].sum << endl;
    return nw;
}

pair<long long,long long> query(long long now, long long a, long long b, long long l = 1, long long r = n){
    if (r < a || b < l ) return {0,0};
    if (a <= l && r <= b) return {seg[now].sum, seg[now].cnt};
    long long mid = (l+r)/2;
    auto L = query(seg[now].l, a, b, l, mid);
    auto R = query(seg[now].r, a, b, mid+1, r);
    return {L.x+R.x, L.y+R.y};
}

double mean (long long ver, long long a, long long b) {
    auto x = query(root[ver], a, b);
    // cerr << "mean " << x.x << ' ' << x.y << endl;
    return (double)x.x/x.y;
}
long long count (long long ver, long long a, long long b) {
    auto x = query(root[ver], a, b);
    if (x.y == 0) return -1;
    return b-a+1-x.y;
}
int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i].x);
        a[i].y = i;
    }
    sort(a+1, a+n+1, greater<pair<long long,long long>>());
    for(int i = 1; i <= n; i++){
        root[i] = update(root[i-1], a[i].y, a[i].x);
        // cerr << i << ' ' << a[i].y << ' ' << a[i].x << endl;
    }

    for(int i = 0; i < m; i++){
        long long a, b;
        double d;
        scanf("%lld %lld %lf", &a, &b, &d);
        long long l = 1, r = n;
        while(l < r) {
            long long mid = (l+r+1)/2;
            // cerr << l << ' ' << r << ' ' << mid << ' ' << mean(mid, a, b) << endl;
            if (mean(mid, a, b) >= d)   l = mid;
            else                       r = mid-1;
        }
        // cerr << "bsearch " << l << endl;
        printf("%lld\n", count(l, a, b));
    }
    return 0;
}