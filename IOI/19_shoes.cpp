#include<bits/stdc++.h>
using namespace std;

bool le (int a, int b) {
    if (abs(a) == abs(b)) return a < b;
    return abs(a) < abs(b);
}

int n;
long long inv (vector<int> &b, int l, int r) {
    if (r == l) return 0;
    int mid = (l + r)/2;
    long long now = inv(b, l, mid) + inv(b, mid+1, r);
    int i = l, j = mid+1;
    vector<int> c;
    // for (int i = l; i <= mid; i++) cerr << b[i] << ' '; cerr << " : ";
    // for (int i = mid+1; i <= r; i++) cerr << b[i] << ' '; cerr << endl;
    while (i <= mid and j <= r) {
        if (le(b[i], b[j])) c.push_back(b[i++]);
        else c.push_back(b[j++]), now += mid-i+1;
    }
    while(i <= mid) c.push_back(b[i++]);
    while(j <= r) c.push_back(b[j++]);
    for (int i = l, j = 0; i <= r; i++, j++) b[i] = c[j];
    // for (int i = 0; i < 2*n; i++) cerr << b[i] << ' '; cerr << endl;
    return now;
}

long long count_swaps (vector<int> a){
    n = a.size() / 2;
    vector<int> b;
    map<int, queue<int>> q;
    int cnt = 1;
    for (auto x : a) {
        if (!q[x].empty()) { b.push_back(q[x].front()); q[x].pop(); continue; }
        b.push_back(cnt * (x<0?-1:1));
        q[-x].push(cnt * (x<0?1:-1));
        cnt++;
    }
    // for (auto x : b) cerr << x << ' '; cerr << endl;
    return inv (b, 0, b.size()-1);
}

// int main () {
//     printf("%lld", count_swaps({3, -3, 2, 1, -1, -1, -2, -3, 1, 3}));
//     return 0;
// }