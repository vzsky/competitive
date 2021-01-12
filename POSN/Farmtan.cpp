#include<bits/stdc++.h>
using namespace std;

#define DEBUG 1

#if !DEBUG
#define cout //
#endif

long long arr[100100];
long long cnt;
long long n, m, l, r, mid;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i< n;i++){
        scanf("%d", &arr[i]);
    }
    l = 0; r = 1e18;
    while (l < r){
        mid = (l + r) / 2;
        cnt = 0;
        for(int i = 0 ; i < n ;i++){
            cnt += (mid/arr[i]);
        }
        if (cnt >= m) r = mid;
        else l = mid+1;
    }
    printf("%lld", l);
return 0;
}