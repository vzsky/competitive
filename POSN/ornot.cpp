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

map <int, int> cnt;

char b[1000100];
int qs[1000100];

int main(){
    int n;
    scanf("%d %s", &n, b+1);
    for(int i = 1; i <= n; i++){
        qs[i] = b[i] == '1'? 1:-1;
        qs[i]+=qs[i-1];
    }
    int ans = 0;
    for(int i = 0; i <= n; i++){
        ans += cnt[qs[i]];
        ans %= 10007;
        cnt[qs[i]]++;
    }
    printf("%d", ans);
    return 0;
}