#include<bits/stdc++.h>
using namespace std;

char FindMiddle (char x, char y, char z){
    char a[4];
    a[0] = x; a[1] = y; a[2] = z;
    sort(a, a+3);
    return a[1];
}

char locka[130], lockb[130], key[130];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    scanf(" %s %s %s", locka, lockb, key);

    for(int j = 0; j < m; j++){
        char x = key[j];
        for(int i = 0; i < n; i++){
            x = FindMiddle(locka[i], lockb[i], x);
        }
        printf("%c", x);
    }
    return 0;
}