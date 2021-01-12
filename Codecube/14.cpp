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

struct A {
	int e, w, k;
};
struct A2 {
	int node, dis, eo, k;
	bool operator < (const A2 & o ) const {
		if (dis != o.dis) return dis > o.dis;
		return k > o.k;
	}
};

vector <A> g[1010];
int visited[1010][2];
int dis[1010][2];
priority_queue <A2> heap;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].pb({b,c,i});
		g[b].pb({a,c,i});
	}
	for(int i = 1; i <= n; i++){
		dis[i][0] = dis[i][1] = 2e9;
	}
	heap.push({1, 0, 0, 0});

	int ans = 2e9;
	int ansk = 2e9;
	while(!heap.empty()){
		auto a = heap.top(); heap.pop();
		dis[a.node][a.eo] = a.dis;
		visited[a.node][a.eo] = 1;
		if (a.node == n && a.eo == 1 && a.dis <= ans) {
			ans = a.dis;
			ansk = min(ansk, a.k);
			break;
		}

		for (auto x : g[a.node]){
			if (visited[x.e][a.eo^1]) continue;
			//cout << "push " << x.e << ' ' << dis[a.node][a.eo]+x.w << ' '  << (a.eo^1) << ' ' << max(x.k,a.k) << endl;
			heap.push({x.e, dis[a.node][a.eo]+x.w, a.eo^1 , max(x.k,a.k)});
		}
	}

	printf("%d %d", ansk ,ans);
	return 0;
}