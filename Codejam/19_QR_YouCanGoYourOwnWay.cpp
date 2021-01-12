#include<bits/stdc++.h>
using namespace std;

char s[50100];

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        printf("Case #%d: ", k);
        int n;
        cin >> n;
        cin >> s;
        int l = 2*(n-1);
        
        for(int i = 0; i < l; i++){
            printf("%c", s[i]=='E'?'S':'E');
        }        

        printf("\n");
        memset(s, 0, sizeof(s));
    }
    return 0;
}