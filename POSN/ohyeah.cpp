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

lli v[200200];
stack <int> s;

int main(){
    s.push(0);
    int n;
    scanf("%d", &n);

    lli val = 0, amn = 1;

    for(int i = 0; i < n; i++){
        int opr;
        scanf("%d", &opr);
        int a, b;
        if (opr == 1){
            scanf("%d %d", &a, &b);
            v[a] += b;
            val+=(a*b);
        }
        else if (opr == 2){
            scanf("%d", &a);
            s.push(a);
            val+=a;
            amn++;
        }
        else {
            //cerr << val <<endl;
            val-= s.top(); s.pop();
            //cerr << val <<endl;
            val-=v[amn];
            //cerr << val <<endl;
            if (v[amn] != 0 ){
                v[amn-1] += v[amn];
                v[amn] = 0;
            }
            amn--;
        }
        printf("%lld %lld\n", val, amn);
    }
    return 0;
}