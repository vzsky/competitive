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

int a[700100], mark[700100];
pii b[700100];

bool sorty (pii a, pii b) {
	return a.y < b.y;
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= m; i++) { scanf("%d", &b[i].x); b[i].y = i; }
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);

	for(int i = 1; i <= n; i++){
		int l = 1, r = m+1;
		while (l < r) {
			int mid = (l+r)>> 1;
			if (b[mid].x >= a[i]-i+1) r = mid;
			else l = mid+1;
		}
		//cerr << l << endl;
		mark[l]++;
	}
	for(int i = 1; i <= m; i++){
		mark[i] += mark[i-1];
		b[i].x+=mark[i];
	}
	sort(b+1,b+m+1, sorty);
	for(int i = 1; i <= m; i++){
		printf("%d ", b[i].x);
	}
	return 0;
}