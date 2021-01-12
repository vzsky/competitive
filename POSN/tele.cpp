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

vi g[101100];
priority_queue <pii> heap;
int visited[101100];

int main(){


    int n, a, t;
    scanf("%d %d %d", &n, &a, &t);
    for(int i = 1; i <= t; i++) {
        for(int j = 1; j <= a; j++){
            int num;
            scanf("%d", &num);
            g[n+i].pb(num);
            g[num].pb(n+i);
        }
    }

    heap.push({0,1});

    while(!heap.empty()){
        auto t = heap.top(); heap.pop();

        if (visited[t.y]) continue;
        visited[t.y] = 1;

        if (t.y == n) {
            int ans = -t.x;
            ans/=2;
            printf("%d", ans+1);
            return 0;
        }

        for(auto x : g[t.y]) {
            if (visited[x]) continue;
            heap.push({t.x-1, x});
        }
    }

    printf("-1");
    return 0;
}