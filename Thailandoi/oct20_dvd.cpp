#include<bits/stdc++.h>
using namespace std;

int n, k;
int arr[200100];

int mn[800100], mx[800100];
void build(int l = 1, int r = n, int now = 1){
    if (l == r) {
        mn[now] = mx[now] = arr[l];
        return;
    }
    int mid = (l+r)>>1;
    build(l, mid, now<<1);
    build(mid+1, r, now<<1|1);
    mn[now] = min(mn[now<<1], mn[now<<1|1]);
    mx[now] = max(mx[now<<1], mx[now<<1|1]);
}
void update(int a, int val, int l = 1, int r = n, int now = 1){
    if (a < l || r < a) return;
    if (l == r) {
        // cerr << l << endl;
        mn[now] = mx[now] = val;
        return;
    }
    int mid = (l+r)>>1;
    update(a, val, l, mid, now<<1);
    update(a, val, mid+1, r, now<<1|1);
    mn[now] = min(mn[now<<1], mn[now<<1|1]);
    mx[now] = max(mx[now<<1], mx[now<<1|1]);
}
pair<int,int> query(int a, int b, int l = 1, int r = n, int now = 1) {
    if (b < l || r < a) return {-2e9, 2e9};
    if (a <= l && r <= b) return {mx[now], mn[now]};
    int mid = (l+r)>>1;
    auto ll = query(a, b, l, mid, now<<1);
    auto rr = query(a, b, mid+1, r, now<<1|1);
    return {max(ll.first, rr.first), min(ll.second, rr.second)};
}
int main(){
    int t;
    // scanf("%d", &t);
    // while(t--){
        scanf("%d %d", &n, &k);
        for(int i = 1; i <= n; i++) arr[i] = i;
        for(int i = 1; i <= 800010; i++) mn[i] = 2e9;
        build();
        // cerr << "y" << endl;
        for(int i = 0; i < k; i++){
            int q, a, b;
            scanf("%d %d %d", &q, &a, &b);
            a++; b++;
            if (q == 0) {
                swap(arr[a], arr[b]);
                update(a, arr[a]);
                update(b, arr[b]);
                // cerr << a << ' ' << arr[a] << ' ' << b << ' ' << arr[b] << endl;
            }
            if (q == 1) {
                auto x = query(a, b);
                // cerr << a << ' ' << b << " : " << x.first << ' ' << x.second << endl;
                printf( (x.first == b && x.second == a)?"YES\n":"NO\n");
            } 
        }
    // }
    return 0;
}