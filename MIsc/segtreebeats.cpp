#include<bits/stdc++.h>
using namespace std;

const int N = 200100;
int n;
long long a[N];
struct A {
  long long sum, max, smax, cnt;
  // cnt is number of elements with value = max
  // no need for lazy tag but update lazily
} seg[4*N];

void build (int now = 1, int l = 1, int r = n) {
  if (l == r) {
    seg[now].cnt = 1;
    seg[now].smax = -1;
    seg[now].sum = seg[now].max = a[l];
    return;
  }
  int mid = (l+r)/2;
  build (now*2, l, mid); build (now*2+1, mid+1, r);

  seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
	seg[now].max = max(seg[now*2].max, seg[now*2+1].max);
	seg[now].smax = max(seg[now*2].smax, seg[now*2+1].smax);

  if (seg[now].max == seg[now*2].max) {
    seg[now].cnt += seg[now*2].cnt;
  } else seg[now].smax = max(seg[now].smax, seg[now*2].smax);
  if (seg[now].max == seg[now*2+1].max) {
    seg[now].cnt += seg[now*2+1].cnt;
  } else seg[now].smax = max(seg[now].smax, seg[now*2+1].smax);
}

void push (int now, int l, int r) {
  if (l == r) return;
  // keep maximum value under parents all the time!
  if (seg[now*2].max > seg[now].max) {
    seg[now*2].sum -= (seg[now*2].max - seg[now].max) * seg[now*2].cnt;
    seg[now*2].max = seg[now].max;
  }
  if (seg[now*2+1].max > seg[now].max) {
    seg[now*2+1].sum -= (seg[now*2+1].max - seg[now].max) * seg[now*2+1].cnt;
    seg[now*2+1].max = seg[now].max;
  }
}

// update every element x in [a..b] to be min(x, v);
void update (int a, int b, int v, int l = 1, int r = n, int now = 1) {
  if (b < l or r < a or seg[now].max <= v) return;
  if (a <= l and r <= b and seg[now].smax < v) {
    // secondmax < x <= max
    seg[now].sum -= (seg[now].max - v) * seg[now].cnt;
    seg[now].max = v;
    return;
  }
  push(now, l, r);
  int mid = (l+r)/2;
  update (a, b, v, l, mid, now*2);
  update (a, b, v, mid+1, r, now*2+1);

	seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
	seg[now].max = max(seg[now*2].max, seg[now*2+1].max);
	seg[now].smax = max(seg[now*2].smax, seg[now*2+1].smax);

  if (seg[now].max == seg[now*2].max) {
    seg[now].cnt += seg[now*2].cnt;
  } else seg[now].smax = max(seg[now].smax, seg[now*2].smax);
  if (seg[now].max == seg[now*2+1].max) {
    seg[now].cnt += seg[now*2+1].cnt;
  } else seg[now].smax = max(seg[now].smax, seg[now*2+1].smax);
}

long long maximum (int a, int b, int l = 1, int r = n, int now = 1) {
  push(now, l, r);
  if (b < l or r < a) return -1e15;
  if (a <= l and r <= b) return seg[now].max;
  int mid = (l+r)/2;
  return max(maximum(a, b, l, mid, now*2), maximum(a, b, mid+1, r, now*2+1));
}

long long summation (int a, int b, int l = 1, int r = n, int now = 1) {
  push(now, l, r);
  if (b < l or r < a) return 0;
  if (a <= l and r <= b) return seg[now].sum;
  int mid = (l+r)/2;
  return summation(a, b, l, mid, now*2) + summation(a, b, mid+1, r, now*2+1);
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m; cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build();
  while (m--) {
    int t, a, b, c; cin >> t >> a >> b;
    if (t == 0) { cin >> c; update(a, b, c); }
    if (t == 1) { cout << maximum(a, b) << endl; }
    if (t == 2) { cout << summation(a, b) << endl; }
  }
  return 0;
}