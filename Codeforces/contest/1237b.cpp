#include<bits/stdc++.h>
using namespace std;

int a[100100], b[100100], taken[100100], ata[100100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &b[i]);
    }

    int j = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if (taken[a[i]]) continue;
        for(; j < n; ) {
            if (ata[b[j]]) {j++; continue;}
            if (b[j] != a[i]) {j++, cnt++, taken[b[j-1]] = 1;}
            else {j++; break;}
        }
        ata[a[i]] = 1;
    }
    
    printf("%d", cnt);
    return 0;
}