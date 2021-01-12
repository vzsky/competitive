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

int key[100100];
int tr[100100];
lli pt = 0;
lli ans;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        int inp;
        scanf("%d", &inp);
        key[inp] = i;
    }
    k--;
    ans += key[1]-1; // door 1;
    for(int i = 2; i <= n; i++){ // door 2-n ;
        if (key[i] < key[i-1])  tr[i] = key[i] + n - key[i-1];
        else                    tr[i] = key[i]-key[i-1];
    }

    if (key[1] < key[n])    tr[1] = key[1] + n - key[n];
    else                    tr[1] = key[1]-key[n];

    for(int i = 1; i <= n; i++) pt+=tr[i];

    int times = k/n;
    int rem = k%n;

    ans += times*pt;
    for(int i = 2; i < 2+rem; i++){
        if (i == n+1) {
            ans += tr[1]; continue;
        }
        ans += tr[i];
    }
    
    printf("%lld", ans);
    return 0;
}