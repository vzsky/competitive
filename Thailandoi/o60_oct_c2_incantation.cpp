#include<bits/stdc++.h>
using namespace std;

int dimension;
const long long LLMIN = -1e15;

struct MAT {
    long long m[1<<7][1<<7];
    MAT operator * (const MAT & o) const {
        MAT temp;
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                temp.m[i][j] = 0; // Real solution 0 -> LLMIN;
                for(int k = 0; k < dimension; k++){
                    temp.m[i][j] = max(temp.m[i][j], m[i][k]+o.m[k][j]);
                }
            }
        }
        return temp;
    }
    void log() {
        for(int i = 0; i < dimension; i++){
            for(int j = 0; j < dimension; j++){
                if (m[i][j] < 0) {
                    cerr << "- "; continue;
                }
                cerr << m[i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;
    }
};

MAT m[30], ans;
int c[1<<10];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    dimension = (1<<(k-1));

    for(int i = 0; i < (1<<k); i++){
        scanf("%d", &c[i]);
    }

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            m[0].m[i][j] = LLMIN;
            // cerr << i << ' ' << j << ' ' << (i>>1) << ' ' << (j&((dimension-1)>>1)) << endl;
            if ((i>>1) == (j&((dimension-1)>>1))) {
                m[0].m[i][j] = c[(j<<1) + i%2];
            } 
        }
    }

    for(int i = 1; i < 30; i++){
        m[i] = m[i-1]*m[i-1];
    }

    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            ans.m[i][j] = LLMIN;
            if (i == j) ans.m[i][j] = 0;
        }
    }

    n-=k;n++;
    // cerr << n << endl;
    for(int i = 0; i < 30; i++){
        if ((1ll<<i)&(n)) 
        ans = ans * m[i];
        // cerr << i << endl;
        // ans.log();
    }
    // ans.log();
    long long mx = 0;
    for(int i = 0; i < dimension; i++){
        for(int j = 0; j < dimension; j++){
            mx = max(ans.m[i][j], mx);
        }
    }
    printf("%lld\n", mx);
    return 0;
}