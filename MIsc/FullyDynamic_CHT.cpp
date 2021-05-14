#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Line {
	mutable ll k, m;
	mutable double p;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	const double inf = 1/.0;
	double div(ll a, ll b) { return (double)a/b; }
	bool isect(iterator x, iterator y) {
		if (y == end()) { x->p = inf; return false; }
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({-k, -m, 0}), y = z++, x = y;						// negative for min envelope
		while (isect(y, z)) z = erase(z);									
		if ((y = x) != begin() && isect(--x, y)) isect(x, erase(y));		// needed to update y first, if remove y return is okay
		while ((y = x) != begin() && isect(--x, y)) isect(x, erase(y));		// in case not remove y but remove x
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return -l.k * x + -l.m;												// negative for min envelope
	}
};