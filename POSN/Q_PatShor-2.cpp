#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef long long lli;
typedef pair<lli,lli> point;
typedef vector<int> vi;

// map<point, vector<point>> mp;
vector<pair<point, point>> allPortal;
map<point, lli> dist;

point e;

struct A {
    lli x, y, dis;
    bool operator < (const A & o ) const {
        return dis > o.dis;
    }
};
priority_queue <A> heap;

// int di[] = {-1, 1, -1, 1, -1, 1};
// int dj[] = {0, 0, -1, -1, 1, 1};

lli dis (point a, point b) {
    lli x = abs(a.x-b.x);
    lli y = abs(a.y-b.y);
    if (x > y) return x;
    return x+((y-x+1)/2)*2;
}

int main(){
    lli m, Q;

    scanf("%lld %lld", &m, &Q);
    for(int i = 0; i < m; i++){
        lli a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        allPortal.pb({{a, b}, {c, d}});
        allPortal.pb({{c, d}, {a, b}});
    }

    sort(allPortal.begin(), allPortal.end());
    allPortal.resize(unique(allPortal.begin(), allPortal.end()) - allPortal.begin());

    while(Q--) {
        lli a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        e = {c, d};
        dist.clear();
        while(!heap.empty()) heap.pop();
        
        // bfs a ,b, 0;
        heap.push({a, b, 0});
        while(!heap.empty()) {
            auto t = heap.top();
            heap.pop();

            // cerr << t.x << ' ' << t.y << ' ' << t.dis << endl;

            if (t.x == e.x and t.y == e.y) {
                printf("%lld\n", t.dis);
                break;
            }

            if (dist[{t.x, t.y}]) continue;
            dist[{t.x, t.y}] = t.dis;


            // endpoint
            heap.push({e.x, e.y, t.dis+dis({t.x, t.y}, e)});
        

            // for(auto x : mp[{t.x, t.y}]) {
            //     if (dist[x]) continue;
            //     heap.push({x.x, x.y, t.dis+1});
            // }
            for(auto x : allPortal) {
                if (dist[x.y]) continue;
                heap.push({x.y.x, x.y.y, t.dis+1+dis(x.x, {t.x, t.y})});
            }
        }
        // cerr << endl;

    }
    return 0;
}