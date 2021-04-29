#include<bits/stdc++.h>
using namespace std;
#define x real()
#define y imag()
typedef complex<double> point;

// Graham scan going ccw from lowest

vector<point> p, hull;

double cross (point a, point b) { return (conj(a) * b).y; }

bool isRight (point a, point b, point next) {
  return cross(next-a, next-b) > 0 ? false : true;
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

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    double a, b; cin >> a >> b;
    p.push_back({a, b});
  }

  hull = makeHull(p);
  
  cout << hull.size() << endl;
  for(auto v : hull) {
    cout << v << endl;
  }

  return 0;
}