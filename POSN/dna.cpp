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

char s[10100], gold[5010];
int cost[4], mn[4][5010];

int main(){
    scanf(" %s %s %d %d %d %d", s+1, gold+1, &cost[0], &cost[1], &cost[2], &cost[3]);
    int l = strlen(s+1);
    int n = strlen(gold+1);
    int all = 0;

    for(int i = 1; i <= n; i++){
        int ind;
        switch (gold[i]){
            case 'A' : ind = 0; break;
            case 'C' : ind = 1; break;
            case 'G' : ind = 2; break;
            case 'T' : ind = 3; break;
        }
        all += cost[ind];
    }

    for(int i = 0; i <= n; i++){
        mn[0][i] = gold[i] == 'A'? i : 2e9;
        mn[1][i] = gold[i] == 'C'? i : 2e9;
        mn[2][i] = gold[i] == 'G'? i : 2e9;
        mn[3][i] = gold[i] == 'T'? i : 2e9;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            mn[j][i] = min(mn[j][i+1], mn[j][i]);
        }
    }

    // logmat(mn, 3, n);

    int mxminus = 0;
    for(int i = 1; i <= l; i++){
        int cur = 0;
        int minus = 0;
        for(int j = i; j <= l; j++){
            int ind;
            switch (s[j]){
                case 'A' : ind = 0; break;
                case 'C' : ind = 1; break;
                case 'G' : ind = 2; break;
                case 'T' : ind = 3; break;
            }
            cur = mn[ind][cur+1];
            // cerr << "cur " << i << ' ' << cur << endl;
            if (cur == 2e9 || cur == 0) break;
            minus += cost[ind];
            // cerr << ind << endl;
        }      
        // cerr << i <<' ' << minus << endl;
        mxminus = max(mxminus, minus);
    }
    printf("%d", all-mxminus);
    return 0;
}