#include<bits/stdc++.h>
using namespace std;

map <string, int> m;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if (m.count(s)){
            cout << s << m[s] << endl;
            m[s]++;
        }
        else {
            cout << "OK\n";
            m[s]++;
        }
    }
    return 0;
}