#include<bits/stdc++.h>
using namespace std;

pair<int,int> p[200100];

const int mod = 998244353;

bool index ( pair<int,int> a,  pair<int,int> b) {
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p+1, p+n+1, greater<>());
    sort(p+1, p+k+1, []( pair<int,int> a,  pair<int,int> b) {return a.second < b.second;});
    
    long long ans = 1;
    long long sum = p[1].first;
    for (int i = 2; i <= k; i++) {
        ans *= (p[i].second - p[i-1].second);
        ans %= mod;
        sum += p[i].first;
    }
    cout << sum << ' ' << ans;
    return 0;
}