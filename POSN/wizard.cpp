#include<bits/stdc++.h>
using namespace std;

#define hs 5000011

int keep[hs][2], ht[hs], x[4][1510], y[4][1510];

int main(){
    int xt, yt, n;
    scanf("%d %d %d", &xt, &yt, &n);

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < n; j++){
            scanf("%d %d", &x[i][j], &y[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int rx = x[0][i] + x[1][j];
            int ry = y[0][i] + y[1][j];
            int t = ((((3*rx)+ry)%hs)+hs)%hs;
            while(ht[t]){
                t++; t%=hs;
            }
            ht[t] = i*1500+j+1;
            keep[t][0] = rx; keep[t][1] = ry;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int rx = xt - x[2][i] - x[3][j];
            int ry = yt - y[2][i] - y[3][j];
            //cerr << i << ' ' << j << endl;
            int t = ((((3*rx)+ry)%hs)+hs)%hs;
            //cerr << t << endl;
            while(ht[t]){
                
                //cerr << t << endl;

                if (keep[t][0] == rx && keep[t][1] == ry){
                    int d = (ht[t]-1)/1500;
                    int n = (ht[t]-1)%1500;
                    printf("%d %d\n", x[0][d], y[0][d]);
                    printf("%d %d\n", x[1][n], y[1][n]);
                    printf("%d %d\n", x[2][i], y[2][i]);
                    printf("%d %d\n", x[3][j], y[3][j]);
                    return 0;
                }
                t++; t%=hs;
            }

        }
    }
    
    return 0;
}