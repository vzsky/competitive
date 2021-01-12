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
	int node; lli dis;
	bool operator < (const A & o) const{
		return dis > o.dis;
	}
};

vector<A> g[100100];
priority_queue <A> heap;
lli dis[100100];
int mark[100100], visited[100100];

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].pb({v, w});
		g[v].pb({u, w});
	}
	int s1, s2, e1, e2;
	scanf("%d %d %d %d", &s1, &e1, &s2, &e2);

	memset(dis, -1, sizeof(dis));

	lli sp = 1e15;
	
	heap.push({s1, 0});
	while(!heap.empty()){
		auto t = heap.top(); heap.pop();

		if (dis[t.node]!=-1) continue;
		dis[t.node] = t.dis;
		if (t.node == e1) {
			sp = min(sp, dis[t.node]);
		}

		for(auto x : g[t.node]) {
			if (dis[x.node]==-1){
				heap.push({x.node, dis[t.node]+x.dis});
			}
		}
	}

	heap.push({e1, 0});
	while(!heap.empty()) {
		auto t = heap.top(); heap.pop();

		if (visited[t.node]) continue;
		visited[t.node] = 1;

		if (t.dis + dis[t.node] == sp) mark[t.node] = 1;

		for(auto x : g[t.node]) {
			if (visited[x.node]) continue;
			heap.push({x.node, t.dis+x.dis});
		}
	}

	heap.push({s2, 0});
	while(!heap.empty()){
		auto t = heap.top(); heap.pop();

		if (mark[t.node]) continue;
		mark[t.node] = 1;

		if (t.node == e2){
			printf("%lld", t.dis);
			return 0;
		}

		for(auto x : g[t.node]) {
			if (mark[x.node]) continue;
			heap.push({x.node, t.dis+x.dis});
		}
	}
	printf("-1");
	return 0;
}