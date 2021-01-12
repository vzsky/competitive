#include<bits/stdc++.h>
using namespace std;
long long int n, k, a, b;
map <long long int,int> m;

int main(){
    cin >> n >> k;
    for(a = 1; a <= k; a++){
        b = n%a;
        if (m.count(b)){
            if (m[b] == 1){
                printf("No");
                return 0;
            }
        }
        m[b] = 1;
    }
    printf("Yes");
    return 0;
}