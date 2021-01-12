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

struct A {
    int i, j, d;
    bool operator < (const A & o) const{
        return d > o.d;
    }
};

int a[1010][1010];

priority_queue <A> heap;

int visited[1010][1010];
int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

int main(){
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf("%d", &a[i][j]);
        }
    }

    for(int i = 1; i < k; i++) heap.push({i, 1, a[i][1]});
    visited[k][1] = 1;

    while(!heap.empty()){
        auto tp = heap.top(); heap.pop();

        if (visited[tp.i][tp.j]) continue;
        visited[tp.i][tp.j] = 1;

        //cerr << tp.i << ' ' << tp.j << ' ' << a[tp.i][tp.j] << endl;
        
        if (tp.j == 1 && tp.i > k){
            printf("%d", tp.d);
            break;
        }

        for(int d = 0; d < 4; d++){
            int ni = tp.i+di[d];
            int nj = tp.j+dj[d];
            if (visited[ni][nj] || ni <= 0 || nj <= 0 || ni > r || nj > c) continue;
            heap.push({ni, nj, a[ni][nj]+tp.d});
        }
    }

    return 0;
}