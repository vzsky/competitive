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

char tab[1010][1010];

int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &tab[i][j]);
        }
    }
    int mn = 2e9;
    int sc;
    for(int j = 0; j < c; j++){
        for(int i = 0; i < r; i++){
            if (tab[i][j] == 'X') sc = i;
            if (tab[i][j] == '#') {
                mn = min(mn, i-sc);
            }
        }
    }
    mn--;
    for(int i = r-1; i >= 0; i--){
        for(int j = 0; j < c; j++){
            if (i-mn < 0) {
                continue;
            }
            if (tab[i-mn][j] == 'X') {
                tab[i-mn][j] = '.';
                tab[i][j] = 'X';
            }
        }
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%c", tab[i][j]);
        }
        printf("\n");
    }

    return 0;
}