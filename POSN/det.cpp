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

struct A {
    lli a[10][10];
};

A a;

lli det (int n, A mat){

    // logmat(mat.a, n-1, n-1);
    // cerr << endl;

    if (n == 2) {
        //cerr << mat.a[0][0]*mat.a[1][1] - mat.a[1][0]*mat.a[0][1] << endl;
        return mat.a[0][0]*mat.a[1][1] - mat.a[1][0]*mat.a[0][1];
    }

    lli d = 0;

    A matb;

    for(int i = 0; i < n; i++){
        lli sv = mat.a[0][i];
        if (i&1) sv*=-1;

        int ii = 0, jj = 0;
        for(int k = 1; k < n; k++){
            for(int l = 0; l < n; l++){
                if (l == i) continue;
                //cerr << mat.a[k][l] << ' ' ;
                //cerr << ii << jj << mat.a[k][l] << endl;
                matb.a[ii][jj++] = mat.a[k][l];
                if (jj == n-1) {jj = 0; ii++;}
            }
            //cerr << endl;
        }
            
        sv *= det(n-1, matb);
        //cerr << "\t" << sv << endl;
        d += sv;
    }
    
    //cerr << d << endl;
    return d;

}

int main(){
    int n;
    scanf("%d", &n);
    For(i,0,n-1){
        For(j, 0, n-1){
            scanf("%lld", &a.a[i][j]);
        }
    }
    if (n == 1) printf("%lld", a.a[0][0]);
    else printf("%lld", det(n, a));
    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// #define inp(a, b) b a; cin >> a;
// #define x first
// #define y second
// #define pb push_back
// #define For(i, start, en) for(auto i = start; i <= en; i++)
// #define log(x) cerr << #x << " is " << x << endl;
// #define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
// #define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
// #define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
// typedef long long int lli;
// typedef pair<int,int> pii;
// typedef vector<int> vi;

// lli a[10][10];

// int main(){
//     int n;
//     scanf("%d", &n);
//     For(i,0,n-1){
//         For(j, 0, n-1){
//             scanf("%lld", &a[i][j]);
//         }
//     }
//     if (n == 1) printf("%lld", a[0][0]);
//     else if (n == 2) printf("%lld", a[0][0]*a[1][1]-a[1][0]*a[0][1]);
//     else if (n == 3) printf("%lld", a[0][0]*a[1][1]*a[2][2]+a[1][0]*a[2][1]*a[0][2]+a[2][0]*a[0][1]*a[1][2]-a[2][0]*a[1][1]*a[0][2]-a[1][0]*a[0][1]*a[2][2]-a[0][0]*a[1][2]*a[2][1]);
//     else {
//         int ans = 1;
//         for(int i = 0; i < n; i++){
//             ans *= a[i][i];
//         }
//         printf("%d", ans);
//     }
//     return 0;
// }