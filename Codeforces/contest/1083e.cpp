#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define m first 
#define c second
typedef pair<long long, long long> pll;
 
struct A {
  long long x, y, a;
  bool operator < (const A & o) const { return x < o.x; }
}; 
vector<A> rects, srect;
long long dp[1000100];
 
long long eval (pll a, long long x) { return a.first * x + a.second; }
bool bad (pll a, pll b, pll c) { return (double)(c.c-b.c)*(double)(a.m-b.m) >= (double)(b.c-a.c)*(double)(b.m-c.m); }
 
vector<pll> hull;
int ind = 0;
void add (long long m, long long c) { // add mx+c m decreases
  while (hull.size() >= 2 and bad(hull[hull.size()-2], hull[hull.size()-1], {m, c})) hull.pop_back();
  hull.push_back({m, c});
}
 
long long ask (long long x) { // ask x x decreases
  if (ind >= hull.size()) ind = hull.size()-1;
  while (ind < hull.size()-1 and eval(hull[ind], x) <= eval(hull[ind+1], x)) ind++;
  return eval(hull[ind], x);
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    long long x, y, a; cin >> x >> y >> a;
    srect.push_back({x, y, a});
  }
  sort(all(srect));
 
  long long ans = 0;
  add(0, 0);
  for (int i = 0; i < srect.size(); i++) {
    dp[i] = ask(srect[i].y) + (srect[i].x * srect[i].y) - srect[i].a;
    add(-srect[i].x, dp[i]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
