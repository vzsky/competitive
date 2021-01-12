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

const int mod = 10007;
int n;

struct MAT {
    int m[205][205];
    MAT operator * (const MAT & o) const{
        MAT temp;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                temp.m[i][j] = 0;
                for(int k = 1; k <= n; k++){
                    temp.m[i][j] += (m[i][k] * o.m[k][j]) % mod;
                }
                temp.m[i][j] %= mod;
            }
        }
        return temp;
    }
};

MAT mat[35];
MAT ans;

int main(){
    int t, m;
    scanf("%d %d %d", &n, &m, &t);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        mat[0].m[a][b] = mat[0].m[b][a] = 1;
    }

    for(int i = 1; i <= n; i++){
        ans.m[i][i] = 1;
        mat[0].m[i][i] = 1;
    }

    for(int i = 1; i < 32; i++){
        mat[i] = mat[i-1] * mat[i-1];
    }

    for(int i = 0; i < 32; i++){
        if ((1<<i)&t) {
            ans = ans * mat[i];
        }
    }

    for(int i = 1; i <= n; i++){
        printf("%d ", ans.m[i][1]);
    }

    return 0;
}