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

int pascal[2200][1100];
int catalan[1010];

#define md 9973

int play(int n){
    int sum = 0;
    if (catalan[n]!=-1) return catalan[n];
    for(int i = 0; i < n; i++){
        int a = catalan[i]==-1? play(i):catalan[i];
        a %= md;
        int b = catalan[n-1-i]==-1? play(n-1-i):catalan[n-1-i];
        b %= md;
        sum += a*b;
        sum%= md;
    }
    return catalan[n] = sum%md;
}

int main(){
    // pascal[1][1] = 1;
    // for(int i =2; i <= 2000; i++){
    //     for(int j = 1; j <= 1000; j++){
    //         pascal[i][j] = pascal[i-1][j] + pascal[i-1][j-1];
    //         pascal[i][j]%=md;
    //     }
    // }
    memset(catalan, -1, sizeof(catalan));
    catalan[0] = catalan[1] = 1;
    play(1000);
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        n--;
        printf("%d\n", catalan[n]);
        // if (n == 0) { printf("1"); continue; }
        // printf("%d\n", (pascal[2*n][n] - pascal[2*n][n-1])%md);
    }
    return 0;
}