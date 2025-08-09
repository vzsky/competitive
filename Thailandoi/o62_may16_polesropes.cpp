#include<bits/stdc++.h>
using namespace std;

int n, m; 
struct A {
  int sum, laz;
} seg[400100];

void pushLazy (int now, int l, int r) {
  if (l != r) {
    if (seg[now].laz) seg[now*2].laz = seg[now*2+1].laz = 1;
  }
  if (seg[now].laz) {
    seg[now].sum = 0;
    seg[now].laz = 0;
  }
}

void build (int now = 1, int l = 1, int r = n) {
  if (l == r) {
    seg[now].sum = 10;
    return;
  }
  int mid = (l+r)/2;
  build(now*2, l, mid);
  build(now*2+1, mid+1, r);
  seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
}

int sum (int a, int b, int now = 1, int l = 1, int r = n) {
  pushLazy(now, l, r);
  if (b < l or r < a) return 0;
  if (seg[now].laz)   return 0;
  if (a <= l and r <= b) {
    return seg[now].sum;
  }
  int mid = (l+r)/2;
  return sum(a, b, now*2, l, mid) + sum(a, b, now*2+1, mid+1, r);
}

void update (int a, int b, int now = 1, int l = 1, int r = n) {
  pushLazy(now, l, r);
  if (b < l or r < a) return;
  if (a <= l and r <= b) {
    seg[now].laz = 1;
    pushLazy(now, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(a, b, now*2, l, mid);
  update(a, b, now*2+1, mid+1, r);
  seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
}

void add (int a, int val, int now = 1, int l = 1, int r = n) {
  pushLazy(now, l, r);
  if (r < a or a < l) return;
  if (l == r) {
    seg[now].sum += val;
    return;
  }
  int mid = (l+r)/2;
  add(a, val, now*2, l, mid);
  add(a, val, now*2+1, mid+1, r);
  seg[now].sum = seg[now*2].sum + seg[now*2+1].sum;
}

int find (int want, int now = 1, int l = 1, int r = n) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (seg[now*2].sum >= want) return find (want, now * 2, l, mid);
  return find(want - seg[now*2].sum, now * 2 + 1, mid+1, r);
}

int main(){
  scanf("%d %d", &n, &m); n--;
  build();
  while(m--) {
    int t, a, b; scanf("%d", &t);
    if (t == 1) {
      scanf("%d %d", &a, &b);
      int half = b/2;
      int suml = sum(1, a-1);
      int sumr = sum(a+1, n);
      if (suml < half) {
        int x = find(b-suml + sum(1, a));
        int s = sum(a+1, x-1);
        update(1, a-1);
        update(a+1, x-1);
        add(x, -b+suml+s);
      }
      else if (sumr < half) {
        int x = find(-b+sumr + sum(1, a-1));
        int s = sum(x+1, a-1);
        update(a+1, n);
        update(x+1, a-1);
        add(x, -b+sumr+s);
      }
      else {
        int xr = find(half + sum(1, a));
        int xl = find(-half + sum(1, a-1));
        int sr = sum(a+1, xr-1);
        int sl = sum(xl+1, a-1);
        update(a+1, xr-1);
        update(xl+1, a-1);
        add(xr, -half+sr);
        add(xl, -half+sl);
      }
      add(a, b);
    }
    if (t == 2) {
      scanf("%d", &a);
      printf("%d\n", sum(a,a));
    }
  }
  return 0;
}
