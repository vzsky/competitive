#include<bits/stdc++.h>
using namespace std;
#define pb push_back


struct A {
	int u, v, w, e;
	bool operator < (const A & o) const {
		return w > o.w;
	}
};

int p[100100];

vector <A> edge;
int t;
vector <int> ans;

int find(int i){
	if (i == p[i]) return i;
	return p[i] = find(p[i]);
}
long long mst = 0;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	if (m < n) {
		printf("-1\n");
		return 0;
	}
	for(int i = 1; i <= n; i++) p[i] = i;
	for(int i = 1; i <= m; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge.pb({a, b, c, i});
	}
	scanf("%d", &t);
	sort(edge.begin(), edge.end());
	int cnt = 0;
	for(int i = 0; i < edge.size(); i++){
		if (cnt == n-1) break;
		if (find(edge[i].u) == find(edge[i].v)) continue;
		mst += edge[i].w;
		edge[i].w = 0;
		p[find(edge[i].u)] = p[edge[i].v];
		ans.pb(edge[i].e);
		cnt++;
	}
	if (cnt != n-1) {
		printf("-1\n");
		return 0;
	}
	sort(edge.begin(), edge.end());
	mst += edge[0].w;
	ans.pb(edge[0].e);
	printf("%lld\n", mst);
	if (t == 2){
		for(auto x : ans) printf("%d ", x);
	}
	return 0;
}