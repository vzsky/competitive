#include "grader.h"
#include <bits/stdc++.h>
using namespace std;

int besthub(int n, int L, int x[], long long b){ 
    long long s[100100]; s[0] = x[0];
    for (int i = 1; i < n; i++) s[i] = 0;
    for (int i = 1; i < n; i++) s[i] = x[i]+s[i-1];
    int l = 0, r = 0, ans = 1;
    while (r < n) {
        int med = (l+r)/2;
        long long low = (long long)x[med]*(med-l) - (s[med-1]-s[l-1]);
        long long high = s[r]-s[med] - (long long)x[med]*(r-med);
        if (low + high <= b) ans = max(ans, r++-l+1);
        else l++;
    }
    return ans;
}

// int main () {
//     int n, l, b;
//     scanf("%d %d %d", &n, &l, &b);
//     int x[n];
//     for (int i = 0; i < n; i++) scanf("%d", &x[i]);
//     printf("%d", besthub(n, l, x, b));
// }