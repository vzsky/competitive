#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i]}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i]
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' '; } cerr << endl
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

vector<pii> g[100100];
int p[100100], lev[100100], dis[100100];

void dfs(int root, int parent, int level) {
	p[root] = parent;
	lev[root] = level;
	for (auto x : g[root]) {
		if (x.x == parent) continue;
		dis[x.x] = x.y;
		dfs(x.x, root, level+1);
	}
	return;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n-1; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		g[a].pb({b, c});
		g[b].pb({a, c});
	}
	dfs(1, 0, 1);
	for(int i = 0; i < m; i++){
		int a, b;
		int ans = 0;
		scanf("%d %d", &a, &b);
		while (lev[a] > lev[b]) {
			ans ^= dis[a] ;
			a = p[a];
		}
		while (lev[b] > lev[a]) {
			ans ^= dis[b] ;
			b = p[b];
		}
		while(a!=b){
			ans ^= dis[a];
			ans ^= dis[b];
			a = p[a];
			b = p[b];
		}
		printf("%d\n", ans);
	}
	return 0;
}