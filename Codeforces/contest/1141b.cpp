#include<bits/stdc++.h>
using namespace std;

int n;
int a[200100], ans = 0, mx;
int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if (a[i] == 1) ans++;
        else {
            mx = max(ans, mx);
            ans = 0;
        }
    }
    int b = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == 1) {
            b++;
            continue;
        }
        else {
            break;
        }
    }
    int c = 0;
    for(int i = n-1; i >= 0; i--){
        if (a[i] == 1) {
            c++;
            continue;
        }
        else {
            break;
        }
    }
    printf("%d", max(mx,c+b));
    return 0;
}