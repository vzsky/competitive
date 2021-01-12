#include<bits/stdc++.h>
using namespace std;

struct node {
    long long x, y;
    bool operator < (const node & o) const {
        return x < o.x;
    }
};

node a[1000100];
long long m[1000100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        a[i] = {x/2, y/2};
    }
    a[n] = {0,0};
    sort(a, a+n+1);

    long long ans =0;
    for(int i = n; i >=0; i--){
        m[i] = max(a[i].y, m[i+1]);
        // cerr << m[i] << endl;
    }
    for(int i = 1; i <= n; i++){
        ans += (a[i].x-a[i-1].x)*m[i];
    }
    cout << 4*ans;
    return 0;
}