#include<bits/stdc++.h>
using namespace std;

long long ap[310][310];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ap[i][j]=1e9;
        }
    }
    for(int i = 0; i < m; i++){
        int s, e; long long w;
        scanf("%d %d %lld", &s, &e, &w);
        ap[s-1][e-1] = min(ap[s-1][e-1], w);
    }
    for(int i = 0; i < n; i++) ap[i][i] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ap[j][k] = min(ap[j][k], ap[j][i]+ap[i][k]);
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%lld ", ap[i][j]==1e9?-1:ap[i][j]);
        }
        printf("\n");
    }
    return 0;
}