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

int qx[100100];

int main(){
    int n, q;
    scanf("%d %d", &n , &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &qx[i]);
        qx[i] ^= qx[i-1];
    }
    for(int i = 0; i < q; i++){
        int a; int b;
        scanf("%d %d", &a, &b);
        printf("%d\n", qx[b]^qx[a-1]);
    }
    return 0;
}