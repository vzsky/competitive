#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> line; 
#define m first
#define c second

ll x[1000100], qs[1000100], dp[1000100];
ll a, b, c;

ll poly (ll x) { return a*x*x+b*x+c; }

bool bad (line &a, line &b, line c) { return (a.c-c.c)*(b.m-a.m) < (a.c-b.c)*(c.m-a.m); }

line l[1000100];
int front = 0, back = 0;
void add (ll m, ll c) {
    while (back >= 2 and bad(l[back-2], l[back-1], {m, c})) back--;
    l[back++] = {m, c};
}

ll query (ll x) {
    if (front >= back) front = back-1;
    while (front < back-1 and l[front].m*x+l[front].c < l[front+1].m*x+l[front+1].c) front++;
    return l[front].m * x + l[front].c;
}

int main(){
    int t; scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d %lld %lld %lld", &n, &a, &b, &c);
        for (int i = 1; i <= n; i++) scanf("%lld", &x[i]), qs[i] = qs[i-1]+x[i];
        
        front = back = 0;

        dp[1] = poly(x[1]);
        add(-2*a*qs[1], a*qs[1]*qs[1]-b*qs[1]+dp[1]);
        for (int i = 2; i <= n; i++) {
            dp[i] = max(query(qs[i]) + poly(qs[i]), poly(qs[i]));
            add(-2*a*qs[i], a*qs[i]*qs[i]-b*qs[i]+dp[i]);
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}