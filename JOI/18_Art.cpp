#include<bits/stdc++.h>
using namespace std;

pair<long long,long long> a[500100];
long long b[500100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i].first, &a[i].second);
    sort(a, a+n);
    b[0] = a[0].second; long long ans = b[0];
    for (int i = 1; i < n; i++) b[i] = a[i].second - a[i].first + a[i-1].first;
    for (int i = 1; i < n; i++) {
        b[i] += b[i-1];
        b[i] = max(b[i], a[i].second);
        ans = max(ans, b[i]);
    }
    printf("%lld", ans);
    return 0;
}