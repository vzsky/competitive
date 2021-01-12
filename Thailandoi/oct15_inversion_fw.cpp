#include<bits/stdc++.h>
using namespace std;

long long fw[100100];
long long a[100100], s[100100];
map<long long,int> m;

int main(){
    int n;
    long long inv = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &a[i]);
        s[i] = a[i];
    }
    sort(a, a+n);
    for(int i = 1; i <= n; i++){
        m[a[i-1]] = i;
    }
    for(int i = 0; i < n; i++){
        for(int j = m[s[i]]+1; j <= n; j+=(j&-j)){
            inv += fw[j];
        }
        for(int j = m[s[i]]; j > 0; j-=(j&-j)){
            fw[j]++;
        }
    }
    printf("%lld", inv);
    return 0;
}