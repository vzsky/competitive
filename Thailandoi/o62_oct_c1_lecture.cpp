#include<bits/stdc++.h>
using namespace std;

long long room[100100], tim[100100];
long long dis[310][310];

int main(){
    int c, n, m;
    scanf("%d %d %d", &c, &n, &m);
    for(int i = 0; i < c; i++) scanf("%lld", &room[i]);
    for(int i = 0; i < c; i++) scanf("%lld", &tim[i]);
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) dis[i][j] = 1e15;
    for(int i = 0; i < m; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        dis[a][b] = min(dis[a][b], c);
        dis[b][a] = min(dis[b][a], c);
    }
    for(int i = 0; i <= n; i++) dis[i][i] = 0;
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
                // cerr << i << ' ' << j << ' ' << dis[i][j] << endl;
            }
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cerr << dis[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }
    long long l = 1, r = 2e9;
    while(l < r) {
        long long mid = (l+r+1)/2;
        long long t = 0;
        bool ch = true;
        long long late = 0;
        // cerr << mid << endl;
        for(int i = 0; i < c-1; i++){
            t = mid*dis[room[i]][room[i+1]];
            if (t > tim[i]+tim[i+1]-late) { ch = false; break; }
            late = max(0ll, t+late-tim[i]);
            // cerr << i << ' ' << t << ' ' << late << ' ' <<  endl;
        }
        if (ch) l = mid;
        else   r = mid-1;
    }
    printf("%lld", l);
    return 0;
}
/*
5 5 4
3 1 4 1 5
92 65 35 89 79 
1 2 3
2 3 4
3 4 5
4 5 6
*/