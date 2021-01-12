#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

long long pow(long long base, int m){
    if (m == 1) return base;
    if (m&1) return ((pow(base, m/2)*pow(base, m/2))%mod*base)%mod;
    else     return pow(base, m/2)*pow(base, m/2)%mod;
}

int main(){
        int n, m;
        scanf("%d %d",&n, &m);
        cout << pow(pow(2ll, m)-1ll, n) << endl;
    return 0;
}