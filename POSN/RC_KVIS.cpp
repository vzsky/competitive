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

int arr[510];
int mic[510][510][510];

int play(int l, int r, int k){
    if (mic[l][r][k]!=-1) return mic[l][r][k];
    if (l == r) return mic[l][r][0];
    // cerr << l << ' ' << r << ' ' << k << endl;
    int mn = 2e9;
    for(int i = l; i < r; i++){
        // can devide k-1
        for(int j = 0; j < k; j++){
            mn = min(mn, play(l, i, j)+play(i+1, r, k-j-1));
        }
    }
    // cerr << l << ' ' << r << ' ' << k << ' ' << mn << endl;
    return mic[l][r][k] = mn;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        arr[i]+=arr[i-1];
    }
    memset(mic, -1, sizeof mic);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int one = (arr[j]-arr[i-1]);
            // cerr << i << ' ' << j << ' ';
            mic[i][j][0] = (j-i+1-one)*one;
            // cerr << mic[i][j][0] << endl;
        }
    }
    printf("%d", play(1, n, k-1));
    return 0;
}