#include<bits/stdc++.h>
using namespace std;

int m[110][110][110];

int mic(int a, int b, int c) {
    // cerr << a << ' ' << b << ' ' << c << endl;
    if (m[a][b][c]) return m[a][b][c];
    if (a >= 1 and b >= 2 and c >= 2) return m[a][b][c] = max(mic(a, b-1, c-2), mic(a-1, b-2, c))+3;
    if (a >= 1 and b >= 2) return mic(a-1, b-2, c)+3;
    if (b >= 1 and c >= 2) return mic(a, b-1, c-2)+3;
    return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b, c;
        scanf("%d %d %d",&a, &b, &c);
        memset(m, 0, sizeof m);
        // cerr << a << ' ' << b << ' ' << c << endl;
        printf("%d\n", mic(a, b, c));
    }
    return 0;
}