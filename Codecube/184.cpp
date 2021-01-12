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

struct A {
	int node, dis, dest;
	bool operator < (const A & o) const{ 
		return dis < o.dis;
	}
};

int a[1010], t[1010];
vector <A> g;
int p[1010];

int find(int node){
	if (node == p[node]) return node;
	return p[node] = find(p[node]);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &t[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	for(int i = 1; i <= n; i++){
		// init p
		p[i] = i;
		g.pb({0, t[i], i});
	}

	for(int i = 1; i <= n; i++){
		for(int j = i+1; j <= n; j++){
			g.pb({j, a[i]+a[j], i});
		}
	}

	sort(g.begin(), g.end());

	lli mst = 0;
	int cnt = 0;

	for(int i = 0; i < g.size(); i++){
		if (find(g[i].node) == find(g[i].dest)) continue;
		if (cnt == n) break;
		mst+=g[i].dis;
		cnt++;
		p[find(g[i].node)] = find(g[i].dest);
	}

	printf("%lld", mst);

	return 0;
}