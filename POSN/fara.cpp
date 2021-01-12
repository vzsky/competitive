#include<bits/stdc++.h>
using namespace std;

int s[1001000];
map<int,int> last, slast, front, sfront;
int ind = 0;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &s[i]);
        ind = max(ind,s[i]);
    }
    for(int i = 0; i < n; i++){
        last[s[i]] = i;
    }
    for(int i = n-1; i >= 0; i--){
        front[s[i]] = i;
    }
    sort(s, s+n);
    for(int i = 0; i < n; i++){
        slast[s[i]] = i;
    }
    for(int i = n-1; i >= 0; i--){
        sfront[s[i]] = i;
    }
    for(int i = 1; i <= ind; i++){

        printf("%d %d\n", i, max(slast[i]-front[i], last[i]-sfront[i]));
    }
return 0;
}