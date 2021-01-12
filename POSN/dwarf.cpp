#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

int mn[800800], mx[800800];
int arr[200200];
int high[200200];

void built(int l, int r, int now){
    if (l == r) {
        mn[now] = mx[now] = high[l];
        return;
    }
    int mid = (l+r)>>1;
    built(l, mid, now*2);
    built(mid+1, r, now*2+1);

    mn[now] = min(mn[now*2], mn[now*2+1]);
    mx[now] = max(mx[now*2], mx[now*2+1]);
    if (mn[now*2] == mx[now*2] && mx[now*2] == 0){
        mn[now] = mn[now*2+1];
        mx[now] = mx[now*2+1];
    }
    if (mn[now*2+1] == mx[now*2+1] && mx[now*2+1] == 0){
        mn[now] = mn[now*2];
        mx[now] = mx[now*2];
    }
}

void update(int node, int v, int l, int r, int now){
    if (l > node || r < node) return;
    if (l == r) {
        mn[now] = mx[now] = v; 
        return;
    }
    int mid = (l+r)>>1;
    update(node, v, l, mid, now*2);
    update(node, v, mid+1, r, now*2+1);

    mn[now] = min(mn[now*2], mn[now*2+1]);
    mx[now] = max(mx[now*2], mx[now*2+1]);
    if (mn[now*2] == mx[now*2] && mx[now*2] == 0){
        mn[now] = mn[now*2+1];
        mx[now] = mx[now*2+1];
    }
    if (mn[now*2+1] == mx[now*2+1] && mx[now*2+1] == 0){
        mn[now] = mn[now*2];
        mx[now] = mx[now*2];
    }
}

pii range(int a, int b, int l, int r, int now){
    if (l > b || r < a) return {-2e9,2e9};
    if (a <= l && b >= r) {
        return {mx[now], mn[now]};
    }
    int mid = (l+r)>>1;
    auto aa = range(a, b, l, mid, now*2);
    auto bb = range(a, b, mid+1, r, now*2+1);
    return {max(aa.x, bb.x), min(aa.y, bb.y)};
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    For(i, 1, n) { 
        scanf("%d", &arr[i]);
        high[arr[i]] = i;
    }

    built(1, n, 1);

    for(int i = 0; i < m; i++){
        int opr, a, b;
        scanf("%d %d %d", &opr, &a, &b);
        //cerr << opr << endl;
        if (opr == 1){
            // swap pos a, b -> high arr[a] with arr[b]
            update(arr[a], b, 1, n, 1);
            update(arr[b], a, 1, n, 1);
            swap(arr[a],arr[b]);
        }
        else {
            int xpt = abs(b-a);
            // a = high[a];
            // b = high[b];
            if (a > b) swap(a, b);
            auto r = range(a, b, 1, n, 1);
            int rng = r.x-r.y;
            // cerr << r.x << ' ' <<r.y << endl;
            printf(rng == xpt? "YES\n": "NO\n");
        }
    }
    return 0;
}
// 7 7 4 7 3 5 1 2 6 2 1 7 1 3 7 2 4 6 2 4 7 2 1 4 1 1 4 2 1 4