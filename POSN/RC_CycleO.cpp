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

int s[100100], cou[100100];
map<int,int> m;

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        m.clear();
        memset(cou, 0, sizeof cou);
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &s[i]);
        }
        sort(s, s+n);
        int cnt = 1;
        for(int i = 0; i < n; i++){
            // cerr << s[i] << s[i-1] << endl;
            if (i != 0 && s[i] - s[i-1] > 1) goto no;
            if (m[s[i]] == 0) m[s[i]] = cnt++;
        }
        for(int i = 0; i < n; i++){
            cou[m[s[i]]]++;
        }
        for(int i = 1; i < cnt; i++){
            // cerr << m[i] << ' ' << m[i]-1 << endl;
            // cerr << cou[m[i]] << ' ' << cou[m[i]-1] << endl;
            cou[i] -= cou[i-1];
            // cerr <<  cou[m[i]] << endl;
            if (cou[i] < 0) goto no;
        }
        if (cou[cnt-1] != 0) goto no;
        
        printf("YES\n"); continue;
        no : printf("NO\n"); continue;
    }
    return 0;
}