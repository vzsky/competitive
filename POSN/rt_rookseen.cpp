#include<bits/stdc++.h>
using namespace std;

map<int,int> dx, dy, px, py;
map<long long, int> rook;

long long n = 2, k, q;

const long long N = 1e9;

long long ans = 0;
int cntx = 0, cnty = 0;
void addx (int x, int p) {
    if (dx[x] == 0) {
        ans += n-cnty;
        cntx++;
    }
    if (px[dx[x]]) {
        px[dx[x]]--;
        ans += py[dx[x]];
    }
    dx[x] ^= p;
    if(dx[x] == 0) {
        ans -= n-cnty;
        cntx--;
    }
    if (dx[x] != 0) px[dx[x]]++;
    ans -= py[dx[x]];
}
void addy (int y, int p) {
    if (dy[y] == 0) {
        ans += n-cntx;
        cnty++;
    }
    if (py[dy[y]]) {
        py[dy[y]]--;
        ans += px[dy[y]];
    }
    dy[y] ^= p;
    if(dy[y] == 0) {
        ans -= n-cntx;
        cnty--;
    }
    if (dy[y] != 0) py[dy[y]]++;
    ans -= px[dy[y]];
}

int main(){
    scanf("%lld %lld %lld", &n, &k, &q);
    for (int i = 1; i <= k; i++) {
        int x, y, p;
        scanf("%d %d %d", &x, &y, &p);
        rook[x*N+y] = p;
        addx(x, p);
        addy(y, p);
    }
    for (int i = 1; i <= q; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int p = rook[a*N+b];
        rook[a*N+b] = 0;
        rook[c*N+d] = p;
        addx(a, p);
        addy(b, p);
        addx(c, p);
        addy(d, p);
        printf("%lld\n", ans);
    }

    return 0; 
}