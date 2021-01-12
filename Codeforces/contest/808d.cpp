#include<bits/stdc++.h>
using namespace std;

long long a[100100], qs[100100];
pair<int,int> b[100100];
int n;

bool check (int l, int r, int v) {
    auto low = lower_bound(b+1, b+n+1, (pair<int,int>){v, l});
    auto upp = upper_bound(b+1, b+n+1, (pair<int,int>){v, r});
    return low != upp;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) { cin >> a[i]; qs[i] = qs[i-1] + a[i]; b[i] = {a[i], i};}
    long long goal = qs[n]/2;

    if (qs[n] & 1) {
        cout << "NO"; return 0;
    }

    sort (b+1, b+n+1);

    for (int i = 1; i <= n; i++) {
        long long left = goal - qs[i];
        if (abs(left) > 1e9) continue;
        if (left < 0) {
            if (check(1, i, -left)) {
                cout << "YES"; return 0;
            }
        }
        else if (check(i+1, n, left)) {
            cout << "YES"; return 0;
        }
    }
    cout << "NO";
    return 0;
}