#include<bits/stdc++.h>
using namespace std;

int ab(int a, int b){
    if (a > b) return a-b;
    return b-a;
}

int main(){
    int q, d;
    scanf("%d %d", &q, &d);
    int ans = 0;
    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (ab(a, b) <= d) {
            ans += max(a, b);
            // cerr << max(a, b) << ' ';
        }
        else {
            int c;
            scanf("%d", &c);
            ans += c;
            // cerr << c << ' ';
        }
    }
    cout << ans;
    return 0;
}