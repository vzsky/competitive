#include<bits/stdc++.h>
using namespace std;
int k, a, b;
int arr[100000];

void play(int w, int l){
    int n = w+l-a-b;
    if (w == k || l == k){
        for(int i = 0; i < n; i++){
            printf(arr[i]?"W ":"L ");
        }
        printf("\n");
        return;
    }
    arr[n] = 1;
    play(w+1,l);
    arr[n] = 0;
    play(w,l+1);
}

int main(){
    scanf("%d %d %d", &k, &a, &b);
    play(a,b);
return 0;
}