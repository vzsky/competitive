#include<bits/stdc++.h>
using namespace std;

char s[1010];
int num[1010], close[1010], tab[2000][2000];

int main(){

    freopen("bbreeds.in", "r", stdin);
    freopen("bbreeds.out", "w", stdout);

    num[1] = 1;
    scanf(" %s", s+1);
    // assert that this is balanced.
    int n = strlen(s+1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') num[i+1] = num[i]+1, close[i+1] = close[i];
        else num[i+1] = num[i]-1, close[i+1] = close[i]+1;
    }
    assert(close[1] == 0 and num[1] == 1);
    tab[1][1] = 1;
    for (int i = 2; i <= n+1; i++) {
        for (int j = close[i]+1; j <= close[i]+num[i]; j++) {
            tab[i][j] = tab[i-1][j-1] + tab[i-1][j];
            tab[i][j] %= 2012;
        }
    }
    printf("%d", tab[n+1][close[n+1] + num[n+1]]);
    return 0;
}