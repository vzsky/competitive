#include<bits/stdc++.h>
using namespace std;

int mic[400][400];

int main(){
    int q;
    scanf("%d", &q);
    
    mic[1][1] = 1;
    mic[2][1] = 2;
    mic[2][2] = 1;
    for(int i = 1; i <= 350; i++){
        for(int j = 1; j <= 350; j++){ // j <= i
            if (j == i) mic[i][j] = 1;
            else {
                mic[i][j] = mic[j][i] = mic[j][i-j] + 1;
            }
            
        }
    }
    while(q--){
        int a, b;
        scanf("%d %d", &a, &b);
        if (b > a) swap(a,b);
        printf("%d", mic[a][b]);
    }
return 0;
}