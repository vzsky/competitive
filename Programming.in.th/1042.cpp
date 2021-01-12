#include<bits/stdc++.h>
using namespace std;

int x[5010], y[5010];
int mx = 0;

int main(){
    int n,m,k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++){
        int a,b,r;
        scanf("%d %d %d", &a, &b, &r);
        if (a-r < 0) x[0] += 1;
        else x[a-r] += 1;
        if (a+r >= n) x[n] -= 1;
        else x[a+r+1] -= 1;
        if (b-r < 0) y[0] += 1;
        else y[b-r] += 1;
        if (b+r >= m) y[m] -= 1;
        else y[b+r+1] -= 1;
    }
    for(int i = 1; i < n; i++){
        x[i] += x[i-1];
        mx = max(mx, x[i]);
    }
    for(int i = 1; i < m; i++){
        y[i] += y[i-1];
        mx = max(mx, y[i]);
    }
    printf("%d", mx);
    return 0;
}