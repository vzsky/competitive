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

// log n = 

int a[1000100];
int tab[20][1000100];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &tab[0][i]);
    }
    for(int i=1; (1<<i) <= n; i++){
        for(int j = 0; j+(1<<i) <= n; j++){
            tab[i][j] = max(tab[i-1][j], tab[i-1][j+(1<<(i-1))]);
        }
    }

    while(q--){
        int x, y;
        scanf("%d %d", &x, &y);
        int k = y-x+1;
        k = log2(k);

        int ans = -2e9;
        ans = max(tab[k][x], tab[k][y-(1<<k)+1]);
        printf("%d\n", ans); 
    }

    //logmat(tab, 3, n-1);
    return 0;
}