#include<bits/stdc++.h>
using namespace std;

long long arr[200100];
long long sum = 0;
long long tim = 0;
long long mn = 2e9;

int main(){
    int n;
    long long h;
    cin >> h >> n;
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        sum += a;
        arr[i] = arr[i-1] + a;
    }
    for(int i = 1; i <= n; i++){
        if (-1*arr[i] >= h) { printf("%d", i); return 0; }
        mn = min(mn, arr[i]);
    }
    if (arr[n] >= 0 || mn >= 0) { printf("-1"); return 0; }
    mn = abs(mn);
    long long k = ((h-mn)/(-1*arr[n]));
    if ((h-mn)%(-1*arr[n]) != 0) k++;
    //cout << k << endl;
    h+=(arr[n]*k);
    tim += k*n;
    //cout << tim << ' ' << h;
    for(int i = 0; i <= n; i++){
        if (-1*arr[i] >= h) { cout << tim+i; return 0; }
    }
    return 0;
}