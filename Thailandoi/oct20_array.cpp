#include<bits/stdc++.h>
using namespace std;

struct Q { int o, a, b, v; };
vector<Q> quest;
vector<int> s;
int sz;
map<int,int> m;
struct SEG { long long v, laz; } seg[800100];

void push(int now, int l, int r) {
  long long laz = seg[now].laz;
  if (laz == 0) return;
  seg[now].v = laz * (s[r]-s[l-1]);
  seg[now].laz = 0;
  if (l == r) return;
  seg[now*2].laz = laz;
  seg[now*2+1].laz = laz;
}

void update (int a, int b, int v, int now = 1, int l = 1, int r = sz) {
  push(now, l, r);
  if (a > r or b < l) return;
  if (a <= l and r <= b) {
    seg[now].laz = v;
    push(now, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(a, b, v, now*2, l, mid); update(a, b, v, now*2+1, mid+1, r);
  seg[now].v = seg[now*2].v + seg[now*2+1].v;
}

long long query (int a, int b, int now = 1, int l = 1, int r = sz) {
  push(now, l, r);
  if (a > r or b < l) return 0ll;
  if (a <= l and r <= b) return seg[now].v;
  int mid = (l+r)/2;
  return query(a, b, now*2, l, mid) + query(a, b, now*2+1, mid+1, r);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q; cin >> n >> q;
  for (int i = 0; i < q; i++) {
    int o, a, b, v = 0;
    cin >> o >> a >> b;
    if (!o) cin >> v;
    quest.push_back({o, a, b, v});
    s.push_back(a); s.push_back(b);
  }
  sort(s.begin(), s.end());
  s.resize(unique(s.begin(), s.end())-s.begin());
  sz = s.size()-1;
  for (int i = 0; i < s.size(); i++) m[s[i]] = i+1;
  
  for (int i = 0; i < q; i++) {
    auto [o, a, b, v] = quest[i];
    if (!o) update(m[a], m[b]-1, v);
    else cout << query(m[a], m[b]-1) << '\n';
  }
  return 0;
}
