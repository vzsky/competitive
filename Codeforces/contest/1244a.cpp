#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c, d, k;
        scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
        if (ceil((double)a/c)+ceil((double)b/d) > k) {
            printf("-1\n");
        }
        else printf("%d %d\n", (int)ceil((double)a/c), (int)ceil((double)b/d));
    }
    return 0;
}