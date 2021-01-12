#include<bits/stdc++.h>
using namespace std;

set<string> s;

int main(){
    int n, m, rep=0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        s.insert(str);
    }
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        if(s.find(str) != s.end()){
            rep++;
        }
    }
    int start = 1;
    if (rep & 1) { //odd
        start = 2;
    }
    if ((start == 2 && m > 0) || (start == 1 && n > 0)){
        if (n > m) printf("YES");
        else if (n < m) printf("NO");
        else printf(start==1? "NO" : "YES");
    }
    else {
        printf(start==1? "NO" : "YES");
    }
    return 0;
}