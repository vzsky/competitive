#include<bits/stdc++.h>
using namespace std;

int b[200100], x[200100], a[200100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    x[1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[i] = x[i] + b[i];
        x[i+1] = max(x[i], a[i]);
        cout << a[i] << ' ';
    }
    return 0;
}