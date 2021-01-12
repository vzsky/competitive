#include<bits/stdc++.h>
using namespace std;

struct A {
	int e;
	long long w;
	int t;
	bool operator < (const A & o) const{
		return w > o.w;
	}
};

priority_queue <A> heap;

long long dis[10100][10];
int visited[10100][10];
vector<pair<int,int>> g[10100];

int main(){
	int n, m, t, x, y;
	scanf("%d %d %d %d %d", &n, &m, &t, &x, &y);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		g[u].push_back({v, w});
	}
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < t; j++){
			dis[i][j] = 1e18;
		}
	}
	dis[x][0] = 0;
	heap.push({x, 0, 1});

	long long ans;

	while(!heap.empty()){
		auto a = heap.top(); heap.pop();
		visited[a.e][a.t] = a.w;
		dis[a.e][a.t] = a.w;
		if (a.e == y && a.t == 0) {
			ans = dis[a.e][a.t];
			break;
		}

		for(auto x : g[a.e]){
			if (visited[x.first][a.t+1%t]) continue;
			//cout << "push " << x.first << ' ' << dis[a.e][a.t]+x.second << ' ' << (a.t+1)%t << endl;
			heap.push({x.first, dis[a.e][a.t]+x.second, (a.t+1)%t});
		}

	}
	if (heap.empty()) printf("-1");
	else printf("%lld", ans);
	return 0;
}