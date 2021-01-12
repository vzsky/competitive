#include<bits/stdc++.h>
using namespace std;

struct A {
    long long x, y;
    bool operator < (const A & o) const {
        return x > o.x;
    }
} a[100100];
double mean[50100];
long long l[50100], r[50100], s[50100], t[50100], ans[50100];
vector<long long> mid[100100];

long long sum[100100], cnt[100100];

long long n, m;

void update (long long idx, long long val){
    idx += 2;
    // cerr << "add " << idx-2 << endl;
    for (int i = idx; i <= n+20; i+=(i&-i)){
        sum[i]+=val;
        cnt[i]++;
    }
}
long long COUNT (long long from, long long to) {
    long long c = 0;
    from += 2; to += 2;
    for(int i = to; i > 0; i-=(i&-i)) {
        c += cnt[i];
    }
    for(int i = from-1; i > 0; i-=(i&-i)) {
        c -= cnt[i];
    }
    return c;
};
double MEAN (int from, int to) {
    double s = 0;
    from += 2; to += 2;
    for(int i = to; i > 0; i-=(i&-i)) {
        s += sum[i];
    }
    for(int i = from-1; i > 0; i-=(i&-i)) {
        s -= sum[i];
    }
    // cerr << "mean " << s << ' ' << COUNT(from, to) << endl;
    return s/COUNT(from-2, to-2);
};


int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i].x);
        a[i].y = i;
    }
    sort(a+1, a+n+1);
    // for(int i = 0; i < n; i++) printf("%d ", a[i].x);
    for(int i = 0; i < m; i++){
        scanf("%lld %lld %lf", &s[i], &t[i], &mean[i]);
        l[i] = 1;
        r[i] = n;
    }
    bool status = true;
    while(status) {
        memset(sum , 0, sizeof sum);
        memset(cnt, 0, sizeof cnt);
        status = false;
        // cerr << "bbb" << endl;
        for(int i = 0; i < m; i++) {
            // cerr << l[i] << ' ' << r[i] << endl;
            if (l[i] == r[i]) continue;
            mid[(l[i]+r[i]+1)/2].push_back(i);
            status = true;
        }
        for(int i = 1; i <= n; i++) {
            update(a[i].y, a[i].x);
            for(auto x : mid[i]) {
                // cerr << MEAN(s[x], t[x]) << ' ' << mean[x] << ' ' << s[x] << ' ' << t[x] << endl;
                if (MEAN(s[x], t[x]) >= mean[x])  l[x] = i; 
                else                              r[x] = i-1;
                mid[i].clear();
            }
        }
    }
    memset(cnt, 0, sizeof cnt);
    memset(sum , 0, sizeof sum);
    for(int i = 1; i <= n; i++) mid[i].clear();
    for(int i = 0; i < m; i++) {
        assert(l[i] == r[i]);
        mid[l[i]].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        update(a[i].y, a[i].x);
        for (auto x : mid[i]) {
            ans[x] = t[x]-s[x]+1-COUNT(s[x], t[x]);
            if (COUNT(s[x], t[x]) == 0) ans[x] = -1;
        }
    }
    for(int i = 0; i < m; i++) printf("%lld\n", ans[i]);
    return 0;
}
