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

#define inf 2e9
struct point {
    double x, y;
};
bool cmpx (point a, point b) {
    return a.x < b.x;
}
bool cmpy (point a, point b) {
    return a.y < b.y;
}
double dis (point a, point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point points[100100];

// double cp (int l, int n){ // amount of points

//     if (n <= 3) {
//         double d = inf;
//         for(int i = 0; i < n; i++){
//             for(int j = i+1; j < n; j++){
//                 d = min(d, dis(points[l+i], points[l+j]));
//             }
//         }
//         return d;
//     }

//     int mid = n>>1;
//     double d1 = cp(l ,mid);
//     double d2 = cp(l+mid, n-mid);
//     double d = min(d1, d2);
//     vector<point> strip;
//     int cnt = 0;
//     for(int i = 0; i < n; i++){
//         if (abs(points[l+mid].x-points[l+i].x) < d) strip.pb(points[l+i]);
//     }
//     sort(strip.begin(), strip.end(), cmpy);
//     for(int i = 0; i < strip.size(); i++){
//         for(int j = i+1; j < strip.size() && abs(strip[i].y-strip[j].y)<d; j++){
//             d = min(d, dis(strip[i], strip[j]));
//         }
//     }
//     return d;
// }

double closest(point P[], int n) {
    if (n <= 3){
        double d = inf;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                d = min(d, dis(P[i], P[j]));
            }
        }
        return d;
    }
    int mid = n >> 1;
    double d1 = closest(P, mid);
    double d2 = closest(P+mid, n-mid);
    double d = min(d1, d2);
    point Stp[n+5];
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if (abs(P[i].x-P[mid].x) < d){
            Stp[cnt++] = P[i];
        }
    }
    sort(Stp, Stp+cnt, cmpy);
    for(int i = 0; i < cnt; i++){
        for(int j = i+1; j < cnt && abs(Stp[i].y-Stp[j].y) < d; j++){
            d = min(d, dis(Stp[i], Stp[j]));
        }
    }
    return d;
}

// double closestpair(int l, int r) {
//     double d = inf;
//     if (r-l+1 <= 3) {
//         for(int i =l; i <= r; i++){
//             for(int j = i+1; j <= r; j++){
//                 d = min(d, dis(points[i], points[j]));
//             }
//         }
//         return d;
//     }

//     int mid = (l+r)>>1;
//     double d1 = closestpair(l, mid);
//     double d2 = closestpair(mid+1, r);
//     d = min(d1, d2);

//     vector<point> strip;

//     for(int i = l; i <= r; i++){
//         if (abs(points[i].x-points[mid].x) < d) strip.pb(points[i]);
//     }
//     sort(strip.begin(), strip.end(), cmpy);
//     for(int i = 0; i < strip.size(); i++){
//         for(int j = i+1; j < strip.size() && abs(strip[i].y-strip[j].y) < d; j++){
//             d = min(d, dis(strip[i], strip[j]));
//         }
//     }
//     return d;
// }

int main(){
    int w;
    scanf("%d", &w);
    while(w--){

        memset(points, 0, sizeof points);
        
        int n; double r, d;
        scanf("%d %lf %lf", &n, &r, &d);
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        sort(points, points+n, cmpx);
        // cp(0,n); 
        // closest(points, n);
        // closestpair(0,n-1);
        printf(closest(points,n)>=d+2*r? "Y\n":"N\n");

    }
    return 0;
}