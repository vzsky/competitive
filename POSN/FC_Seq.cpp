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

#define MOD 2553

struct MT {
    int m[4][4];
};

MT temp;

void mul (MT *a, MT *b){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            temp.m[i][j] = 0;
            for(int k = 0; k < 4; k++){
                temp.m[i][j] += (a->m[i][k]*b->m[k][j])%MOD;
                temp.m[i][j] %= MOD;
            }
        }
    }
}

int ap[10];
MT l[60];
MT ans;

int main(){
    for(int i = 1; i <= 8; i++) scanf("%d", &ap[i]);

    l[0].m[0][0] = ap[5]; l[0].m[0][1] = ap[6]; l[0].m[0][2] = ap[7]; l[0].m[0][3] = ap[8];
    l[0].m[1][0] = l[0].m[2][1] = l[0].m[3][2] = 1;

    for(int i = 1; i < 60; i++) {
        mul(&l[i-1], &l[i-1]);
        l[i] = temp;
    }

    int q;
    scanf("%d", &q);

    for(int i = 0; i < q; i++){
        lli n;
        scanf("%lld", &n);
        if (n <= 4) {
            printf("%d\n", ap[n]);
            continue;
        }

        memset(ans.m, 0, sizeof ans.m);
        for(int i = 0; i < 4; i++) ans.m[i][i] = 1;

        n-=4;

        for(int i = 0; i < 60; i++){
            if (n&(1ll<<i)) {
                mul(&ans, &l[i]);
                ans = temp;
            }
        }

        int ANS = ans.m[0][0]*ap[4] + ans.m[0][1]*ap[3] + ans.m[0][2]*ap[2] + ans.m[0][3]*ap[1];

        printf("%d\n",ANS%MOD);

    }
    return 0;
}