/*

Stiring number of the second kind

Ways of arranging n objects into k identical boxes ???

2 Subprocesses...
- 1 : find ways of arranging n-1 objects in k identical boxes then add the nth into any box.
- 2 : find ways of arranging n-1 objects in k-1 identical boxes then add the nth into the kth box.

Ways of arranging n objects into k identical boxes = 1 + 2

*/

int stir[1010][1010];

#include<bits/stdc++.h>
using namespace std;

int main(){

    stir[1][1] = 1;

    for(int i = 2; i <= 1000; i++){
        for(int j = 1; j <= i; j++){
            stir[i][j] = stir[i-1][j]*j+stir[i-1][j-1];
            stir[i][j]%=9871;
        }
    }

    int t;
    scanf("%d", &t);
    while(t--){
        int n, k;
        scanf("%d %d", &n, &k);
        printf("%d\n", stir[n][k]);
    }
    return 0;
}