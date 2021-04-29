#include<bits/stdc++.h>
using namespace std;
#define x real()
#define y imag()
typedef complex<double> point;

vector<point> p1, p2, h1, h2;

double cross (point a, point b) { return (conj(a) * b).y; }
bool isRight (point a, point b, point next) {
  return cross(next-b, next-a) > 0 ? true : false;
}

vector<point> makeHull (vector<point> p) {
  vector<point> hull;
  sort(p.begin(), p.end(), [&](const point &a, const point &b){
    return a.y < b.y;
  });
  hull.push_back(p[0]);
  sort(p.begin()+1, p.end(), [&](const point &a, const point &b){
    if (arg(a-hull[0]) == arg(b-hull[0])) return abs(a-hull[0]) < abs(b-hull[0]);
    return arg(a-hull[0]) < arg(b-hull[0]);
  });
  hull.push_back(p[1]);
  for (int i = 2; i < p.size(); i++) {
    while (hull.size() >= 2 and isRight(hull[hull.size()-2], hull.back(), p[i])) hull.pop_back();
    hull.push_back(p[i]);
  }
  if (isRight(hull[hull.size()-2], hull.back(), p[0])) hull.pop_back();
  return hull;
}

bool searchRange (point s, vector<point> &h) {
  int l = 1, r = h.size()-2;
  while (l < r) {
    int mid = (l+r+1)/2;
    bool b1 = isRight(h[0], h[mid], s); 
    if (b1) r = mid-1;
    else l = mid;
  }
  bool status = false;
  status |= isRight(h[l], h[l+1], s);
  status |= isRight(h.back(), h[0], s);
  status |= isRight(h[0], h[1], s);
  return !status;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    double a, b; cin >> a >> b;
    p1.push_back({a, b});
  }
  for (int i = 0; i < m; i++) {
    double a, b; cin >> a >> b;
    p2.push_back({a, b});
  }

  h1 = makeHull(p1);
  h2 = makeHull(p2);

  int ans = 0;
  for (auto s : p1) ans+=searchRange(s, h2);
  for (auto s : p2) ans+=searchRange(s, h1);

  cout << ans;
  return 0;
}