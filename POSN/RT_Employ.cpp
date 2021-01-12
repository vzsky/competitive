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

int n;

struct MAT {
    double m[255][255];
    MAT operator * (const MAT & o) const{
        MAT temp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                temp.m[i][j] = 0;
                for(int k = 1; k <= n; k++){
                    temp.m[i][j] += m[i][k] * o.m[k][j];
                }
            }
        }
        return temp;
    }
};

MAT mat[25];
MAT ans;

int init[270];

int main(){
    int t;
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++){
        scanf("%d", &init[i]);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf(" %lf", &mat[0].m[i][j]);
        }
    }

    for(int i = 1; i < 25; i++){
        mat[i] = mat[i-1] * mat[i-1];
    }

    for(int i = 1; i <= n; i++){
        ans.m[i][i] = 1;
    }

    for(int i = 0; i < 25; i++){
        if ((1<<i)&t) {
            ans = ans * mat[i];
        }
    }

    //logmat(ans.m, n+1, n+1)

    for(int i = 1; i <= n; i++){
        double a = 0;
        for(int j = 1; j <= n; j++){
            a += init[j] * ans.m[j][i];
        }
        printf("%.2lf\n", a);
    }

    return 0;
}