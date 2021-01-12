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

lli p[400];
lli MOD=1000000007;

int play(int n){
    if (p[n]) return p[n];
    p[n] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if (i + j + k == n-1){
                    //cerr << i << ' ' << j << ' ' << k << endl;
                    lli sum = play(i);
                    sum *= play(j);
                    sum %= MOD;
                    sum *= play(k);
                    sum %= MOD;
                    //p[n] += (play(i)*play(j)*play(k))%MOD;
                    //p[n] %= MOD;
                    p[n]+=sum;
                    p[n]%=MOD;
                }
            }
        }
    }
    return p[n];
}

int main(){
    p[0] = 1;
    p[1] = 1;
    p[2] = 3;
    for(int i = 0; i <= 350; i++){
        printf("p[%d] = %d\n", i, play(i));
    }
    return 0;
}