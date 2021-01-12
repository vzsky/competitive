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
typedef pair<lli,lli> pii;
typedef vector<int> vi;

pii a[500100];
lli fw[2][1000100];

void update(lli idx, lli idx2, lli val){
    for (; idx2 <= 1000000; idx2+=(idx2&-idx2)){
        fw[idx][idx2] += val;
    }
}

lli query (lli idx, lli idx2) {
    lli ans = 0;
    for(; idx2 > 0; idx2-=(idx2&-idx2)){
        ans+=fw[idx][idx2];
    }
    return ans;
}

int main(){
    long long ans = 0;
    lli n;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &a[i].x, &a[i].y);
    }
    //cerr << "1";
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        update(1, a[i].y+1, 1);
    }
   // cerr << "2";
    for(int i = 0; i < n; i++){
        update(1, a[i].y+1, -1);
        ans += ((n-i-1)-query(1, a[i].second))*query(0, a[i].second);
        update(0, a[i].y, 1);
    }
    printf("%lld", ans);
    return 0;
}