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

vector <pii> c;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	For(i, 0, n-1){
		pii a;
		scanf("%d %d", &a.x, &a.y);
		c.pb(a);
	}
	For(i, 0, m-1){
		int b;
		scanf("%d", &b);
		for(int i = 0; i < n; i++){
			if (c[i].x <= b){
				c[i] = {c[i].y, c[i].x};
			}
		}
	}
	for(auto x : c){
		printf("%d\n",x.x);
	}
	return 0;
}