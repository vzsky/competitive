#include<bits/stdc++.h>
using namespace std;

int n;
int h[100100], root[100100], high[100100];

struct SEG {
  int suf, pre, mx;
  int l, r;
} seg[2000100];

int tot = 0;
int clone (int n) {
  tot++;
  seg[tot] = seg[n];
  return tot;
}

SEG merge (SEG sl, SEG sr, int l, int r) {
  int mid = (l+r)/2;
  SEG temp;
  temp.pre = sl.pre;
  temp.suf = sr.suf;
  if (sl.pre == mid-l+1) temp.pre = sl.pre + sr.pre;
  if (sr.suf == r-mid) temp.suf = sl.suf + sr.suf;
  temp.mx = max(max(sl.mx, sr.mx), sl.suf+sr.pre);
  return temp;
}

int update (int now, int ind, int l = 1, int r = n) {
  if (ind < l or ind > r) return now;
  if (l == r) {
    int nw = clone(now);
    seg[nw].suf = seg[nw].pre = seg[nw].mx = 1;
    return nw;
  }
  int nw = clone(now);
  int mid = (l+r)/2;
  int sl = update(seg[nw].l, ind, l, mid);
  int sr = update(seg[nw].r, ind, mid+1, r);
  seg[nw] = merge(seg[sl], seg[sr], l, r);
  seg[nw].l = sl;
  seg[nw].r = sr;

  return nw;
}

SEG query (int now, int a, int b, int l = 1, int r = n) {
  if (r < a or l > b) return seg[0];
  if (a <= l and r <= b) return seg[now];
  int mid = (l+r)/2;
  return merge(query(seg[now].l, a, b, l, mid), query(seg[now].r, a, b, mid+1, r), l, r);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  vector<pair<int,int>> o;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    o.push_back({h[i], i});
  }
  sort(o.begin(), o.end(), greater<pair<int,int>>());
  int ver = 1;
  for (auto [height, i] : o) {
    root[ver] = update(root[ver-1], i);
    high[ver] = height;
    ver++;
  }

  int q; cin >> q;
  while (q--) {
    int l, r, w; cin >> l >> r >> w;

    int a = 1, b = n;
    while (a < b) {
      int mid = (a+b)/2;
      int ch = o[mid].first;
      int qu = query(root[mid], l, r).mx;
      if (qu >= w) b = mid;
      else a = mid+1;
    }
    cout << high[a] << endl;
  }

  return 0;
}