#include<bits/stdc++.h>
using namespace std;

int p, k, l, q;

int lev (int a) {
    int x = 0;
    if (a > p) a-=p;
    while(a) {
        a=a>>1;
        x++;
    }
    return x;
}

int path (int a, int b) {
    int path = 0;
    int S = 0;
    if(a > p && b < p) return 5e8;
    if(a < p && b > p) return 5e8;
    if(a > p && b > p) {
        S = p;
        a -= p;
        b -= p;
    }
    if (lev(a) < lev(b)) swap(a, b);
    // cerr << "T " << a << ' ' << b << endl;
    // cerr << "T " << lev(a) << ' ' << lev(b) << endl;
    if (lev(a) > lev(b)) {
        path+=(lev(a)-lev(b));
        a = a >> (lev(a)-lev(b));
    }
    // cerr << a << ' ' << b << ' ' << "T" << endl;
    // cerr << lev(a) << ' ' << lev(b) << ' ' << path << endl; 
    // assert(path >= 0);
    // assert(lev(a) == lev(b));
    if (a==b) return path;
    while(a != b) {
        a/=2;
        b/=2;
        path+=2;
    }
    // assert(a==b);
    // assert(path >= 0);
    return path;
}

int dis[15][15];
int m[15];

int main(){
    scanf("%d %d %d", &k, &l, &q);
    p = 1<<k;

    // cerr << "DEBUG " << path(30, 18) << ' ' << endl;

    for(int i = 0; i < 2*l; i++){
        for(int j = 0; j < 2*l; j++){
            dis[i][j] = 1e9;
        }
    }

    for(int i = 0; i < l; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        dis[i][i+l] = dis[i+l][i] = 1;
        m[i] = a;
        m[i+l] = b;
    }


    for(int i = 0; i < l; i++){
        for(int j = i; j < l; j++){
            if (i == j) dis[i][j] = dis[i+l][j+l] = 0;
            dis[i][j] = dis[j][i] = path(m[i], m[j]);
            dis[i+l][j+l] = dis[j+l][i+l] = path(m[i+l], m[j+l]);
        }
    }

    // for(int i = 0; i < 2*l; i++){
    //     for(int j = 0; j < 2*l; j++){
    //         cerr << dis[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    for(int k = 0; k < 2*l; k++){
        for(int i = 0; i < 2*l; i++){
            for(int j = 0; j < 2*l; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    // for(int i = 0; i < 2*l; i++){
    //     for(int j = 0; j < 2*l; j++){
    //         cerr << dis[i][j] << ' ';
    //     }
    //     cerr << endl;
    // }

    for(int i = 0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int disab = path(a, b);
        // cerr << disab << endl;
        for(int i = 0; i < 2*l; i++){
            for(int j = 0; j < 2*l; j++){
                // cerr << m[i] << ' ' << m[j] << ' ' << path(a, m[i]) << ' ' << path(m[j], b) << endl;
                disab = min(disab, path(a, m[i]) + dis[i][j] + path(m[j], b));
            }
        }
        printf("%d\n",disab);
    }
    return 0;
}