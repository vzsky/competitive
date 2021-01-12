#include<bits/stdc++.h>
using namespace std;

char s[110];
int twos[110];
int first = 1e5;

int main(){
    int t;
    scanf("%d", &t);
    for(int k = 1; k <= t; k++){
        printf("Case #%d: ", k);
        cin >> s;
        int l = strlen(s);
        for(int i = 0; i < l; i++){
            if (s[i] == '4') { 
                twos[i] = 2;
                cout << '2';
                first = min(first, i);
            }
            else {
                cout << s[i];
            }
        }
        printf(" ");
        for(int i = first; i < l; i++){
            printf("%d", twos[i]);
        }
        printf("\n");
        memset(s, 0, sizeof(s));
        memset(twos, 0, sizeof(twos));
        first = 1e5;
    }
    return 0;
}