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

map<int,int> dis;

int level (int i){
    return log2(i);
}

int main(){
    inp(m, int);
    int u, v, w;
    while(m--){
        char opr;
        scanf(" %c", &opr);
        if (opr == 'U'){
            scanf("%d %d %d", &u, &v, &w);
            while (level(u) > level(v)) {
                dis[u]+=w; u/=2;
            }
            while (level(u) < level(v)) {
                dis[v]+=w; v/=2;
            }
            while(u!=v){
                dis[u]+=w;
                dis[v]+=w;
                u/=2;
                v/=2;
            }
        }
        else {
            scanf("%d %d", &u, &v);
            int ans = 0;
            while (level(u) > level(v)) {
                ans += dis[u]; u/=2;
            }
            while (level(u) < level(v)) {
                ans += dis[v]; v/=2;
            }
            while(u!=v){
                ans += dis[u]; u/=2;
                ans += dis[v]; v/=2;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}