#include<bits/stdc++.h>
using namespace std;

int mat[310][310];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        if (i%2==0) {
            for(int j = 1; j <= n; j++){
                mat[i+1][j] = i*n+j;
            }
        }
        else {
            for(int j = 1; j <= n; j++){
                mat[i+1][n-j+1] = i*n+j;
            }
        }
    }
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}