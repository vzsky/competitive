#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, l, r;
} seg[2000100];
int root[100100], ar[100100], s[100100];
int n, m;
map<int,int> mp;

int cnt = 0;
int clone(int n) {
    seg[++cnt] = seg[n];
    assert(cnt <= 2000000);
    // cerr << "fs " << cnt << endl;
    return cnt;
}

int update(int a, int now, int l = 1, int r = n){
    if (r < a || a < l) return now;
    if (l == r) {
        int nw = clone(now);
        seg[nw].val++;
        return nw;
    }
    int nw = clone(now);
    int mid = (l+r)/2;
    seg[nw].l = update(a, seg[now].l, l, mid);
    seg[nw].r = update(a, seg[now].r, mid+1, r);
    seg[nw].val = seg[seg[nw].l].val + seg[seg[nw].r].val;
    return nw;
}

int query(int now, int a, int b, int l = 1, int r = n){
    if (r < a || b < l) return 0;
    if (a <= l && r <= b) {
        return seg[now].val;
    }
    int mid = (l+r)/2;
    return query(seg[now].l, a, b, l, mid)+query(seg[now].r, a, b, mid+1, r);
}

int main(){
    scanf("%d %d", &n, &m);
    // assert(n <=100000);
    // assert(m <= 5000);
    for(int i = 1; i <= n; i++){
        scanf("%d", &ar[i]);
        s[i] = ar[i];
    }
    sort(s+1, s+n+1);
    for(int i = 1; i <= n; i++){
        mp[s[i]] = i;
    }
    for(int i = 1; i <= n; i++){
        root[i] = update(mp[ar[i]], root[i-1]);
    }
    for(int i = 0; i < m; i++){
        int a, b, k;
        scanf("%d %d %d", &a, &b, &k);
        int l = 1, r = n;
        while(l < r) {
            int mid = (l+r)/2;
            // cerr << l << ' ' << r << ' ' << mid << ' ' << (query(root[b], 1, mid)-query(root[a-1], 1, mid)) << endl;
            if (query(root[b], 1, mid)-query(root[a-1], 1, mid) >= k)    r = mid;
            else                                                         l = mid+1;
        }
        // cerr << l  << endl;
        printf("%d\n", s[l]);
    }
    return 0;   
}