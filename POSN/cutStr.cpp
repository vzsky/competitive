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

char s[300100];
int a[30];
int b[30];
lli ans[30];

int main(){
    scanf(" %s", s);
    int n = strlen(s);
    for(int i = 0; i < n; i++){
        a[s[i]-'a'] = i+1;

        for(int j = 1; j <= 26; j++){
            b[j] = a[j-1];
        }
        sort(b+1, b+27);

        for(int j = 25; j >= 0; j--){
            ans[26-j] += b[j+1]-b[j];
        }
    }

    int cnt = 26;
    while(ans[cnt]==0) cnt--;

    //logarr(ans, ans+26);

    printf("%d\n", cnt);
    for(int i = 1; i <= cnt; i++) printf("%lld\n", ans[i]);

    return 0;
}