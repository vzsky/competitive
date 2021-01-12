#include<bits/stdc++.h>
using namespace std;

char s[110];
char t[110];
char ss[110];
char tt[110];
map<char, vector<int>> m;
vector<int> lis[110];
int cnt;

int main(){
    int q;
    cin >> q;
    while(q--){
        int l; cin >> l;
        cin >> s;
        cin >> t;

        strcpy(ss, s);
        strcpy(tt, t);
        sort(ss, ss+l);
        sort(tt, tt+l);
        int mx;
        for(int i = 0; i < l; i++){
            if (ss[i] != tt[i]) { printf("-1\n"); goto nq; }
        }
        
        mx = 0;
        for(int j = 0; j < l; j++){
            for(int i = 0, c = 0; i < l; i++){
                if (j+c == l) break;
                if (t[j+c] == s[i]) c++;
                mx = max(mx, c);
            }
        }
        printf("%d\n", l-mx);
        nq : continue;
    }
    return 0;
}