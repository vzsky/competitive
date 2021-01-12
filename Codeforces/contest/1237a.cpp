#include<bits/stdc++.h>
using namespace std;

int a;
int main(){
    int n;
    scanf("%d", &n);
    int bit = 0;
    int mi, pl;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if (a&1) {
            // cerr << bit << endl;
            if (a < 0) {
                printf("%d\n", (a-bit)/2);
            }
            else {
                printf("%d\n", (a+(bit^1))/2);
            }
            bit ^= 1;
        }
        else {
            printf("%d\n", a/2);
        }
    }
    return 0;
}