#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

lli mic[200100][2];
int n, m;

lli seg[800100][2];

void build (int t, int now = 1, int l = 1, int r = n) {
    if (l == r) return void(seg[now][t] = -1e18);
    int mid = (l+r)/2;
    build(t, now*2, l, mid); build(t, now*2+1, mid+1, r);
    seg[now][t] = max(seg[now*2][t], seg[now*2+1][t]);
}
void update (int t, int a, lli v, int now = 1, int l = 1, int r = n) {
    if (r < a or l > a) return;
    if (l == r) return void(seg[now][t] = max(seg[now][t], v));
    int mid = (l+r)/2;
    update (t, a, v, now*2, l, mid); update(t, a, v, now*2+1, mid+1, r);
    seg[now][t] = max(seg[now*2][t], seg[now*2+1][t]);
}
lli query (int t, int a, int b, int now = 1, int l = 1, int r = n) {
    if (r < a or l > b) return -1e18;
    if (l >= a and r <= b) return seg[now][t];
    int mid = (l+r)/2;
    return max(query(t, a, b, now*2, l, mid), query(t, a, b, now*2+1, mid+1, r));
}

int main(){
    scanf("%d %d", &n, &m);
    build(1); build(0);
    lli t, b, c, ans = 0;
    
    scanf("%lld %lld %lld", &t, &b, &c);
    if (t < b) swap(b, t);
    mic[1][0] = mic[1][1] = c;
    update(0, t, mic[1][0]-t); update(1, t, mic[1][0]+t);
    update(0, b, mic[1][1]-b); update(1, b, mic[1][1]+b);
    ans = max(ans, max(mic[1][0], mic[1][1]));
    printf("%lld\n", ans);

    for(int i = 2; i <= m; i++){
        scanf("%lld %lld %lld", &t, &b, &c);
        if (t < b) swap(b, t);
        mic[i][0] = max(max(query(1, 1, b)-b, query(0, b, n)+b), 0ll)+c;
        mic[i][1] = max(max(query(1, 1, t)-t, query(0, t, n)+t), 0ll)+c;
        update(0, t, mic[i][0]-t); update(1, t, mic[i][0]+t);
        update(0, b, mic[i][1]-b); update(1, b, mic[i][1]+b);
        ans = max(ans, max(mic[i][0], mic[i][1]));
        printf("%lld\n", ans);
    }
    return 0;
}