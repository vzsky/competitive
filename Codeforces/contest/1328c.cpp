#include<bits/stdc++.h>
using namespace std;

int a[50010];
int b[50010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string s;
        int n; cin >> n;
        cin >> s;
        b[0] = a[0] = 1;
        bool flag = false;
        for (int i = 1; i < n; i++) {
            // a > b if flag else = 
            if (s[i] == '2') {
                if (!flag) {a[i] = 1; b[i] = 1;}
                if (flag) {a[i] = 0; b[i] = 2;}
            }
            if (s[i] == '1') {
                if (!flag) {
                    flag = true;
                    a[i] = 1; b[i] = 0;
                }
                else if (flag) {
                    a[i] = 0; b[i] = 1;
                }
            }
            if (s[i] == '0') {
                a[i] = b[i] = 0;
            }
        }
        for (int i = 0; i < n; i++) cout << a[i]; cout << endl;
        for (int i = 0; i < n; i++) cout << b[i]; cout << endl;
        
    }
    return 0;
}