#include<bits/stdc++.h>
using namespace std;

#define DEBUG 1

#if !DEBUG
#define cout //
#endif

long long arr[1000100];
long long cnt;
long long a, b;
long long l, r, mid;

int main(){
    scanf("%lld %lld", &a, &b);
    for(int i = 0; i < a; i++){
        scanf("%lld", &arr[i]);
    }
    l = 0; r = 3e9;
    while(l<r){
        mid = (l + r + 1) /2;
        cnt = 0;
        for(int i = 0 ; i < a; i++){
            if (mid<arr[i]) cnt += (arr[i]-mid);
        }
        if (cnt >= b) l = mid;
        else r = mid-1;
    }
    printf("%lld", l);
return 0;
}