#include<bits/stdc++.h>
using namespace std;

typedef long long int lli;
const int mod = 1e9-1;

int a[80100];
int s[80100];
lli fw[80100];
int n, k;

void update(int ind, int val){
    val = val%mod;
    for(int i = ind; i <= 80010; i+=(i&-i)){
        fw[i]+=val;
        fw[i]%=mod;
    }
}
lli query(int ind) {
    lli ans = 0;
    for(int i = n; i > 0; i-=(i&-i)) {
        ans += fw[i];
        ans %= mod;
    }
    for(int i = ind; i > 0; i-=(i&-i)) {
        ans -= fw[i];
        ans += mod;
        ans %= mod;
    }
    return ans % mod;
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        s[i] = 1;
    }

    for(int j = 2; j <= k; j++) {
        memset(fw, 0, sizeof fw);
        for(int i = 0; i < n; i++){
            lli q = query(a[i]);
            update(a[i], s[i]);
            s[i] = q;
            // cerr << q << ' ';
        }
        // cerr << endl;
    }
    lli ans = 0;
    for(int i = 0; i < n; i++){
        ans+=s[i];
        ans %= mod;
    }
    printf("%lld\n", ans%mod);
    return 0;
}