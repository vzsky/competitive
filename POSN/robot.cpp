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

char tab[2005][2005];
int visited[2005][2005];
struct A {
    int i, j, dis;
    bool operator < (const A &o) const {
        return dis > o.dis;
    }
};

int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

queue<A> heap;

int main(){
    int n, m;
    int maxa = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf(" %c", &tab[i][j]);
            if (tab[i][j] == 'X') {
                heap.push({i,j,0});
            }
            if (tab[i][j] == 'A') maxa++;
        }
    }

    lli ans = 0, amn = 0;

    while(!heap.empty()){
        auto t = heap.front(); heap.pop();

        if (tab[t.i][t.j] == 'A') {
            ans += t.dis;
            amn++;
            tab[t.i][t.j] = 'T';
        }
        if (amn == maxa) break;

        for(int d = 0; d < 4; d++){
            int ni = t.i +di[d];
            int nj = t.j +dj[d];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if (tab[ni][nj] == 'W' || visited[ni][nj]) continue;
            visited[ni][nj] = 1;
            heap.push({ni,nj,t.dis+1});
        }
    }

    printf("%lld %lld", amn, ans*2);

    return 0;
}