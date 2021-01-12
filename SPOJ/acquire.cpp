#include<bits/stdc++.h>
using namespace std;
#define w first
#define h second
#define m first
#define c second
typedef pair<long long,long long> line;

/*
min envelope
slope decrease monotonic
query increase monotonic
*/

pair<long long,long long> a[50100];
vector<pair<long long,long long>> r;
long long dp[50100];
line l[50100];
int front = 0, back = 0;

bool bad (line a, line b, line c) { return (a.c-c.c)*(b.m-a.m) < (a.c-b.c)*(c.m-a.m); }

void add (long long m, long long k) {
    while (back >= 2 and bad(l[back-2], l[back-1], {m, k})) back--;
    l[back++] = {m, k};
    // cerr << "line now " << endl;
    // for (int i = front; i <= back; i++) cerr << l[i].m << ' ' << l[i].c << endl;
    // cerr << endl;
}

long long query (int x) {
    if (front >= back) front = back-1;
    while (front < back-1 and l[front].m*x+l[front].c > l[front+1].m*x+l[front+1].c) front++;
    return l[front].m * x + l[front].c;
}
// vary by min or max env

int main(){
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld %lld", &a[i].w, &a[i].h);
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        while(!r.empty() and r.back().h <= a[i].h) r.pop_back();
        r.push_back(a[i]);
    }

    cerr << r.size() << endl;
    // cerr << endl; 
    // for (auto i : r) cerr << i.w << ' ' << i.h << endl;
    // cerr << endl;

    add(r[0].h, 0);
    for (int i = 0; i < r.size(); i++) {
        dp[i] = query(r[i].w);
        // cerr << "query at " << r[i].w << " : " << dp[i] << endl;
        if (i < r.size()-1) add(r[i+1].h, dp[i]);
    }
    printf("%lld\n", dp[r.size()-1]);
    return 0;
}