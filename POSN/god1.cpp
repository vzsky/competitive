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

int a[100100], b[100100];
lli fw[100100];
unordered_map <int,int> mp;


int mx = 1e9;

int main(){
    int n; lli m;
    scanf("%d %lld", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b+n);
    for(int i = 2; i < n+2; i++){
        mp[b[i-2]] = i;
    }


   if (m == 0) {printf("0"); return 0;}

    int l = 1; int r = 1e9;
    while(l < r) {
        int mid = (l+r)>>1;
        
        memset(fw, 0, sizeof(fw));

        lli inv = 0;

        for(int i = 0; i < n; i++){
            if (mid >= a[i]){ 
                int b = mp[a[i]];
                //cerr << a[i] << ' ' << b << endl;
                for(int j = b; j > 0; j-=(j&-j)){
                    inv+=fw[j];
                }
                for(int j = 1; j <= 100000; j+=(j&-j)){
                    fw[j]++;
                }
                for(int j = b+1; j <= 100000; j+=(j&-j)){
                    fw[j]--;
                }
            }
        }
        //cerr << inv;
        
        if (inv >= m) r = mid;
        else l = mid+1;
    }
    printf("%d", l);
    return 0;
}