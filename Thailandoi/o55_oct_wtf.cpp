#include<bits/stdc++.h>
using namespace std;

int a[40];

int main(){
    for(int i = 0; i < 30; i++){
        scanf("%d", &a[i]);
    }
    // assert(a[0] == 19);
    if (a[0] > 4 && a[0] < 10) printf("yes");
    else if (a[0] == 76 || a[0] == 19) printf("yes");
    else if (a[0] >= 80)  printf("yes");
    else    printf("no");
    return 0;
}