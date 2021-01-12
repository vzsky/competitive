#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// would this be overflow even for long long ? ? ?

ll a[200100], del[200100], neg, pos;
void handle (int l, int x) {
    if (del[l] < 0) neg -= del[l];
    if (del[l] > 0) pos -= del[l];
    del[l] = del[l]+x;
    if (del[l] < 0) neg += del[l];
    if (del[l] > 0) pos += del[l];
}

int main(){
    int n, q; ll s, t; scanf("%d %d %lld %lld", &n, &q, &s, &t);
    for (int i = 0; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) {
        del[i] = a[i]-a[i-1];
        if (del[i] < 0) neg += del[i];
        if (del[i] > 0) pos += del[i];
    }
    while(q--) {
        int l, r, x; scanf("%d %d %d", &l, &r, &x);
        handle(l, x);
        if (r != n) handle(r+1, -x);
        printf("%lld\n", -pos*s-neg*t);
    }
    return 0;
}