#include<bits/stdc++.h>
using namespace std;

int fw[1000000100];

int main(){
    int karn = 0;
    int n;
    scanf("%d", &n);
    while(n--){
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 1) {
            for(int i = 1; i <= 1000000000; i+=(i&-i)){
                fw[i]++;
            }
            for(int i = b; i <= 1000000000; i+=(i&-i)){
                fw[i]--;
            }
            karn++;
        }
        else {
            int ans = 0;
            for(int i = b; i > 0; i-=(i&-i)){
                ans += fw[i];
            }
            printf("%d\n", karn-ans);
        }
    }
    return 0;
}