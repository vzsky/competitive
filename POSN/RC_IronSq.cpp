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

#define qs(i, j) tab[i][j]-tab[i-k][j]-tab[i][j-k]+tab[i-k][j-k]

int tab[110][110];
char a[110][110];

int main(){
    int r, c, k;
    scanf("%d %d %d", &r, &c, &k);
    k-=2;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            scanf(" %c", &a[i][j]);
            tab[i][j] = a[i][j]=='.'?0:1;
            tab[i][j] += tab[i-1][j]+tab[i][j-1]-tab[i-1][j-1];
        }
    }
    int mx = -2e9; pii p;
    for(int i = k+1; i < r; i++){
        for(int j = k+1; j < c; j++){
            if (mx < qs(i, j)){
                mx = qs(i, j);
                p = {i, j};
            }
        }
    }
    printf("%d\n", mx);
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if ((i == p.x-k && j == p.y-k) || (i == p.x+1 && j == p.y-k) || (i == p.x-k && j == p.y+1) || (i == p.x+1 && j == p.y+1)) printf("+");
            else if ((i == p.x-k && j <= p.y+1 && j >= p.y-k) || (i == p.x+1 && j <= p.y+1 && j >= p.y-k )) printf("-");
            else if ((j == p.y-k && i <= p.x+1 && i >= p.x-k) || (j == p.y+1 && i <= p.x+1 && i >= p.x-k )) printf("|");
            else printf("%c", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}