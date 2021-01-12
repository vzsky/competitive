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
typedef pair<lli,lli> pii;
typedef vector<lli> vi;

int n, p, s, o;

struct A {
    lli node, dis;
};

pii man[15100];
lli dis[15100];

lli dist(int i, int j) {
    if (p == 1) return 2*(abs(man[i].x-man[j].x)+abs(man[i].y-man[j].y));
    if (p == 2) return 2*((man[i].x-man[j].x)*(man[i].x-man[j].x)+(man[i].y-man[j].y)*(man[i].y-man[j].y));
    return 2*(abs((man[i].x-man[j].x)*(man[i].x-man[j].x)*(man[i].x-man[j].x))+abs((man[i].y-man[j].y)*(man[i].y-man[j].y)*(man[i].y-man[j].y)));
}

int main(){
    scanf("%d %d %d %d", &n, &p, &s, &o);
    for(int i = 1; i <= n; i++){
        scanf("%lld %lld", &man[i].x, &man[i].y);
    }

    for(int i = 1; i <= n; i++) dis[i] = 1e18;

    lli mn, mst = 0;
    int node = 1, mstcnt = n-1, newnode; 
    while(mstcnt--){
        mn = 1e18;
        for(int i = node+1; i <= n; i++){
            dis[i] = min(dis[i], dist(i, node));
            if (mn > dis[i]){
                mn = dis[i];
                newnode = i;
            }
        }
        swap(dis[node+1], dis[newnode]);
        swap(man[node+1], man[newnode]);
        node++;
        mst += mn;
    }
    printf("%lld", mst+(n-1)*o);
    return 0;
}