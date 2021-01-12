#include<bits/stdc++.h>
using namespace std;

map<char,int> first, cnt;
vector<pair<int,char>> a, f;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int ttt = 1; ttt <= T; ttt++) {
        first.clear();
        cnt.clear();
        a.clear();
        f.clear();
        char zero = '?';
        cout << "Case #" << ttt << ": ";
        int U;
        cin >> U;
        for (int i = 0 ; i < 10000; i++) {
            string Q, R;
            cin >> Q >> R;
            first[R[0]]++;
            for (int j = 0; j < R.size(); j++) {
                cnt[R[j]]++;
            }
            
        }
        for (auto x : cnt) {
            a.push_back({x.second, x.first});
        }
        for (auto x : first) {
            f.push_back({x.second, x.first});
        }
        sort(f.begin(), f.end(), greater<pair<int,int>>());
        sort(a.begin(), a.end(), greater<pair<int,int>>());
        for (auto x : a) {
            if (first[x.second] == 0) {
                if (zero != '?') while(1);
                zero = x.second;
            }
        }
        if (zero == '?') while(1);
        cout << zero;
        for (auto x : f){
            if (x.second != zero) {
                cout << x.second;
            }
        }
        // for (auto x : a){
        //     if (x.second != zero) {
        //         cout << x.second;
        //     }
        // }
        cout << endl;
    }
    return 0;
}