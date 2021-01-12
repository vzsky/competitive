#include<bits/stdc++.h>
using namespace std;

vector<int> find_subset(int l, int u, vector<int> w) {
    int n = w.size();
    vector<pair<int,int>> s(n);
    for (int i = 0; i < n; i++) s[i] = {w[i], i};
    sort(s.begin(), s.end());
    int a = 0, b = -1;
    long long sum = 0;
    deque<int> ans;
    while (1) {
        // cerr << a << ' ' << b << ' ' << sum << endl;
        if (a < b and sum > u) sum -= s[a++].first, ans.pop_front();
        else if (b < (n-1) and sum < l) sum += s[++b].first, ans.push_back(s[b].second);
        else if (l <= sum and sum <= u) return (vector<int>){ans.begin(), ans.end()};
        else break;
    }
    return vector<int>(0);
}

int main(){
    int n, l, u;
    scanf("%d %d %d", &n, &l, &u);
    vector<int> w(n);
    for (int i = 0; i < n; i++) scanf("%d", &w[i]);
    vector<int> ans = find_subset(l, u, w);
    for (auto x : ans) cout << x << ' ';
    return 0;
}