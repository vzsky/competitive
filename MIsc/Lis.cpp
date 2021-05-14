#include<bits/stdc++.h>
using namespace std;

// const int mod = 1e9+7;
int a[100100], top[100100];
// vector<int> lis[100100], qs[100100];

int main(){
    int n, ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), top[i] = 1e9, lis[i].push_back(0);
    for (int i = 1; i <= n; i++) {
        int find = lower_bound(top+1, top+n, a[i]) - top;
        top[find] = a[i];
        // lis[find].push_back(a[i]);
        if (ans < find) ans = find;
    }

    printf("%d", ans);
    return 0;
}