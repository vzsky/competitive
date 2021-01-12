#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int lli;
typedef pair<int,int> pii;

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int cnt1 = 0; int cnt2 = 0;
        char c[110];
        
        scanf(" %s", c);
        if (c[0] == '>' || c[n-1] == '<') {printf("0\n"); continue;}
        else {
            for(int j = 0; j < n; j++){
                if (c[j] == '>') break;
                cnt1++;
            }
            for(int j = n-1; j >= 0; j--){
                if (c[j] == '<') break;
                cnt2++;
            }
        }
        printf("%d\n", min(cnt1, cnt2));

    }
    return 0;
}