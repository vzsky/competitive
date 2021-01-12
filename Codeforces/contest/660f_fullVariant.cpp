#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> line;

ll a[200100], sum[200100], qs[200100];

struct Line {
	mutable ll m, k, p;
	bool operator<(const Line& o) const { return m < o.m; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->m == y->m) x->p = x->k > y->k ? inf : -inf;
		else x->p = div(y->k - x->k, x->m - y->m);
		return x->p >= y->p;
	}
	void add(ll m, ll k) {
		auto y = insert({m, k, 0}), z = y, x = y; z++;
		while (isect(y, z)) z = erase(z);
		while ((y = x) != begin() && isect(--x, y)) isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.m * x + l.k;
	}
} l;

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), qs[i] = a[i] + qs[i-1], sum[i] = a[i] * i + sum[i-1];
    ll ans = 0;

    l.add(0, 0);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum[i]+l.query(qs[i]));
        l.add(-i, -sum[i]+i*qs[i]);
    }

    printf("%lld", ans);
    return 0;
}