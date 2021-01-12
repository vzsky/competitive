#include<bits/stdc++.h>
using namespace std;

int n, m;

void play(int state){
    if (m>=n) {

        if (m > n) return;
        printf("%d", state);
        exit(0);
    }
    m*=2;
    play(state+1);
    m/=2;
    m*=3;
    play(state+1);
    m/=3;
}

int main(){
    scanf("%d %d", &m, &n);
    play(0);
    printf("-1");
    return 0;
}