#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int lli;
typedef pair<int,int> pii;

int main(){
    int n;
    scanf("%d", &n);
    int stop = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        stop = max(stop, a);
        if (i==stop) ans++;
    }
    printf("%d", ans);
    return 0;
}