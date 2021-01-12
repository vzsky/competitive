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

int main(){

    inp(n, int);

    int xpt = (n-11)>>1;

    int eight = 0;
    int other = 0;

    For(i, 0, n-1){
        int in;
        char c;
        scanf(" %c", &c);
        in = c-'0';

       // cerr << in << endl;

        if (in==8) eight++;
        else other++;

      //  cerr << other;

        if (other > xpt) {printf("NO"); break;}
        if (eight > xpt) {printf("YES"); break;}
    }
    return 0;
}