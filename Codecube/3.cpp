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

lli a, b, m;

int gcd (int a, int b) {
	if (b==0) return a;
	// cerr << b << ' ' << a%b << endl;
	return gcd(b, a%b);
}

int main(){
	scanf("%lld %lld", &a, &b);
	m = a*b;
	if (a < b) swap(a, b);
	printf("%lld", m/gcd(a, b));
	return 0;
}
