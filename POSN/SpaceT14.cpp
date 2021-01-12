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
#define logmat(a, m, n) For(i, 1, m) { For(j, 1, n) cerr << a[i][j]; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

int n, m;

int tab[1010][2010];

int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};

void play(int i, int j){
    //cerr << i << ' ' << j << endl;
    //if (i < 0 || j < 0 || i >= m || j >= n) return;
    tab[i][j] = 0;
    for(int d= 0; d < 4; d++){
        int ni = i+di[d], nj = j+dj[d];
        if (ni <= 0 || nj <= 0 || ni > m || nj > n) continue;
        if (tab[ni][nj]) play(ni, nj);
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            char c;
            scanf(" %c", &c);
            tab[i][j] = c-'0';
        }
    }
    int tri = 0, dia = 0, sqr = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (!tab[i][j]) continue;
            int mx1 = 0, mx2 = 0, mx3 = 0, mx4 = 0;
            for(int ii = j; ii <= n; ii++){
                if (!tab[i][ii]) break;
                mx1++;
            }
            for(int ii = i; ii <= m; ii++){
                if (!tab[ii][j]) break;
                mx2++;
            }
            for(int ii = 0; ii <= max(n, m); ii++){
                if (i+ii > m || j+ii > n) break;
                if (!tab[i+ii][j+ii]) break;
                mx3++;
            }
            for(int ii = 0; ii <= max(n, m); ii++){
                if (i+ii > n || j-ii <= 0) break;
                if (!tab[i+ii][j-ii]) break;
                mx4++;
            }
            // cerr << mx1 << ' ' << mx2 << ' ' << mx3 << ' ' << mx4 << endl;
            if (mx1 == mx2 && mx1 == mx3) sqr++;
            else if ((mx2+1)/2 == mx3 && mx3 == mx4) dia++;
            else tri++;
            play(i, j);
            // logmat(tab, m, n);
            // cerr << endl;
        }
    }
    printf("%d %d %d",sqr, dia, tri);
    return 0;
}