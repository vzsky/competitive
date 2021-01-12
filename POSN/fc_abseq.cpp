#include<bits/stdc++.h>
using namespace std;

int a[110], sum;

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]*i-sum);
        sum = a[i]*i;
    }
    return 0;
}