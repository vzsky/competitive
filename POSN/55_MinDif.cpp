#include<bits/stdc++.h>
using namespace std;

int a[100100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);
    int ans = 2e9;
    for(int i = 1; i < n; i++){
        ans = min(ans, a[i]-a[i-1]);
    }
    cout << ans;
    return 0;
}