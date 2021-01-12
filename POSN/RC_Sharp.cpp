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

char s[510];
char sharp[510][30];
stack <char> st;

int main(){
    int n, m, k, a;
    scanf("%d %d %d %d", &n, &m, &k, &a);
    a--;
    cin >> s;
    n = strlen(s);
    for(int i = 0; i < m; i++){
        cin >> sharp[i];
        sort(sharp[i], sharp[i]+k);
    }
    int cnt = m-1;
    while(cnt >= 0){
        //cerr << sharp[cnt][a%k];
        st.push(sharp[cnt--][a%k]);
        a/=k;
    }
    //cerr << a << endl;
    for(int i = 0; i < n; i++){
        if (s[i] == '#') {printf("%c",st.top()); st.pop();}
        else printf("%c", s[i]);
    }

    return 0;
}