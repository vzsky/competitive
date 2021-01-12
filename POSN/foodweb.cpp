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

vi c[100100];
int lev[100100];

void root(int r = 1, int l = 1){
    lev[r] = l;
    for(auto x : c[r]) {
        root(x, l+1);
    }
}

int rt[20][100100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        rt[0][v] = u;
        c[u].pb(v);
    }

    for(int i = 1; i < n; i++){
        if (rt[0][i] == 0) {
            rt[0][i] = i;
            root(i);
            break;
        }
    }

    for(int i = 1; i < 18; i++){
        for(int j = 1; j <= n; j++){
            rt[i][j] = rt[i-1][rt[i-1][j]];
        }
    }

    //logarr(rt[1], 14); cerr << endl;

    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int a, b;
        scanf(" %d %d", &a, &b);
        //cerr << a << ' ' << b << endl;
        while (lev[a] > lev[b]){
            for(int i = 17; i >= 0; i--){
                if (lev[rt[i][a]] >= lev[b]) a = rt[i][a];
            }
        }
        while (lev[a] < lev[b]){
            for(int i = 17; i >= 0; i--){
                if (lev[rt[i][b]] >= lev[a]) b = rt[i][b];
            }
        }
        //cerr << a << ' ' << b << endl;
        // lev[a] == lev[b]
        while(a != b) {
            a = rt[0][a];
            b = rt[0][b];
        }
        printf("%d\n", a);
    }
    return 0;
}