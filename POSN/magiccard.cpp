#include<bits/stdc++.h>
using namespace std;

int a[5010], b[5010];
long long dam[5010][5010];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for(int i = 1; i <= m; i++) scanf("%d", &b[i]);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //cout << dam[i-1][j-1]+abs(a[i]-b[j]) << ' ' << max(dam[i-1][j], dam[i][j-1]) << endl;
            dam[i][j] = max(dam[i-1][j-1]+abs(a[i]-b[j]), max(dam[i-1][j], dam[i][j-1]));
        }
    }
    printf("%lld", dam[n][m]);
return 0;
}