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

char a[100];

pii ex (int aa, pii st){
    if (st.x + 1 == st.y) {
        if (aa == 1) return {st.x, st.y};
        return {-1, -1};
    }
    if (a[st.x] == '(' && a[st.y-1] == ')') {
        int pa = 0;
        int l = st.x;
        for(int i = st.x; i < st.y-1; i++){
            if (a[i] == '(' ) pa++;
            if (a[i] == ')' ) pa--;
            if (pa == 0) l = i;
        }
        // cerr << "PARENTHESIS ";
        if (aa == 1 && l == st.x) return {st.x+1, st.y-1};
        if (aa > 1 && l == st.x) return {-1, -1};
    }
    vi plus, mul, pow;
    int check = 0;
    plus.pb(st.x-1);
    mul.pb(st.x-1);
    pow.pb(st.x-1);
    for(int i = st.x; i < st.y; i++){
        if (a[i] == '(') {
            check++;
        }
        if (a[i] == ')') {
            check--;
        }
        if (check) continue;
        if (a[i] == '+'){
            plus.pb(i);
        }
        if (a[i] == '*'){
            mul.pb(i);
        }
        if (a[i] == '^'){
            pow.pb(i);
        }
    }
    plus.pb(st.y);
    mul.pb(st.y);
    pow.pb(st.y);
    if (plus.size() > 2) {
        // cerr << "PLUS ";
        if (aa+1 > plus.size()) return {-1,-1};
        return {plus[aa-1]+1, plus[aa]};
    }
    else if (mul.size() > 2) {
        // cerr << "MUL ";
        if (aa+1 > mul.size()) return {-1,-1};
        return {mul[aa-1]+1, mul[aa]};
    }
    else if (pow.size() > 2) {
        // cerr << "POW ";
        if (aa+1 > pow.size()) return {-1,-1};
        return {pow[aa-1]+1, pow[aa]};
    }
    return {-2, -2};
}

int main(){
    cin >> a;
    int len = strlen(a);
    int n;
    scanf("%d", &n);
    while(n--){
        int cnt = 0;
        queue<int> q;
        stack<int> s;
        int c = 1;
        while(c != 0) {
            scanf("%d", &c);
            if (c == 0) break;
            q.push(c);
            s.push(c);
        }
        pii st = {0, len};


        while(!s.empty()){
            cnt++;
            printf("op(%d,",s.top());
            s.pop();
        }
        printf("p");
        while(cnt--) printf(")");
        printf("=");

        while(!q.empty()){
            int t = q.front(); q.pop();
            st = ex(t, st);
            if (st.x == -1 && st.y == -1) goto nul;
            assert(st.x != -2 || st.y != -2);
        }

        for(int i = st.x; i < st.y; i++){
            printf("%c", a[i]);
        }
        printf("\n");
        continue;
        nul : printf("null\n");
    }
    return 0;
}