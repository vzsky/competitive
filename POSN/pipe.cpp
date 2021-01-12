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

pii node[15100];
struct A {
    int i, j; lli dis;
    bool operator < (const A & o) const {
        return dis < o.dis;
    }
};
vector <A> edge;

int p[15100];

lli dis (int i, int j) {
    return abs(node[i].x-node[j].x)+abs(node[i].y-node[j].y);
}

int findp (int i) {
    if (p[i] == i) return i;
    return p[i] = findp(p[i]);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &node[i].x, &node[i].y);
        p[i] = i;
    }

    
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            edge.pb({i, j, dis(i, j)});
        }
    }

    sort(edge.begin(), edge.end());

    // for(int i = 0; i < edge.size(); i++){
    //     cerr << edge[i].i << ' ' << edge[i].j << ' ' << edge[i].dis << endl;
    // }

    lli ans = 0;
    int cnt = 0;
    for(int i = 0; i < edge.size(); i++){
        if (findp(edge[i].i) == findp(edge[i].j)) continue;
        p[edge[i].i] = p[edge[i].j];
        ans += edge[i].dis;
        // cerr << edge[i].dis << endl;
        cnt++;
        if (cnt == n-k) break;
    }

    printf("%d",ans);
    return 0;
}
// MST - Prim's algorithm in N^2
// 5 2 2 9 9 7 14 2 12 9 16 4