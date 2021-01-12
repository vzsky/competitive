#include<bits/stdc++.h>
using namespace std;

int a[1010], b[1010], c[1010];

int mx, ans = 0;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++) scanf("%d", &b[i]);
    for(int i = 0; i < n; i++) c[i] = a[i]-b[i];
    //for(int i = 0; i < n; i++) cout << c[i] << ' ';

    mx = abs(c[0]);
    for(int i = 1; i < n; i++){
        if ((c[i] > 0 && c[i-1] > 0)||(c[i] < 0 && c[i-1] < 0)) {
            mx = max(mx, abs(c[i]));
        }
        else {
            ans+=mx;
            mx = abs(c[i]);
        }
    }
    ans += mx;
    printf("%d", ans);
return 0;
}