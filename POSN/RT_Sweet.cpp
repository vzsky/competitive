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

lli n, m;
lli mean, sum;
int a[100100], b[100100];

int main(){
    scanf("%lld %lld", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        mean += a[i];
    }

    if (mean % n == 0) mean--;
    mean /= n;
    mean++;

    int l = mean; int r = 1e9;
    while(l < r) {

        // cerr << l << ' ' << r << endl;
        int mid = (l+r)>>1;
        // log(mid);
        lli tak = 0;
        for(int i = 1; i <= n; i++){
            if (a[i] > mid) tak+=a[i]-mid;
        }
        if (tak > m) l = mid+1;
        else         r = mid;
    }

    printf("%d", l);
    
    return 0;
}