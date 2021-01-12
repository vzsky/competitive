#include<bits/stdc++.h>
using namespace std;

int seg[4000100];
int n, k;

void update(int idx, int val, int l = 1, int r = n, int now = 1){
    if (idx < l || r < idx) return;
    if (l == r) {
        seg[now] = val;
        return;
    }
    int mid = (l+r)/2;
    update(idx, val, l, mid, now*2);
    update(idx, val, mid+1, r, now*2+1);
    seg[now] = max(seg[now*2], seg[now*2+1]);
}

int query(int a, int b, int l = 1, int r = n, int now = 1) {
    if (r < a || b < l) return -1e9;
    if (a <= l && r <= b) return seg[now];
    int mid = (l+r)/2;
    // cerr << a << ' ' << b << ' ' << l << ' ' << r << endl;
    return max(query(a, b, l, mid, now*2), query(a, b, mid+1, r, now*2+1));
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        // cerr << i << endl;
        int idx, val, l, r;
        scanf("%d %d", &idx, &val);
        idx++;
        update(idx, val);
        l = 1, r = idx;
        while(l < r) {
            int mid = (l+r)/2;
            // cerr << mid << endl;
            if (query(mid, idx) == val) r = mid;
            else                        l = mid+1;
        }
        int left = l;
        l = idx, r = n;
        while(l < r) {
            int mid = (l+r+1)/2;
            if (query(idx, mid) == val) l = mid;
            else                        r = mid-1;
        }
        int right = l;
        if (left == 1 && right == n) printf("%d\n", n);
        else if (left == 1) printf("%d\n", right-idx);
        else if (right == n) printf("%d\n", idx-left);
        else printf("%d\n", min(right-idx, idx-left));
    }
    return 0;
}