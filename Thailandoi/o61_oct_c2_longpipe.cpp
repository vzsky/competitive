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

const int MOD =  1e9+7;

struct A { 
    lli m[3][3];
    A operator * (const A & o) const {
        A temp;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++){
                temp.m[i][j] = 0;
                for(int k = 0; k < 3; k++){
                    temp.m[i][j] += m[i][k]*o.m[k][j];
                    temp.m[i][j] %= MOD;
                }
                temp.m[i][j] %= MOD;
            }
        }
        return temp;
    }
};

A mat[35];
A ans;

int main(){
    mat[0] = {1,1,1, 2,1,0, 1,0,1};
    for(int i = 1; i <= 31; i++) {
        mat[i] = mat[i-1]*mat[i-1];
    }
    lli n;
    scanf("%lld", &n);
    ans = {1,0,0,0,1,0,0,0,1};
    for(int i = 0; i <= 31; i++) {
        if ((1<<i) & n) {
            ans = ans * mat[i];
        }
    }
    lli realans = 0;
    realans += 2*(ans.m[0][0]+ans.m[0][1]);
    realans += ans.m[1][0]+ans.m[1][1];
    realans %= MOD;
    cout << realans;
    return 0;
}