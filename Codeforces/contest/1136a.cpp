#include<bits/stdc++.h>
using namespace std;

int start[110];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int t;
        scanf("%d %d",&start[i], &t);
    }
    int k;
    scanf("%d", &k);
    int low = upper_bound(start, start+n, k) - start;
    printf("%d", n-low+1);
    return 0;
}