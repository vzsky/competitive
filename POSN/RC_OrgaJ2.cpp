#include<bits/stdc++.h>
using namespace std;

int MOD = 1000000007;

struct MT {
    lli m[2][2];
};

MT temp;

void mul (MT *a, MT *b){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            temp.m[i][j] = 0;
            for(int k = 0; k < 2; k++){
                temp.m[i][j] += (a->m[i][k]*b->m[k][j])%MOD;
                temp.m[i][j] %= MOD;
            }
        }
    }
}

MT mat[60];
MT ans;

int main(){
    int q;
    scanf("%d", &q);

    mat[0].m[1][0] = 1;
    mat[0].m[0][0] = 1;
    mat[0].m[0][1] = 1;

    for(int i = 1; i <= 59; i++){
        //mat[i] = mat[i-1]*mat[i-1];
        mul(&mat[i-1], &mat[i-1]);
        mat[i] = temp;
    }
    //logmat(mat[1].m, 2, 2);

    while(q--){
        lli a;
        scanf("%lld", &a);
        a-=2;
        if (a <= 0) {
            a+=2;
            printf("%d\n",a==0?0:1);
            continue;
        }
        
        memset(ans.m, 0, sizeof ans.m);
        for(int i = 0; i < 2; i++){
            ans.m[i][i] = 1;
        }

        for(int i = 0; i <= 59; i++){
            if ((1ll<<i)&a) {
                //cerr << i << endl;
                //ans = ans* mat[i];
                mul(&ans, &mat[i]);
                ans = temp;
            }
        }
        //cerr << endl;

        //logmat(ans.m, 2, 2);

        lli aans = (ans.m[1][0]+ans.m[0][0])%MOD;
        printf("%lld\n", aans);
        
    }
    return 0;
}