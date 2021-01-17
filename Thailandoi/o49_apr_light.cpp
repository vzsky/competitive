#include<bits/stdc++.h>
using namespace std;

struct SEG {
  int sum, odd, laz, cnt;
} seg[400100];
int l, n, a[100100], s[100100];

map<int,int> m;

void push (int now, int l, int r) {
  if (seg[now].laz == 0) return;
  seg[now].odd = seg[now].sum - seg[now].odd;
  seg[now].laz = 0;
  if (l == r) return;
  seg[now*2].laz ^= 1;
  seg[now*2+1].laz ^= 1;
}

SEG merge (SEG a, SEG b) {
  return {a.sum + b.sum, a.odd + b.odd, 0, a.cnt + b.cnt};
}

void add (int val, int ind, bool isodd, int now = 1, int l = 1, int r = n) {
  push(now, l, r);
  if (ind < l or ind > r) return;
  if (l == r) {
    seg[now].sum += val;
    seg[now].cnt = 1;
    if (isodd) seg[now].odd += val;
    return;
  }
  int mid = (l+r)/2;
  add(val, ind, isodd, now*2, l, mid); add(val, ind, isodd, now*2+1, mid+1, r);
  seg[now] = merge(seg[now*2], seg[now*2+1]);
}

void update (int a, int b = n, int now = 1, int l = 1, int r = n) {
  push(now, l, r);
  if (b < l or r < a) return;
  if (a <= l and r <= b) {
    seg[now].laz ^= 1;
    push(now, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(a, b, now*2, l, mid); update(a, b, now*2+1, mid+1, r);
  seg[now] = merge(seg[now*2], seg[now*2+1]);
}

SEG query (int a, int b, int now = 1, int l = 1, int r = n) {
  push(now, l, r);
  if (b < l or r < a) return {0, 0, 0, 0};
  if (a <= l and r <= b) return seg[now];
  int mid = (l+r)/2;
  return merge(query(a, b, now*2, l, mid), query(a, b, now*2+1, mid+1, r));
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> l >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], s[i] = a[i];
  sort(s+1, s+n+1);
  for (int i = 1; i <= n; i++) m[s[i]] = i;
  for (int i = 1; i <= n; i++) {
    bool isodd = !(query(1, m[a[i]]).cnt & 1);
    add(a[i], m[a[i]], isodd);
    update(m[a[i]]+1);
    auto q = query(1, n);
    int ans = l;
    if (q.cnt & 1) ans -= l;
    ans += 2*q.odd - q.sum;
    cout << ans << '\n';
  }
  return 0;
}