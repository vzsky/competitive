#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cout << #x << " is " << x << endl;
#define logarr(start, en) cout << #start << " : "; For(it, start, en) cout << *it << ' '; cout << endl;
#define logvec(v) cout << #v << " : "; for(auto x : v) cout << x << ' '; cout << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cout << a[i][j] << ' '; cout << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define DEBUG 1

#if !DEBUG
#undef log
#undef logarr
#undef logvec
#undef logmat
#define cout //
#endif

int a[20];

bool sorted(int l, int r){
    for(int i = l; i < r; i++){
        if (a[i] > a[i+1]) return false;
    }
    return true;
}

int play(int l, int r){
    int mid = (l+r) / 2;
    if (sorted(l, r)) return r-l+1;
    return max(play(l, mid), play(mid+1, r));
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int l = 0, r = n-1;
    cout << play(l ,r);
}