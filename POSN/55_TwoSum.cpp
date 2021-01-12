#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int a[500100];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n;
        scanf("%d", &n);
        long long ans = 0;
        m.clear();
        a[0] = 0;
        m[0]++;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i] += a[i-1];
            ans += m[a[i]];
            m[a[i]]++;
        }
        cout << ans << endl;
    }
    return 0;
}