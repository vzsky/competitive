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

int tab[650][400];

int main(){
    char opr;
    int dish, disw;
    scanf(" %c %d %d", &opr, &dish, &disw);
    while(1){
        scanf(" %c", &opr);
        if (opr == 'C') {
            int p, a, b, c, d;
            scanf("%d %d %d %d %d", &p, &a, &b, &c, &d);
            for(int i = a; i <= min(dish,(a+c-1)); i++){
                for(int j = b; j <= min(disw,(b+d-1)); j++){
                    tab[i][j] = p;
                }
            }
        }
        if (opr == 'G') {
            int a, b;
            scanf("%d %d", &a, &b);
            printf("%d\n", tab[a][b]);
        }
        if (opr == 'T') break;
    }
    return 0;
}