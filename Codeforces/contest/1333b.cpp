#include<bits/stdc++.h>
using namespace std;

int a[100100], b[100100];

pair<int,int> h;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        h = {0, 0};
        bool flag = true;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) goto next;
            if (a[i] < b[i] and h.first) goto next;
            if (a[i] > b[i] and h.second) goto next;
            flag = false;
            break;
            next : 
            if (a[i] == 1) h.first = 1;
            if (a[i] == -1) h.second = 1;
            continue;
        }
        cout << (flag?"YES":"NO") << '\n';
    }
    return 0;
}