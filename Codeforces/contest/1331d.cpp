#include<bits/stdc++.h>
using namespace std;

long long res = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        res += s[i]*(pow(16, 7-i-1));
    }
    cout << (res&1);
    return 0;
}