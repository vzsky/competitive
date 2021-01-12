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

struct A {
    int l, r, n;
    bool operator < (const A & o) const {
        return r < o.r;
    }
};
vector <A> block [400];
int ans[100100], cnt[100100], a[100100];
int rt;

int main(){
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    int rt = sqrt(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= q; i++){
        int l, r;
        scanf("%d %d", &l, &r);
        l--; r--;
        block[l/rt].pb({l, r, i});
    }
    for(int i = 0; i < rt; i++){
        if (block[i].size() == 0) continue;

        // first case
        int l, r, count=0;
        sort(block[i].begin(), block[i].end());
        for(int j = block[i][0].l; j <= block[i][0].r; j++){
            cnt[a[j]]++;
            if (cnt[a[j]] == k) count++;
        }
        l = block[i][0].l; r = block[i][0].r;
        ans[block[i][0].n] = count;

        for(int j = 1; j < block[i].size(); j++) {
            while(l < block[i][j].l) {
                cnt[a[l]]--;
                if (cnt[a[l]] == k-1) count--;
                l++;
            }
            while(l > block[i][j].l) {
                l--;
                cnt[a[l]]++;
                if (cnt[a[l]] == k) count++;
            }
            while(r < block[i][j].r) {
                r++;
                cnt[a[r]]++;
                if (cnt[a[r]] == k) count++;
            }
            ans[block[i][j].n] = count;
        }
        memset(cnt, 0, sizeof cnt);
    }
    for(int i = 1; i <= q; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}