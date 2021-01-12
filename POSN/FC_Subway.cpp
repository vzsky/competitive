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

vi sta[1000100];
int dis[510][510];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++){
        int a;
        scanf("%d", &a);
        while(a--){
            int b;
            scanf("%d", &b);
            sta[b].pb(i);
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= m; j++){
            if (i == j) dis[i][j] = 0;
            else        dis[i][j] = 1e9;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 0; j < sta[i].size(); j++){
            for(int k = j+1; k < sta[i].size(); k++){
                if (sta[i][j] == sta[i][k]) continue;
                dis[sta[i][j]][sta[i][k]] = dis[sta[i][k]][sta[i][j]] = 1;
            }
        }
    }

    for(int k = 1; k <= m; k++){
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= m; j++){
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    //logmat(dis, n, n);

    int q;
    scanf("%d", &q);
    while(q--){
        int a, b;
        int ans = 1e9;
        scanf("%d %d", &a, &b);
        for(int i = 0; i < sta[a].size(); i++){
            for(int j = 0; j < sta[b].size(); j++){
                ans = min(ans, dis[sta[a][i]][sta[b][j]]);
            }
        }
        if (ans == 1e9) printf("impossible\n");
        else            printf("%d\n", ans);
    }

    return 0;
}