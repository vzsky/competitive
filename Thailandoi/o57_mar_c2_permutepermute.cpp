#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

struct A {
  int p[10];
} d[200100], seg[800100], iden;

int position[200100];
vector<int> pos;
vector<pair<int,int>> query;
int get (int x) { return lower_bound(all(pos), x)-pos.begin(); } 
int sz;

void update (int a, A val, int now = 1, int l = 0, int r = sz) {
  if (a < l or r < a) return;
  if (l == r) { seg[now] = val; return; } 
  int mid = (l+r)/2;
  update(a, val, now*2, l, mid);
  update(a, val, now*2+1, mid+1, r);
  for (int i = 0; i < 10; i++) seg[now].p[i] = seg[now*2+1].p[seg[now*2].p[i]];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < 10; i++) iden.p[i]=i;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x; 
    for (int j = 0; j < 10; j++) cin >> d[i].p[j];
    pos.push_back(x);
    position[i] = x;
  }
  for (int i = 0; i < m; i++) {
    int ind, x; cin >> ind >> x;
    pos.push_back(x);
    query.push_back({ind, x});
  }
  sort(all(pos)); pos.resize(unique(all(pos))-pos.begin());
  sz = pos.size();
  for (int i = 1; i <= 800010; i++) seg[i] = iden;
  for (int i = 1; i <= n; i++) update(get(position[i]), d[i]);
  for (auto [ind, x] : query) {
    update(get(position[ind]), iden);
    update(get(x), d[ind]);
    position[ind] = x;
    cout << seg[1].p[0] << '\n';
  }

  return 0;
}