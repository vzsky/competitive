#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

int rmq[20][100100];

int main(){

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &rmq[0][i]);
    }

    for(int i = 1; (1<<i) <= n; i++){
        for(int j = 0; j+(1<<(i-1)) <= n; j++){
            rmq[i][j] = max(rmq[i-1][j], rmq[i-1][j+(1<<(i-1))]);
        }
    }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        int lev = log2(b-a+1);
        int ans = max(rmq[lev][a], rmq[lev][b-(1<<lev)+1]);
        printf("%d\n", ans);
    }
    
    return 0;
}