#include<bits/stdc++.h>
using namespace std;

int b[200100], c[200100], d[200100], ans[200100];
pair<int,int> a[200100];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n+1; i++) scanf("%d", &a[i].first), a[i].second = i;
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    sort(a+1, a+n+2); sort(b+1, b+n+1);
    for (int i = 1; i <= n; i++) c[i] = max(a[i].first-b[i], 0), c[i] = max(c[i], c[i-1]);
    for (int i = n; i >= 1; i--) d[i] = max(a[i+1].first-b[i], 0), d[i] = max(d[i], d[i+1]);
    for (int i = 1; i <= n+1; i++) ans[a[i].second] = max(c[i-1], d[i]);
    for (int i = 1; i <= n+1; i++) printf("%d ", ans[i]);
    return 0;
}