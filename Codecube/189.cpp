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
	int node, dis;
	bool operator < (const A & o) const {
		return dis > o.dis;
	}
};

int dist[100100];
vector<A> g[100100];
int visited[100100];

priority_queue<A> heap;

int total=0, ans=2e9;

int main(){
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	memset(dist, -1, sizeof dist);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].pb({v, w});
		g[v].pb({u, w});
		total+=w;
	}
	
	heap.push({t, 0});
	while(!heap.empty()){
		auto now = heap.top(); heap.pop();

		if (dist[now.node] != -1) continue;
		dist[now.node] = now.dis;

		for(auto x : g[now.node]){
			if (dist[x.node] == -1) heap.push({x.node, x.dis+dist[now.node]});
		}
	}
	while(!heap.empty()) heap.pop();

	// logarr(dist, dist+n);

	heap.push({s, 0});
	while(!heap.empty()){
		auto now = heap.top(); heap.pop();

		if (visited[now.node]) continue;
		visited[now.node] = 1;

		for(auto x : g[now.node]){
			ans = min(ans, dist[x.node]+now.dis);
			if (visited[x.node]) continue;
			heap.push({x.node, x.dis+now.dis});
		}
	}

	printf("%d", total-ans);

	return 0;
}