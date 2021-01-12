#include <bits/stdc++.h>
using namespace std;

int p[500100];
vector<int> cycle[500100];
int ind[500100];
int incycle[500100];
int visited[500100];

int cnt;
void dfs (int u, int c) {
	if (visited[u]) return;
	visited[u] = 1;
	cycle[c].push_back(u);
	incycle[u] = c;
	ind[u] = ++cnt;
	dfs(p[u], c);
}

bool same (int a, int b) {
	return incycle[a] == incycle[b];
}

bool check () {
	int s, e, a, b;
	cin >> s >> e >> a >> b;
	s = p[s]; e = p[e]; a = p[a]; b = p[b];
	s = (s == a)? b : (s == b)? a : s;
	e = (e == a)? b : (e == b)? a : e;

	if (!same(a, b)) {
		// cerr << "diff" << endl;
		// join cycle of a and b
		if (same(s, e)) return true;
		if (same(s, a) and same(e, b)) return true;
		if (same(s, b) and same(e, a)) return true;
		return false;
	}
	// cerr << "same" << endl;
	// same cycle
	if (ind[a] > ind[b]) swap(a, b);
	// index a < b
	if (same(s, a) and same(e, a)) {
		// cerr << s << ' ' << e << endl;
		// cerr << (ind[a] <= ind[s] and ind[s] < ind[b]) << " and " << (ind[a] <= ind[e] and ind[e] < ind[b]) << endl;
		return !((ind[a] <= ind[s] and ind[s] < ind[b]) ^ (ind[a] <= ind[e] and ind[e] < ind[b]));
	}
	return same(s, e);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> p[i];
	int c = 0;
	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		cnt = 0;
		dfs(i, ++c);
	}

	// for (int i = 1; i <= n; i++) {
	//	 cerr << incycle[i] << ' ' << ind[i] << endl;
	// }

	for (int i = 0; i < q; i++) {
		cout << (check()?"DEAD":"SURVIVE") << '\n';
	}
	return 0;
}