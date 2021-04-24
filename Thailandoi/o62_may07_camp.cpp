#include<bits/stdc++.h>
using namespace std;

struct A {
  int a, b;
  long long c;
  bool operator < (const A & o) const {
    return b < o.b;
  }
};
vector<A> events;
vector<A> endpoint[500100];
long long best[500100];
int from[500100], used[500100], mark[500100];
vector<int> comp;
map<int,int> m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c; cin >> a >> b >> c;
    comp.push_back(a);
    comp.push_back(b);
    events.push_back({a, b, c});
  }
  sort(comp.begin(), comp.end());
  for (int i = 0; i < comp.size(); i++) m[comp[i]] = i+1;

  for (int i = 0; i < n; i++) {
    auto [a, b, c] = events[i];
    endpoint[m[b]].push_back({m[a], c, i});
  }

  for (int b = 1; b <= comp.size(); b++) {
    // b != 1 since first is always a
    best[b] = best[b-1];
    from[b] = b-1;
    for (auto [a, c, ind] : endpoint[b]) {
      if (best[a] + c > best[b]) {
        best[b] = best[a] + c;
        from[b] = a;
        used[b] = ind;
      }
    }
  }

  for (int i = comp.size(); i > 1; i=from[i]) {
    if (used[i] != 0) mark[used[i]] = 1;
  }

  long long ans = 0;
  for (int i = 0; i < n; i++) if (!mark[i]) {
    ans = max(ans, events[i].c);
  }
  ans += best[comp.size()];
  cout << ans;

  return 0;
}