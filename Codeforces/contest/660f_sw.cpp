#include<bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> line;
#define m first
#define c second

long long a[200100], sum[200100], qs[200100];

bool bad(line &a, line &b, line c) { return (a.c-c.c)*(b.m-a.m) > (a.c-b.c)*(c.m-a.m); }
long long at(line a, long long x) { return a.m * x + a.c; }
int back = 0;

line l[200100];

void add (long long m, long long c) {
    if (back >= 2 and bad(l[back-2], l[back-1], {m, c})) back--;
    l[back++] = {m, c};
}
long long query (long long x, int L = 0, int R = back-1) {
    if (L+1 ==  R) return max(at(l[L], x), at(l[R], x));
    if (L == R) return at(l[L], x);
    int mid = (L+R)/2;
    if (at(l[mid], x) < at(l[mid-1], x)) return query(x, L, mid-1);
    if (at(l[mid], x) < at(l[mid+1], x)) return query(x, mid+1, R);
    return at(l[mid], x);
}

int main(){
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), qs[i] = a[i] + qs[i-1], sum[i] = a[i] * i + sum[i-1];
    long long ans = 0;

    add(0, 0);
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum[i]+query(qs[i]));
        add(-i, -sum[i]+i*qs[i]);
    }

    printf("%lld", ans);
    return 0;
}