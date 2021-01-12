#include<bits/stdc++.h>
using namespace std;

int p[100100];
int sol[100100];

int findr(int n) {
    if (n == p[n]) return n;
    return p[n] = findr(p[n]);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &sol[i]);
    }
    for(int i = 1; i <= m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (findr(a) == findr(b)) {printf("-1\n"); continue;}
        if (p[b] < p[a]) swap(a, b);

        if (sol[findr(a)] >= sol[findr(b)]) {
            printf("%d\n", p[a]);
            sol[p[a]] += sol[p[b]]/2;
            p[findr(b)] = findr(a);
        }
        else {
            printf("%d\n", p[b]);
            sol[p[b]]  += sol[p[a]]/2;
            p[findr(a)] = findr(b);
        }
    }
return 0;
}