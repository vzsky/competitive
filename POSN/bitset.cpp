#include<bits/stdc++.h>
using namespace std;

char a[1010], b[1010];

int main(){
    scanf(" %s %s", a, b);
    int cnta = 0, cntb = 0;
    int len = max(strlen(a),strlen(b));

    for(int i = 0; i < len; i++){
        if (a[i]=='1') cnta++;
        if (b[i]=='1') cntb++;
    }
    if (cnta&1) cnta++;
    //cout << cnta << ' ' << cntb << endl;
    printf(cnta>=cntb? "YES":"NO");

return 0;
}