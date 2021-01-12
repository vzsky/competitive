#include<bits/stdc++.h>
using namespace std;

int n, w;
int rmq[22][100100];

void build () {
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n+2; j++){
            if (j+(1<<i)-1 > n+2) continue;
            rmq[i][j] = min(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int a, int b) {
    int lev = floor(log2(b-a+1));
    // cerr << a << ' ' << b << ' ' << lev << " : " << a << ' ' << b-(1<<lev)+1 << endl;
    // cerr << rmq[lev][a] << ' ' << rmq[lev][b-(1<<lev)+1] << endl;
    return min(rmq[lev][a], rmq[lev][b-(1<<lev)+1]);
}


int main(){
    scanf("%d %d", &n, &w);
    for(int i = 2; i <= n+1; i++){
        scanf("%d", &rmq[0][i]);
    }
    // cerr << rmq[0][n+1] << endl;
    build();
    assert(w != -10);

    int ans = -1;
    for(int i = 1; i <= n+2; i++){
        if (i+w+2 > n+2) break;
        // cerr << rmq[0][i] << ' ' << rmq[0][i+w+2] << " : " << query(i, i+w+1) << ' ' << query(i+1, i+w+2) << endl;
        if (rmq[0][i] == query(i, i+w+1) && rmq[0][i+w+2] == query(i+1, i+w+2)) {
            if (query(i+1, i+w+1) == rmq[0][i] or query(i+1, i+w+1) == rmq[0][i+w+2]) continue;
            ans = max(ans, query(i+1, i+w+1));
        }
    }
    printf("%d", ans);
    return 0;
}