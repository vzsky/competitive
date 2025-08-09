#include<bits/stdc++.h>	
#include <iomanip>
using namespace std;		

struct Point {
  int x, y;
} points[100];

double triangle_area (Point a, Point b, Point c) {
  return abs(a.x * b.y + b.x * c.y + c.x * a.y - a.y * b.x - b.y * c.x - c.y * a.x) / 2.0;
}

int main () {		 
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> points[i].x >> points[i].y;
  }

  double max_area = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      for (int k = j+1; k < n; k++) {
        max_area = max(max_area, triangle_area(points[i], points[j], points[k]));
      }
    }
  }

  cout << fixed << setprecision(3) << max_area;

  return 0;	
}	
