#include<bits/stdc++.h>
using namespace std;

int arr[200100];
long long int ans = 0;

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int last = 2e9;
    for(int i = n-1; i >= 0; i--)
    {
        last = min(arr[i], last);
        if ( last < 0 ) last = 0;
        ans += last;
        //cout << last << ' ';
        last--;
    }
    cout << ans;
    
    return 0;
}