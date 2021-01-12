#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

bool isnum (char a){
    return (a == '1' || a == '2' || a == '3' || a == '4' || a == '5' || a == '6' || a == '7' || a == '8' || a == '9' || a == '0' );
}

char s[1100];

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    while(n) {
        cin >> s;
        // cerr << s << ' ';
        int l = strlen(s);
        if (isupper(s[0])) {
            int ch = 0;
            for(int i = 0; i < l; i++){
                if (isnum(s[i])) ch = 1;
            }
            // cerr << ch;
            if (!ch) ans++;
        }
        // cerr << endl;
        if (s[l-1] == '.' || s[l-1] == '!' || s[l-1] == '?') goto next;
        continue;
        next : 
        printf("%d\n", ans);
        ans = 0;
        n--;
    }
    return 0;
}