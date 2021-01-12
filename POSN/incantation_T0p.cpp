#include<bits/stdc++.h>
using namespace std;
int k;
struct data{
    long long t[130][130];
    void log() {
        for(int i = 0; i < (1<<k); i++){
            for(int j = 0; j < (1<<k); j++){
                if (t[i][j] <= 0) {cerr << "- "; continue;}
                cerr << t[i][j] << ' ';
            }
            cerr << endl;
        }
        cerr << endl;
    }
};
data M[65], temp, ans;
void process(data *a, data *b, int sz){
    memset(temp.t, 0, sizeof temp.t);
    for(int i=0 ; i<(1<<sz) ; i++){
        for(int j=0 ; j<(1<<sz) ; j++){
            for(int k=0 ; k<(1<<sz) ; k++){
                temp.t[i][j] = max(temp.t[i][j], a->t[i][k] + b->t[k][j]);
            }
        }
    }
}
int main(){
    int n;
    scanf(" %d %d",&n,&k);
    for(int i=0 ; i<(1<<k) ; i++){
        for(int j=0 ; j<(1<<k) ; j++){
            M[0].t[i][j] = -1e15;
        }
    }
    for(int i=0 ; i<(1<<k) ; i++){
        int d;
        scanf(" %d",&d);
        M[0].t[i][i/2 + (1<<(k-1))] = M[0].t[i][i/2] = d;
    }
    for(int i=1 ; i<30 ; i++){
        process(&M[i-1], &M[i-1], k);
        M[i] = temp;
    }
    M[0].log();
    M[1].log();
    M[2].log();
    // M[3].log();
    for(int i=0 ; i<30 ; i++){
        if((1ll<<i)&(n-k+1)){
            process(&ans, &M[i], k);
            ans = temp;
        }
    }
    // ans.log();
    long long val = -1;
    for(int i=0 ; i<(1<<k) ; i++){
        for(int j=0 ; j<(1<<k) ; j++){
            val = max(val, ans.t[i][j]);
        }
    }
    printf("%lld\n",val);
    return 0;
}