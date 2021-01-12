#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int i = 1; i <= T; i++) {
        int x, y; string s;
        cout << "Case #" << i << ": ";
        cin >> x >> y >> s;
        int ans = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'N') y++;
            if (c == 'E') x++;
            if (c == 'S') y--;
            if (c == 'W') x--;
            if (abs(x)+abs(y) <= i+1) {
                ans = i+1;
                break;
            }
        }
        if (ans == -1) cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;
    }
    return 0;
}