#include<bits/stdc++.h>
using namespace std;

int a[20];

long long craft(int k, int w){
    long long ab = 2*w-a[k-1]+1;
    if (ab <= 1) return -2e9;
    if (k == 2) return ab;
    if (ab&1) return craft(k-1, ab/2)+craft(k-1, ab/2+1);
    else      return 2*craft(k-1, ab/2); 
}

int main(){
    int n, w;
    scanf("%d %d", &n, &w);
    for(int i = 1; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("%lld", craft(n, w)<0?-1:craft(n, w));
    return 0;
}