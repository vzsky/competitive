#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    printf("%d", 3*n + min(k-1, n-k));
    return 0;
}