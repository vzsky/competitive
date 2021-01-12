#include<bits/stdc++.h>
using namespace std;

long long v[2020], t[2020];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld %lld", &t[i], &v[i]);
    while(m--) {
        long long p, b, e, ans = 0;
        scanf("%lld %lld %lld", &p, &b, &e);
        for(int i = 1; i <= n; i++) if (v[i]*(b-t[i]) <= p and v[i]*(e-t[i]) >= p) ans++;
        printf("%lld\n", ans);
    }
    return 0;
}