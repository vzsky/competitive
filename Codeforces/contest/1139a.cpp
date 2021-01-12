#include<bits/stdc++.h>
using namespace std;

long long int ans=0;

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        char a;
        scanf(" %c", &a);
        int b = a-'0';
        if (b%2 == 0) {
            ans+=i;
        }

    }
    cout << ans;
    
    return 0;
}