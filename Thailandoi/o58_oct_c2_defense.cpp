#include<bits/stdc++.h>
using namespace std;

int a[3010];
int mic[3010][3010];

int mn[3010];

int main(){
    int n, l;
    scanf("%d %d", &n, &l);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        for(int j = 0; j < n; j++){
            mic[i][j] = 1e9;
        }
    }

    for(int i = 0; i < l; i++){
        for(int j = 0; j < i; j++){
            mic[i][j] = a[i]+a[j];
            if (mic[i][mn[i]] > mic[i][j]) mn[i] = j;
        }
    }

    for(int i = l; i < n; i++){
        for(int j = i-l+1; j < i; j++){
            mic[i][j] = a[i] + mic[j][mn[j]];
            if (mic[i][mn[i]] > mic[i][j]) mn[i] = j;
        }
    }

    int ans = 2e9;
    for(int i = n-l; i < n; i++){
        for(int j = n-l; j < i; j++){
            ans = min(ans, mic[i][j]);
        }
    }
    printf("%d", ans);
    return 0;
}