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
typedef vector<int> vi;

typedef pair<double,double> point;

int n;
double r, d;

point plant[100100];

bool byy (point a, point b) {
    return a.y < b.y;
}

double dist (point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double cp (point p[], int n){
    if (n <= 3) {
        double d = 2e9;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                d = min(d, dist(p[i], p[j]));
            }
        }
        return d;
    }
    int mid = n>>1;
    double d1 = cp(p, mid);
    double d2 = cp(p+mid, n-mid);
    double d = min(d1, d2);
    point str[n+5];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (abs(p[i].x - p[mid].x) < d) str[cnt++] = p[i];
    }
    //cerr << d;
    sort(str, str+cnt, byy);
    for(int i = 0; i < cnt ; i++){
        for(int j = i+1; j < cnt && abs(str[i].y - str[j].y) < d; j++){
            d = min(d, dist(str[i], str[j]));
        }
    }
    return d;
}

int main(){
    int w;
    scanf("%d", &w);
    while(w--){
        scanf("%d %lf %lf", &n, &r, &d);
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &plant[i].x, &plant[i].y);
        }
        sort(plant, plant+n);
        printf(cp(plant, n) >= 2*r+d? "Y\n": "N\n");
    }
    return 0;
}