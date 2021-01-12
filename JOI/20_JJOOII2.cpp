#include<bits/stdc++.h>
using namespace std;

string s;
vector<int> J, O, I;
int main(){
    int n, k; scanf("%d %d", &n, &k); cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'J') J.push_back(i);
        if (s[i] == 'O') O.push_back(i);
        if (s[i] == 'I') I.push_back(i);
    }
    int ans = 1e9;
    for (int i = k-1; i < J.size(); i++)  {
        int firstj = J[i-k+1], lastj = J[i];
        int lasto = upper_bound(O.begin(), O.end(), lastj)-O.begin() + k-1;
        if (lasto >= O.size()) break;
        lasto = O[lasto];
        int lasti = upper_bound(I.begin(), I.end(), lasto)-I.begin() + k-1;
        if (lasti >= I.size()) break;
        lasti = I[lasti];
        ans = min(ans, lasti-firstj-3*k+1);
    }
    printf("%d", ans==1e9?-1:ans);
    return 0;
}