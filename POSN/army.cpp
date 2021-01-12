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

lli dp[1<<12], mask[1<<12];
// dp stores ans in each combination
// mask stores amount of gun in each army

lli play(lli bit){
    if (dp[bit]!=-1) return dp[bit]; // built dp
    if (__builtin_popcount(bit)==1) return dp[bit] = 0; // if only one army

    for(int i = 1; i < bit; i++){ // loop every possible army
        if ((i&bit)!=i) continue; // there exists some 1s in i but not in bit, therefore impossible to build bit
        lli cost = max((~mask[i])&mask[i^bit], (~mask[i^bit])&mask[i]); // cost for combining two possible armys
        dp[bit] = max(dp[bit], play(i)+play(bit^i)+cost); // max of every answer candidate
    }
    return dp[bit]; // return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        memset(dp, -1, sizeof(dp));
        memset(mask, 0, sizeof mask);
        int n, m;
        scanf("%d %d", &n, &m); //armys, sizes of rebot

        for(int i = 0; i < n; i++){
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k; j++){
                int a;
                scanf("%d", &a);
                mask[1<<i]|=(1ll<<(a-1)); // def mask is 00000000, (1ll<<a-1) is a robot
            }
        }

        //generating maskkkkk
        for(int i = 1; i <(1<<n); i++){ // bit to generate, every possible bit(robot) in n army
            for(int j = 0; j < n; j++){ // each bit in i
                if (i&(1<<j)){ // 1 found (least value)
                    mask[i] = mask[1<<j]^mask[i^(1<<j)];
                    break;
                }
            }
        }
        printf("%lld\n", play((1<<n)-1));
        memset(mask, 0, sizeof mask);
    }
    return 0;
}