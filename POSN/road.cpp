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

int a[110][10010];

priority_queue<pii> heap;

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int input;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &input);
            a[i][j]+=input;
        }

        if (i == n-1) {
            for(int j = 0; j < n; j++) heap.push({a[i][j], j});
            printf("%d\n", heap.top().x);
            break;
        }

        for(int j = 0; j < m; j++){
            heap.push({a[i][j], j});
            if (j == m-1){
                for(int x = m-k; x < m; x++){
                    while (heap.top().y < x-k) heap.pop();
                    a[i+1][x] = heap.top().x;
                }
            }
            else if (j > k && j < m-1) {
                while (heap.top().y < j-k) heap.pop();
                a[i+1][j-k] = heap.top().x;
            }
            else if (j == k) {
                for(int x = 0; x <= k; x++){
                    a[i+1][x] = heap.top().x;
                }
            }
        }
        while(!heap.empty()) heap.pop();
    }

    logmat(a, n-1, m-1);

    
    return 0;
}