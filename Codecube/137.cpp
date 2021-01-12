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

vector <int> v, v2;

int main(){
	int n;
	scanf("%d", &n);
	int mn = 2e9, save = -1;
	for(int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < n; i++){
		if (i == 0 && v[i+1]==v[i]) continue;
		if (i == n-1 && v[i-1]==v[i]) continue;
		if (v[i-1] == v[i] || v[i] == v[i+1]) continue;
		v2.push_back(v[i]);
	}
	//logvec(v2);
	int s = v2.size();
	for(int i = 0; i < s; i++){
		int k = abs(2017-v2[i]);
		if (k < mn) {
			mn = k;
			save = i;
		}
	}
	if (save == -1) { printf("-1"); return 0; }
	printf("%d", v2[save]);
	return 0;
}