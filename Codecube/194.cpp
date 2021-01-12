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

int a[100100];
int top[100100];
vi lis[100100];
lli sum = 0;

bool REV (int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		top[i] = 2e9;
	}
	top[0] = a[0];
	lis[0].pb(a[0]);
	int cnt = 0;
	for(int i = 1; i < n; i++){
		int bs = upper_bound(top, top+n, a[i]) - top;
		if (top[bs] == a[i]) bs++;
		cnt = max(bs, cnt);
		lis[bs].pb(a[i]);
		top[bs] = a[i];
   }
   int ls = cnt;
   printf("%d ", ls+1);
   sum = lis[ls][0];
   //cerr << sum;
   int last = lis[ls][0];
   for(int i = ls-1; i >= 0; i--){
	   //for(auto x : lis[i]) cerr << x << ' ';
	   //cerr << endl;
	   int bs = lower_bound(lis[i].begin(), lis[i].end(), last, REV)-lis[i].begin();
	   while (lis[i][bs] > last) bs--;
	   //cerr << lis[i][bs];
	   sum += lis[i][bs];
	   last = lis[i][bs];
   }
   printf("%lld", sum);
	return 0;
}