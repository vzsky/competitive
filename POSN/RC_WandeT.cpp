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

vi g[1010];
int out[1010];

int out1[1010], mark[1010], mk[1010];

queue<int> q;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[b].pb(a);
        out[a]++;
    }
    int quest;
    scanf("%d", &quest);
    while(quest--){

        for(int i = 1; i <= n; i++){
            out1[i] = out[i];
            mk[i] = 0;
            mark[i] = 0;
        }

        int amn;
        scanf("%d", &amn);
        for(int i = 0; i < amn; i++){
            int a;
            scanf("%d", &a);
            out1[a] = 0;
            mk[a] = 1;
            // for(auto x : g[a]) {
            //     out[x]--;
            // }
        }
        for(int i = 1; i <= n; i++){
            // for(auto x : g[i]) {
            //     if (mk[x]) out[i]--;
            // }
            if (out1[i] <= 0) q.push(i);
        }


        while(!q.empty()){
            auto t = q.front(); q.pop();
            mark[t] = 1;
            for(auto x : g[t]){
                out1[x]--;
                if (out1[x] == 0) q.push(x);
            }
        }
        int ch = 0;
        for(int i = 1; i<= n; i++){
            if (!mark[i]) {
                printf("%d ", i);
                ch = 1;
            }
        }
        if (!ch) printf("-1");
        printf("\n");

    }
    return 0;
}