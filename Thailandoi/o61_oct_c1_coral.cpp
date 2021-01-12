#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

int k, m;

int leafcnt = 0;

int seg[1<<22];

void update(int now){
    // cerr << "now " << now << endl;
    seg[now] = 1;
    if ((int)log2(now) == k) {
        // leaf
        leafcnt++;
    }
    if (now != 1) {
        // not root
        if (now&1) {
            if (seg[now] && seg[now-1] && !seg[now/2]){
                update(now/2);
            }
            if (seg[now] && seg[now/2] && !seg[now-1]){
                update(now-1);
            }
        }
        if (!(now&1)) {
            if (seg[now] && seg[now+1] && !seg[now/2]){
                update(now/2);
            }
            if (seg[now] && seg[now/2] && !seg[now+1]){
                update(now+1);
            }
        }
    }
    if (seg[now] && seg[now*2] && !seg[now*2+1]){
        update(now*2+1);
    }
    if (seg[now] && seg[now*2+1] && !seg[now*2]){
        update(now*2);
    }
}

void logtree(int now = 1) {
    cerr << seg[now] << ' ';
    if ((int)log2(now) == k) return;
    logtree(now*2);
    logtree(now*2+1);
}

int main(){
    scanf("%d %d", &k, &m);
    for(int i = 0; i < m; i++){
        int lev, num;
        scanf("%d %d", &lev, &num);
        int now = (1<<(k-lev))+num/(1<<lev);
        // cerr << lev << ' ' << num << ' ' << now << endl;
        if (seg[now] == 0) {
            update(now);
        } 
        // logtree();
        // cerr << endl;
        if (leafcnt == 1<<k) {
            cout << i+1; 
            return 0;
        }
    }
    return 0;
}