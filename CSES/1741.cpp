#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

vector<tuple<int,int,int,int>> events;
struct node {
  int a, s;
  node *l = NULL, *r = NULL;
  node () { a = s = 0; }
};
node * root = new node();

int s (node * now) { return now?now->s:0; }

void update (int a, int b, int v, int l = -1e6, int r = 1e6, node * now = root) {
  if (b < l or r < a) return;
  if (a <= l and r <= b) {
    now->a += v;
    if (now->a == 0) now->s = s(now->l) + s(now->r);
    else now->s = r-l+1;
    return;
  }
  int mid = floor((l+r)/2.0);
  if (!now->l) now->l = new node();
  if (!now->r) now->r = new node();
  update(a, b, v, l, mid, now->l); update(a, b, v, mid+1, r, now->r);
  if (now->a == 0) now->s = s(now->l) + s(now->r);
  else now->s = r-l+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n; 
  for (int i = 0; i < n; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    events.push_back({min(b, d),  1, min(a, c), max(a, c)});
    events.push_back({max(b, d), -1, min(a, c), max(a, c)});
  }
  sort(all(events));
  long long ans = 0, start = 0;
  for (auto [y, v, x1, x2] : events) {
    if (x1 == x2) continue;
    ans += 1ll * s(root) * (y-start);
    update(x1, x2-1, v);
    start = y;
  }
  cout << ans << endl;
  return 0;
}
