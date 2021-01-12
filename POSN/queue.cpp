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

int a[100100];
int b[100100];

lli inv (int l ,int r){
    if (l == r) return 0;
    int mid = (l+r)>>1;
    lli ans = inv(l, mid) + inv(mid+1, r);
    int i = l, j = mid+1;
    int cnt = l;
    while(i <= mid && j <= r){
        if (a[i] < a[j])
            b[cnt++] = a[i++];
        else {
            b[cnt++] = a[j++];
            ans+= (mid-i+1);
        }
    }
    while(i <= mid){
        b[cnt++] = a[i++];
    }
    while(j <= r){
        b[cnt++] = a[j++];
    }

    for(int i = l; i <= r; i++){
        a[i] = b[i];
    }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i++){
            if (a[i] - i > 2) {printf("CHEAT"); goto label; }
        }
        printf("%lld", inv(1, n));

        label : printf("\n");
    }
    return 0;
}