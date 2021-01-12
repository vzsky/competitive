#include<bits/stdc++.h>
using namespace std;

vector<long long> a;
long long n, k;

int main(){
    scanf("%lld %lld", &n, &k);
    for(int i = 0; i < n; i++){
        long long z;
        scanf("%lld", &z);
        a.push_back(z);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end())-a.begin());

    long long l = 1, r = 1e9;

    while(l < r) {
        long long mid = (l+r)/2ll;
        long long ans = (mid+1ll)*(mid+1ll);
        for(int i = 1; i < a.size(); i++){
            ans += (mid+1ll)*(mid+1ll);
            // assert(ans >  0);
            long long d = (a[i]-a[i-1]-1ll)/2ll;
            if (d >= mid) continue;
            long long day = mid-d;             
            if ((a[i]-a[i-1]) & 1ll)  ans -= (day*day)+day;
            else                      ans -= (day*day);
            // assert(ans > 0);
            continue;
        }
        // assert(ans > 0);
        // cerr << mid << ' ' << ans << endl;
        if (ans >= k) r = mid;
        else          l = mid+1ll;
    }
    printf("%lld", l);

    return 0;
}