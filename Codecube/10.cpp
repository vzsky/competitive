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

lli c = 0;

int gcd (int a, int b) {
	if (b==0) return a;
	// cerr << b << ' ' << a%b << endl;
	return gcd(b, a%b);
}

bool prime(int a){
	int r = pow(a, 0.5);
	for(int i = 2; i <= r; i++){
		if(a%i==0) return 0;
	}
	return 1;
}

int n, b;

int main(){
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		if (prime(i)) c++;
	}
	scanf("%d", &b);
	if (b>=c) printf("0");
	else printf("%lld", c-b);
	return 0;
}
