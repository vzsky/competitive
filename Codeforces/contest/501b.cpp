#include<bits/stdc++.h>
using namespace std;

map <string, string> m;
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        string o, n;
        cin >> o >> n;
        m[o] = n;
    }
    for(auto x : m){
        while (m.count(m[x.first])){
            auto f = x.first, s = x.second;
            //cout << "dict" << f << ' ' << s << endl;
            m[x.first] = x.second = m[x.second];
            m.erase(s);
            //cout << x.first << ' ' << m[x.first] << ' ' << x.second << endl;
            n--;
        }
    }
    printf("%d\n", n);
    for(auto x : m){
        cout << x.first << ' ' << x.second << endl;
    }
    return 0;
}