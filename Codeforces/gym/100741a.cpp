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

lli fw[11][15000];
lli arr[15000];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &arr[i]);

        for(int j = i; j <= n; j+=(j&-j)){
            fw[arr[i]%m][j] += arr[i];
        }
    }

    int q;
    scanf("%d", &q);
    while(q--){
        int ans = 0;
        char opr; int a, b;
        scanf(" %c %d %d", &opr, &a, &b);
        if (opr=='+') {

            for(int j = a; j <= n; j+=(j&-j)){
                fw[arr[a]%m][j] -= arr[a];
            }
            arr[a]+=b;
            for(int j = a; j <= n; j+=(j&-j)){
                fw[arr[a]%m][j] += arr[a];
            }
            printf("%lld\n", arr[a]);

        }
        if (opr=='-') {

            if (arr[a] < b) {
                printf("%lld\n", arr[a]);
                continue;
            }

            for(int j = a; j <= n; j+=(j&-j)){
                fw[arr[a]%m][j] -= arr[a];
            }
            arr[a]-=b;
            for(int j = a; j <= n; j+=(j&-j)){
                fw[arr[a]%m][j] += arr[a];
            }
            printf("%lld\n", arr[a]);
            
        }
        if (opr=='s') {

            int mod;
            scanf("%d", &mod);
            lli ans = 0;
            
            for(int j = b; j > 0; j-=(j&-j)){
                ans += fw[mod][j];
            }
            for(int j = a-1; j > 0; j-=(j&-j)){
                ans -= fw[mod][j];
            }
            printf("%lld\n", ans);

        }
    }
    return 0;
}