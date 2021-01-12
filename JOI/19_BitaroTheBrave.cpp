#include<bits/stdc++.h>
using namespace std;


string tab[3010];
int O[3010][3010], I[3010][3010];
int main(){
    int h, w; scanf("%d %d", &h, &w);
    for (int i = 0; i < h; i++) cin >> tab[i];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (tab[i][j] == 'O') O[i+1][j+1] = 1;
            if (tab[i][j] == 'I') I[i+1][j+1] = 1;
            O[i+1][j+1] += O[i+1][j];
            I[i+1][j+1] += I[i][j+1];
        }
    }
    long long ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (tab[i-1][j-1] == 'J') {
                ans += (O[i][w]-O[i][j-1]) * (I[h][j]-I[i-1][j]);
            }
        }
    }
    printf("%lld", ans);
    return 0;
}