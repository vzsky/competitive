#include<bits/stdc++.h>
using namespace std;

vector<int> seg[400100];
int a[100100], d[100100];
int n;

void build(int l = 1, int r = n, int now = 1) {
    if (l==r) {
        seg[now].push_back(a[l]);
        return;
    }
    int mid = (l+r)/2;
    build(l, mid, now*2);
    build(mid+1, r, now*2+1);
    int L = 0, R = 0;

    while(L < seg[now*2].size() and R < seg[now*2+1].size()) {
        if(seg[now*2][L] < seg[now*2+1][R]) seg[now].push_back(seg[now*2][L++]);
        else seg[now].push_back(seg[now*2+1][R++]);
    }
    while(L < seg[now*2].size())    seg[now].push_back(seg[now*2][L++]);
    while(R < seg[now*2+1].size())  seg[now].push_back(seg[now*2+1][R++]);
    // cerr << now << " : "; for(auto x : seg[now]) cerr << x << ' '; cerr << endl;
}

long long Gquery(int a, int b, int k, int l = 1, int r = n, int now = 1){
    if (r < a || b < l) return 0;
    if (a <= l && r <= b) {
        int idx = lower_bound(seg[now].begin(), seg[now].end(), k) - seg[now].begin();
        return (int)seg[now].size()-idx;
    }
    int mid = (l+r)/2;
    return Gquery(a, b, k, l, mid, now*2)+Gquery(a, b, k, mid+1, r, now*2+1);
}
long long Lquery(int a, int b, int k, int l = 1, int r = n, int now = 1){
    if (r < a || b < l) return 0;
    if (a <= l && r <= b) {
        int idx = lower_bound(seg[now].begin(), seg[now].end(), k) - seg[now].begin();
        if (seg[now][idx] == k) idx--;
        return idx;
    }
    int mid = (l+r)/2;
    return Lquery(a, b, k, l, mid, now*2)+Lquery(a, b, k, mid+1, r, now*2+1);
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build();
    for(int i = 1; i <= n; i++) scanf("%d", &d[i]);
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        // cerr << Gquery(max(1, i-d[i]), i-1, a[i]) << endl;
        // cerr << Lquery(i+1, min(n, i+d[i]), a[i]) << endl;
        sum += Gquery(max(1, i-d[i]), i-1, a[i]);
        sum += Lquery(i+1, min(n, i+d[i]), a[i]);
    }
    printf("%lld", sum);
    return 0;
}