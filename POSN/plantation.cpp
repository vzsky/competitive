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
typedef pair<lli,lli> pii;
typedef vector<int> vi;

#define INF 2e9

pii points[100100];

bool cmpbyx (pii A, pii B){
    return A.x < B.x;
}
bool cmpbyy (pii A, pii B){
    return A.y < B.y;
}
double dis (pii A, pii B){
    return pow((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y), 0.5 );
}

double closest(pii temp[], int n){
    double dl, dr, d;
    int mid = n/2;

    if (n <= 3){
        d = INF;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                d = min(d, dis(temp[i], temp[j]));
            }
        }
        return d;
    }

    dl = closest(temp, mid);
    dr = closest(temp+mid, n-mid);
    d = min(dl, dr);

    pii strip[n+3]; auto mp = temp[mid];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (abs(temp[i].x - mp.x) <= d) strip[cnt++] = temp[i];
    }
    sort(strip, strip+cnt, cmpbyy);
    double old = d;
    for(int i = 0; i < cnt; i++){
        for(int j = i+1; j < cnt && abs(strip[i].y - strip[j].y) <= old; j++){
            d = min(d, dis(strip[i], strip[j]));
        }
    }

    return d;
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        double r, d;
        scanf("%d %lf %lf", &n, &r, &d);
        for(int i = 0; i < n; i++){
            int a, b;
            scanf("%d %d", &points[i].x, &points[i].y);
        }
        sort(points, points+n, cmpbyx);
        int dist = closest(points, n);
        printf(dist>=2*r+d ? "Y\n":"N\n");
    }
    return 0;
}