#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int lli;
typedef pair<int,int> pii;

int main(){
    int n;
    lli ans = 0;
    scanf("%d", &n);
    for(int i = 2; i < n; i++){
        ans += (i*(i+1));
    }
    cout << ans;
    return 0;
}