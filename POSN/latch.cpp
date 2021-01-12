#include<bits/stdc++.h>
using namespace std;

#define x first
#define m second

long long down[1010][1010], a[1010][1010];

stack<pair<long long, int>> s;
long long sum;

int main(){
    long long n, m;
    scanf("%lld %lld", &n, &m);
    long long ans = 0;

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%lld", &a[i][j]);
            down[i][j] = a[i][j]==a[i-1][j]? down[i-1][j]+1:1;
        }
    }

    for (int i = 1; i <= n; i++) {
        while(!s.empty()) s.pop();
        sum = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i][j] != a[i][j-1]) {sum = 0; while(!s.empty()) s.pop();}
            int cnt = 0;
            while(!s.empty() and s.top().x >= down[i][j]) { sum -= (s.top().x-down[i][j])*s.top().m; cnt+=s.top().m; s.pop();}
            s.push({down[i][j], cnt+1});
            sum += down[i][j];
            ans += sum;
        }
        cerr << ans << endl;
    }

    printf("%lld", ans);
    return 0;
}