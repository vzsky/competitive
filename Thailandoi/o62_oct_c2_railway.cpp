#include<bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()

struct A { 
    int a, b, c;
    bool operator < (const A & o ) const {
        return c < o.c;
    }
};

int p[200100];
int find(int u) {return u==p[u]? u : p[u] = find(p[u]);}
set<int> w;

vector<A> want, other;

int l[200100], r[200200], ans[200200];
vector<int> mid[200200];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (i < n-1) want.push_back({a, b, c});
        else { other.push_back({a, b, c}); w.insert(c); }
    }
    sort(all(want));

    for(int i = 0; i < other.size(); i++) {
        l[i] = 0; r[i] = want.size()-1;
    }

    bool done = false;
    while (not done) {
        done = true;
        for(int i = 0; i < other.size(); i++) {
            if (l[i] < r[i]) {
                done = false;
                mid[(l[i]+r[i])>>1].push_back(i);
            }
        }
        iota(p, p+n+10, 0);
        for(int i = 0; i < want.size(); i++) {
            auto [a, b, c] = want[i];
            // cerr << i << ' ' << a << ' ' << b << endl;
            p[find(a)] = find(b);
            for (auto x : mid[i]) {
                // cerr<< x << ' ' << i << ' ' << find(other[x].a) << ' ' << find(other[x].b) << endl;
                if (find(other[x].a) == find(other[x].b)) r[x] = i;
                else    l[x] = i+1;
                mid[i].clear();
            }
        }
    }

    // for(int i = 0; i < other.size(); i++) {
    //     cerr << want[l[i]].c << endl;
    // }

    for(int i = 0; i < other.size(); i++) {
        auto f = w.upper_bound(want[l[i]].c);
        if (f == w.end()) { printf("0"); return 0; }
        ans[i] = *f;
        w.erase(f);
    }

    printf("1\n");
    for(int i = 0; i < other.size(); i++) {
        printf("%d\n", ans[i]);
    }

    return 0;
}