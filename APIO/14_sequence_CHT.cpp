#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100100];
ll s[100100], dp[2][100100];
int mxk[200][100100];

// dp[i][j] = maximizing dp[i^1][k] + (s[j]-s[k]) * (s[k])
//          = maxing dp[i^1][k] + s[j]s[k] - s[k]s[k] in the form mj+c

struct line { ll m, c; int k; };
bool bad (line &a, line &b, line c) { return (a.c-c.c)*(b.m-a.m) <= (a.c-b.c)*(c.m-a.m); }
line l[1000100];
int front = 0, back = 0;
void add (ll m, ll c, int k) {
    while (back > 2 and bad(l[back-2], l[back-1], {m, c})) back--;
    l[back++] = {m, c, k};
}
pair<ll,int> query (ll &x) {
    if (front >= back) front = back-1;
    while (front < back-1 and l[front].m*x+l[front].c <= l[front+1].m*x+l[front+1].c) front++;
    return {l[front].m * x + l[front].c, l[front].k};
}

int main(){
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), s[i] = s[i-1]+a[i];
    for (int i = 1; i <= k; i++) {
        front = back = 0;
        memset(l, 0, sizeof l);
        dp[i%2][1] = 0;
        add(s[1], dp[(i+1)%2][1] - s[1]*s[1], 1);
        for (int j = 2; j <= n; j++) {
            tie(dp[i%2][j], mxk[i][j]) = query(s[j]);
            add(s[j], dp[(i+1)%2][j] - s[j]*s[j], j); 
        }
    }
    printf("%lld\n", dp[k%2][n]);
    for (int x = n, i = k; i > 0; i--) printf("%d ", x = mxk[i][x]);
    return 0;
}
// 7 3 4 1 3 4 0 2 3