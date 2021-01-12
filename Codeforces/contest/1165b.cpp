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

int a[200100];

int ans;
int main(){
    int n;
    scanf("%d", &n);
    For(i, 1, n){
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    logarr(a+1, a+n+1);
    for(int i = 1, d = 1; i <= n; i++){
        if (d > a[i]) {
            //cerr << i << ' ' << a[i] << endl;
            continue;
        }
        d++;
        ans++;
    }
    printf("%d", ans);
    return 0;
}