#include<bits/stdc++.h>
using namespace std;

#define md 1000000007

int main(){
   int q;
   scanf("%d", &q);
   while(q--){
       long long n;
       long long ans;
       scanf("%lld", &n);
       //err << n << endl;
        if (n&1ll) {
            ans = (n+1)/2;
            ans%=md;
            ans *= (n%md);
            ans %= md;
        }
        else {
            ans = n/2;
            ans%=md;
            ans *= ((n+1)%md);
            ans%=md;
        }
        printf("%lld\n", ans);
   }
   return 0;
}