#include<bits/stdc++.h>
using namespace std;

const int MX = 300;

int laz[120010], cus[120010], l[120010];
vector<int> g[120010], h[120010];

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1; i <= m; i++){
        int A;
        scanf("%d", &A);
        for(int j = 0; j < A; j++) {
            int a;
            scanf("%d", &a);
            if (A <= MX)  h[i].push_back(a);
            else g[a].push_back(i);
        }
    }
    while(q--) {
        int opr, x, y, z;
        scanf("%d", &opr);
        if (opr == 1) {
            scanf("%d %d", &x, &y);
            if (h[x].size() <= MX && h[x].size()!=0) {
                for(auto c : h[x]) {
                    cus[c] += y-l[x];
                }
                l[x] = y;
            }
            else laz[x] = y;

        }
        if (opr == 2) {
            scanf("%d", &z);
            int s = cus[z];
            for(auto x : g[z]) {
                s+=laz[x];
            }
            printf("%d\n", s);
        }
    }
    return 0;
}