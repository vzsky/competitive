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

int seg[400400];
int laz[400400];

void update(int a, int b, int l, int r, int now){
    if (laz[now]) {
        if (l!=r) laz[now*2] ^= 1, laz[now*2+1] ^=1;
        seg[now] = r-l+1 - seg[now];
        laz[now] = 0;
    }
    if (l > b || r < a) return;
    if (l >= a && r <= b){
        if (l!=r) laz[now*2] ^= 1, laz[now*2+1] ^=1;
        seg[now] = r-l+1 - seg[now];
        return;
    }

    int mid = (l+r)>>1;
    update(a, b, l, mid, now*2);
    update(a, b, mid+1, r, now*2+1);
    seg[now] = seg[now*2] + seg[now*2+1];
}

int query(int a, int b, int l, int r, int now){
    if (laz[now]) {
        if (l!=r) laz[now*2] ^= 1, laz[now*2+1] ^=1;
        seg[now] = r-l+1 - seg[now];
        laz[now] = 0;
    }
    if (l > b || r < a) return 0;
    if (l >= a && r <= b){
        return seg[now];
    }

    int mid = (l+r)>>1;
    int ans = query(a, b, l, mid, now*2) + query(a, b, mid+1, r, now*2+1);
    //seg[now] = seg[now*2] + seg[now*2+1];
    return ans;
}

int main(){
    int n, m;
    scanf("%d %d",&n ,&m);
    while(m--){
        int opr, a, b;
        scanf("%d %d %d", &opr, &a, &b);
        if (opr == 0){
            update(a, b, 1, n, 1);
        }
        else {
            cout << query(a, b, 1, n ,1) << endl;
        }
    }
    
    return 0;
}