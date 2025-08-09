#include<bits/stdc++.h>
using namespace std;

const int maxn = 1500000;

int seg[4*maxn+100];
int lazy[4*maxn+100];

int RMXN;

void update(int idxa, int idxb, int val, int l = 1, int r = RMXN, int now = 1){
    if (lazy[now]) {
        if (l != r) {
            lazy[now*2] = lazy[now];
            lazy[now*2+1] = lazy[now];
        }
        seg[now] = lazy[now];
        lazy[now] = 0;
    }
    if (r < idxa or l > idxb) return;
    if (l == r) {
        seg[now] = val;
        return;
    }
    if (l >= idxa and r <= idxb) {
        lazy[now*2] = val;
        lazy[now*2+1] = val;
        seg[now] = val;
        return;
    }
    int mid = (l+r)/2;
    update(idxa, idxb, val, l, mid, now*2);
    update(idxa, idxb, val, mid+1, r, now*2+1);
    seg[now] = min(seg[now*2], seg[now*2+1]);
}

int query(int idxa, int idxb, int l = 1, int r = RMXN, int now = 1){
    if (lazy[now]) {
        if (l != r) {
            lazy[now*2] = lazy[now];
            lazy[now*2+1] = lazy[now];
        }
        seg[now] = lazy[now];
        lazy[now] = 0;
    }
    if (r < idxa or l > idxb) return 2e9;
    if (l >= idxa and r <= idxb) {
        return seg[now];
    }
    int mid = (l+r)/2;
    return min(query(idxa, idxb, l, mid, now*2), query(idxa, idxb, mid+1, r, now*2+1));
}

int main(){
    int R, C, m;
    scanf("%d %d %d", &R, &C, &m);

    RMXN = R*C;

    for(int i = 0; i < m; i++){
        int k, r, c, x;
        scanf("%d", &k);
        if (k == 1) {
            scanf("%d %d %d", &r, &c, &x);
            r--; c--;
            int node = C*r+c+1;
            update(node, node, x);
        }
        if (k == 2) {
            scanf("%d %d", &r, &x);
            r--;
            int node = C*r+1;
            // cerr << "test " << node << ' ' << node+C-1 << endl;
            update(node, node+C-1, x);
            // cout << query(node, node) <<endl;
        }
        if (k == 3){
            scanf("%d %d", &r, &c);
            r--; c--;
            int node = C*r+c+1;
            int ans = query(node, node);
            // if (ans == (int)2e9) while(1);
            cout << ans << "\n";
        }
        if (k == 4){
            int ans = query(1, RMXN);
            // if (ans == (int)2e9) while(1);
            cout << ans << "\n";
        }
    }

    return 0;
}
