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

int p[300100];
int rt[25][300100];
int lev[300100];

int main(){
    //rt[0][0] = 0;
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        char opr;
        scanf(" %c", &opr);
        if (opr == 'a') {
            int a;
            scanf("%d", &a);
            rt[0][i] = p[a];
            lev[i] = lev[p[a]]+1;
            for(int j = 1; j < 20; j++){
                rt[j][i] = rt[j-1][rt[j-1][i]];
            }
            p[i] = i;
            //cerr << name[i] << ' ' << lev[i] << ' ' << rt[0][i] << endl;
        }
        if (opr == 'b') {
            int a;
            scanf("%d", &a);
            printf("%d\n", p[a]==0?-1: p[a]);
            p[i] = rt[0][p[a]];
        }
        if (opr == 'c') {
            int a, b;
            scanf("%d %d", &a, &b);
            p[i] = p[a];
            a = p[a];
            b = p[b];
            if (lev[a] < lev[b]) swap(a, b);
            // cerr << p[a] << ' ' << p[b] << endl;
            while (lev[a] > lev[b]) {
                //cerr << 'a' << endl;
                for(int j = 19; j >= 0; j--){
                    //cerr << "TO " << rt[j][a] << ' ' << lev[rt[j][a]] << endl; 
                    if (lev[rt[j][a]] >= lev[b]) {
                        a = rt[j][a];
                        //cerr << "MOVE " << a << endl;
                    }
                }
            }
            if (a==b) goto p;
            // cerr << a << ' ' << b << endl;
            for(int j = 19; j >= 0; j--){
                if (rt[j][b] != rt[j][a]) {
                    b = rt[j][b];
                    a = rt[j][a];
                }
            }
            // cerr << a << ' ' << b << endl;
            a = rt[0][a];
            p:printf("%d\n", lev[a]);
        }
    }
    return 0;
}