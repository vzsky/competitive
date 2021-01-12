#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second

bool sorty (pii a, pii b) {
  return a.y < b.y;
}
vector<pii> a;
set<pii> s;
long long cost;
long long dis (pii a, pii b) {
  return abs(a.x-b.x)+abs(b.y-a.y);
}
void add (pii u) {
  auto pos = s.lower_bound(u);
  if (pos == s.end()) {
    cost += dis(*--pos, u);
  }
  else if (pos == s.begin()) {
    cost += dis(*pos, u);
  }
  else {
    auto next = *pos--;
    cost += dis(*pos, u) + dis(u, next);
    cost -= dis(*pos, next);
  }
  s.insert(u);
}

void del (pii u) {
  auto pos = s.find(u);

  auto now = pos;
  auto next = ++pos;
  pos--;
  if (now == s.begin()) {
    cost -= dis(*now, *next);
  }
  else if (next == s.end()) {
    cost -= dis(*now, *(--pos));
  }
  else {
    auto last = (--pos);
    cost -= dis(*last, *now) + dis(*now, *next);
    cost += dis(*last, *next);
  }
  s.erase(now);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  if (k == 1) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    a.push_back({x, y});
  }
  sort(a.begin(), a.end(), sorty);
  
  s.insert(a[0]);
  for (int i = 1; i < k; i++) add(a[i]);

  long long mn = cost;
  for (int i = k; i < n; i++) {
    add(a[i]);
    del(a[i-k]);
    mn = min(mn, cost);
  }

  cout << mn << endl;
  return 0;
}