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

string a, b;

bool isprime (int n){
    int rn = pow(n, 0.5);
    for(int i = 2; i <= rn; i++){
        if (n%i==0) return false;
    }
    return true;
}
bool ispal (int n){
    a = "";
    while(n != 0){
        int dig = n%10;
        n/=10;
        a += (char) dig+'0';
    }
    b = a;
    reverse(a.begin(), a.end());
    if (a.compare(b) == 0) return true;
    return false;
}

int main(){
   inp(n, int);
   for(int i = n; i <= 1003001; i++){
       if (isprime(i)&&ispal(i)) {printf("%d", i); break;}
   }
   return 0;
}