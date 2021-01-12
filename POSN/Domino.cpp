#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10000];

void play(int state, int total){
    if (state == n) {
        for(int i = 0; i < total; i++){
            printf(arr[i]?"||\n":"--\n");
        }
        printf("E\n");
        return;
    }
    if (state > n) return;
    arr[total] = 0;
    play(state+1, total+1);
    arr[total] = 1;
    play(state+2, total+1);
}

int main(){
    scanf("%d", &n);
    play(0,0);
return 0;
}