#include<bits/stdc++.h>
using namespace std;
#define m first
#define c second
typedef pair<long long, long long> pll;
 
int a[100100], b[100100];
vector<pll> hull;
int ind = 0;
bool bad (pll a, pll b, pll c) { return (b.c-a.c)/(a.m-b.m) >= (b.c-c.c)/(c.m-b.m); }
long long eval (pll a, long long x) { return a.m*x+a.c; }
void add (long long m, long long c) {
  while (hull.size() >= 2 and bad(hull[hull.size()-2], hull[hull.size()-1], {m, c})) hull.pop_back();
  hull.push_back({m, c});
}
long long query (long long x) {
  if (hull.empty()) return 0;
  if (ind >= hull.size()) ind = hull.size()-1;
  while (ind < hull.size()-1 and eval(hull[ind],x) > eval(hull[ind+1],x)) ind++;
  return eval(hull[ind], x);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) cin >> b[i];
  for (int i = 1; i <= n; i++) add(b[i], query(a[i]));
  cout << hull.back().c << endl;
  return 0;
}
