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

#define MOD 1000000007
#define MAXN 201

struct MT {
    lli m[204][204];
};

MT temp;

void mul (MT *a, MT *b) {
    for(int i = 1; i <= MAXN; i++){
        for(int j = 1; j <= MAXN; j++){
            temp.m[i][j] = 0;
            for(int k = 1; k <= MAXN; k++){
                temp.m[i][j] += (a->m[i][k]*b->m[k][j])%MOD;
                temp.m[i][j] %= MOD;
            }
        }
    }
}

MT mic[30], ans;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    mic[0].m[1][1] = 1;

    for(int i = 2; i < MAXN; i++){
        for(int j = 1; j <= i; j++){
            mic[0].m[i][j] = (mic[0].m[i-1][j-1] + mic[0].m[i-1][j])%MOD;
        }
    }
    mic[0].m[MAXN][MAXN] = mic[0].m[MAXN][k+1] = 1;

    logmat(mic[0].m, 10, 10);

    for(int i = 1; i <= 29; i++){
        mul(&mic[i-1], &mic[i-1]);
        mic[i] = temp;
    }

    memset(ans.m, 0, sizeof ans.m);
    for(int i = 1; i <= MAXN; i++) ans.m[i][i] = 1;

    for(int i = 0; i <= 29; i++){
        if (n&(1ll<<i)){
            mul(&mic[i], &ans);
            ans = temp;
        }
    }

    lli ANS = 0;

    for(int i = 1; i < MAXN; i++){
        ANS += ans.m[MAXN][i];
        ANS %= MOD;
    }

    //logmat(ans.m, 3, 3);

    printf("%lld", ANS);

    return 0; 
}