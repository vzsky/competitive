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

struct A {
    lli m[3][3];
};
A temp;
void mul (A *a, A *b){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            temp.m[i][j] = 0;
            for(int k = 0; k < 3; k++){
                temp.m[i][j] += a->m[i][k]*b->m[k][j];
                temp.m[i][j] %= MOD;
            }
        }
    }
}

A f[30];
A ans;

int main(){

    int arr[3][3] = {0, 0, 6, 1, 0, 5, 0, 1, -2};
    //logmat(arr, 2, 2);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            f[0].m[i][j] = arr[i][j];
        }
    }

    for(int i = 1; i <= 25; i++){
        mul(&f[i-1], &f[i-1]);
        f[i] = temp;
    }

    int t;
    scanf("%d", &t);
    for(int xxx =1; xxx <= t; xxx++){
        printf("Case #%d: ", xxx);

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                ans.m[i][j] = arr[i][j];
            }
        }

        int a;
        scanf("%d", &a);

        if (a == 0) { printf("14\n"); continue; }

        a--;
        //logmat(ans.m, 2, 2);
        for(int i = 0; i <= 25; i++){
            if (a & (1<<i)) {
                //cerr << i;
                mul(&ans, &f[i]);
                ans = temp;
            }
        }

        int b[ ] = {14, 15, 63};

        lli realans = 0;
        for(int i = 0; i < 3; i++){
            realans += b[i] * ans.m[i][0];
            realans %= MOD;
        }

         printf("%lld\n", (realans+MOD)%MOD);
        //printf("%lld\n", realans);

    }
    return 0;
}