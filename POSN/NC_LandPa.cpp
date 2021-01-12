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

int a[55][55];
int cnt[25010000];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }

    int ans = 0;

    for(int i = 1; i < n; i++){
        for(int j = 1; j < n; j++){
            
            for(int ii = 1; ii <= i; ii++){
                for(int jj = 1; jj <= j; jj++){
                    int sum = a[i][j]-a[ii-1][j]-a[i][jj-1]+a[ii-1][jj-1];
                    if (sum < 0) sum += 2500000;
                    cnt[sum]++;
                }
            }

            for(int ni = i+1; ni <= n; ni++){
                for(int nj = j+1; nj <= n; nj++){
                    int sum = a[ni][nj]-a[ni][j]-a[i][nj]+a[i][j];
                    if (sum < 0) sum += 2500000;
                    ans += cnt[sum];
                    //cerr << sum << ' ' << cnt[sum] << endl;
                }
            }

            for(int ii = 1; ii <= i; ii++){
                for(int jj = 1; jj <= j; jj++){
                    int sum = a[i][j]-a[ii-1][j]-a[i][jj-1]+a[ii-1][jj-1];
                    if (sum < 0) sum += 2500000;
                    cnt[sum] = 0;
                }
            }


            for(int ii = 1; ii <= i; ii++){
                for(int jj = j+1; jj <= n; jj++){
                    int sum = a[i][jj]-a[ii-1][jj]-a[i][j]+a[ii-1][j];
                    if (sum < 0) sum += 2500000;
                    cnt[sum]++;
                }
            }

             for(int ni = i+1; ni <= n; ni++){
                for(int nj = 1; nj <= j; nj++){
                    int sum = a[ni][j]-a[ni][nj-1]-a[i][j]+a[i][nj-1];
                    if (sum < 0) sum += 2500000;
                    ans+=cnt[sum];
                    //cerr << sum << ' ' << cnt[sum] << endl;
                }
            }

            for(int ii = 1; ii <= i; ii++){
                for(int jj = j+1; jj <= n; jj++){
                    int sum = a[i][jj]-a[ii-1][jj]-a[i][j]+a[ii-1][j];
                    if (sum < 0) sum += 2500000;
                    cnt[sum] = 0;
                }
            }

        }
    }
    printf("%d", ans);
    return 0;
}