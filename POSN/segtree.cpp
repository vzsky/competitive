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

int seg[100100*3]; // 3-4 times of # leaf nodes.
int n;

void built (int l, int r, int ind = 1){
    if (l == r){
        seg[ind] = 0; // = array[l = r]
        return;
    }
    int mid = l+r >> 1;
    built(l, mid, ind*2);
    built(mid+1, r, ind*2+1);
    seg[ind] = max(seg[ind*2], seg[ind*2+1]); //any optimized func.
}

void update (int leaf, int val, int now = 1, int l = 1, int r = n){ // always now = root, l = begin, r = end
    if (l > leaf || r < leaf ) return;
    if (l == r) { // imply that l == r == a
        seg[now] = val;
        return;
    }
    int mid = l+r >> 1;
    update(leaf, val, now*2, l, mid);
    update(leaf, val ,now*2+1, mid+1, r);

    seg[now] = max(seg[now*2], seg[now*2+1]);
}

int query (int a, int b, int l = 1, int r = n, int now = 1){ //always now = root, l = begin, r = end
    if (r < a || l > b) return -2e9;
    if (l >= a  && r <= b) return seg[now];
    int mid = l+r >> 1;
    return max(query(a, b, l, mid, now*2), query(a, b, mid+1, r, now*2+1));
}

int main(){
    int q;
    scanf("%d %d", &n ,&q);
    //built(1, n);
    while(q--){
        char cmd;
        int a, b;
        scanf(" %c %d %d", &cmd, &a, &b);
        if (cmd == 'U'){ // Update
            update(a, b);
            //logarr(seg, seg+3*n);
        }
        else { // Query
            //logarr(seg, seg+3*n);
            printf("%d\n", query(a, b));
        }
    }
    return 0;
}