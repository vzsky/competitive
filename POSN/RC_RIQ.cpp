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

map<int,int> m;
int cnt =2;

int arr[1010], fw[1010];
int s[1010];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        s[i] = arr[i];
    }
    sort(s, s+n);
    for(int i = 0; i < n; i++){
        if (m[s[i]] == 0) m[s[i]] = cnt++;
    }
    //for(int i = 0; i < n; i++)
    while(q--){
        memset(fw, 0, sizeof fw);
        int l, r;
        scanf("%d %d", &l, &r); int inv=0;
        l--;r--;
        for(int i = l; i <= r; i++){
            int search = m[arr[i]];
            for(int j = search; j > 0; j-=(j&-j)){
                inv += fw[j];
            }
            for(int j = 1; j <= cnt; j+=(j&-j)){
                fw[j]++;
            }
            for(int j = search+1; j <= cnt; j+=(j&-j)){
                fw[j]--;
            }
            //cerr << inv << endl;
        }
        printf("%d\n", inv);
    }
    return 0;
}