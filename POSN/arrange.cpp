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

set <string> s;
char str[50];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %s", str);
        s.insert(str);
        auto it = s.find(str);
        if (it == s.begin()) printf("N/A");
        else { printf("%s", (--it)->c_str()); it++; }
        printf(" ");
        if (++it == s.end()) { printf("N/A"); it--; }
        else printf("%s", it->c_str());
        printf("\n");
    }

    
    return 0;
}