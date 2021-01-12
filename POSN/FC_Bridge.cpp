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

long long inv(int l, int r){
    if (l == r) return 0;
    int mid = (l + r)/2;
    long long cnt = inv(l, mid) + inv(mid+1, r);

    int i = l;
    int j = mid+1;
    int ind = l;
    while(i <= mid && j <= r){
        if (a[i] < a[j]){
            b[ind++] = a[i++];
        }
        else {
            b[ind++] = a[j++];
            cnt += mid-i+1;
        }
    } 
    while(i <= mid){
        b[ind++] = a[i++];
    } 
    while(j <= r){
        b[ind++] = a[j++];
    } 

    for(int i = l; i <= r; i++){
        a[i] = b[i];
    }
    
    return cnt;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int inp;
            scanf("%d", &inp);
            a[i] = inp;
            //a[inp] = i;
        }
        cout << inv(0, n-1) << endl;
        //logarr(a, a+n-1);
    }
    return 0;
}