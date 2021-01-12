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

int clus[1010], val[1000100];
int rt = 1000;

int block (int i) {
    return i/rt;
}

int n;

int left(int pos, int v){
    for(int i = pos; i >= block(pos)*rt; i--){
        if (v < val[i]) return pos-i;
    }
    for(int i = block(pos)-1; i >= 0; i--){
        if (clus[i] <= v) continue;
        int j;
        for(j=i*rt+rt-1; v >= val[j]; j--);
        return pos-j;
    }
    return 1 << 30;
}
int right(int pos, int v){
    for(int i = pos; i <= block(pos)*rt+rt-1; i++){
        if (v < val[i]) return i-pos;
    }
    for(int i = block(pos)+1; i <= block(n); i++){
        if (clus[i] <= v) continue;
        int j;
        for(j=i*rt; v >= val[j]; j++);
        return j-pos;
    }
    return 1 << 30;
}

int main(){
    int q;
    scanf("%d %d", &n, &q);
    int rt = pow(n, 0.5);
    for(int i = 0; i < q; i++){
        int x, v;
        scanf("%d %d", &x, &v);

        printf("%d\n", min(n, min(right(x, v), left(x, v))));

        val[x] = v;
        int cl = x/rt;
        clus[cl] = max(clus[cl], val[x]);
    }
    return 0;
}