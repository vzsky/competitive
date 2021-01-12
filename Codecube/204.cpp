#include<bits/stdc++.h>
using namespace std;

char x[50100];
int at[50100];
int wanted;
int visited[50100][16];

struct A {
	int node, w, stat;
	bool operator < (const A & o) const {
		return w > o.w;
	}
};

vector<A> g[50100];
priority_queue<A> heap;

int main(){
	int n, m;
	scanf("%d %d",&n, &m);
	scanf(" %s",x);
	for(int i = 0; i < 4; i++) if (x[i] == '_') wanted |= (1<<i);
	scanf(" %s", x+2);
	for(int i = 2; i <= n; i++) {
		if (x[i] == 'X') at[i] = 1;
		else if (x[i] == 'M') at[i] = 2;
		else if (x[i] == 'A') at[i] = 4;
		else if (x[i] == 'S') at[i] = 8;
		else at[i] = 0;
	}
	for(int i = 0; i < m; i++) {
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		g[a].push_back({b, w, 0});
		g[b].push_back({a, w, 0});
	}
	heap.push({n, 0, at[n]});
	while(!heap.empty()) {
		auto t = heap.top(); heap.pop();

		if (visited[t.node][t.stat]) continue;
		visited[t.node][t.stat] = 1;
		// cerr << t.node << ' ' << t.stat << endl;

		if (t.node == 1 and (t.stat & wanted) == wanted) {
			printf("%d", t.w);
			break;
		}

		for(auto x : g[t.node]) {
			heap.push({x.node, t.w + x.w, t.stat|at[x.node]});
		}
	}
	return 0;
}