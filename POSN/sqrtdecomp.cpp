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

int arr[100100];
int clus[400];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    int rt = pow(n, 0.5);
    while(q--){
        char opr; int a, b;
        scanf(" %c %d %d", &opr, &a, &b);
        a--;
        if (opr == 'U'){
            arr[a] = b;
            int cl = a/rt;
            int st = cl*rt;
            clus[cl] = -2e9;
            for(int i = st; i < min(n,st+rt); i++){
                clus[cl] = max(clus[cl], arr[i]);
            }
        }
        else {
            int ans = -2e9;
            b--;

            int i = a;
            ans = arr[i];
            
            for(int i = a; i <= b;){
                if (i%rt==0 && i+rt < b){
                    ans = max(ans, clus[i/rt]);
                    i+=rt;
                }
                else {
                    ans = max(ans, arr[i]);
                    i++;
                }
            }

            printf("%d\n", ans);
        }
    }
    return 0;
}