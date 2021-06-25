#include "train.h"
#include <bits/stdc++.h>
using namespace std;

int seg[800100], laz[800100], n, m;

void build (int now = 1, int l = 0, int r = n-1) {
  if (l == r) return void(seg[now] = laz[now] = 1e9); 
  int mid = (l+r)/2;
  build(now*2, l, mid); build(now*2+1, mid+1, r);
  seg[now] = laz[now] = 1e9;
}

void push (int now, int l, int r) {
  if (l != r) {
    laz[now*2] = min(laz[now*2], laz[now]);
    laz[now*2+1] = min(laz[now*2+1], laz[now]);
  }
  seg[now] = min(seg[now], laz[now]);
  laz[now] = 1e9;
}

void update (int a, int b, int v, int l = 0, int r = n-1, int now = 1) {
  push(now, l, r);
  if (r < a or b < l) return;
  if (a <= l and r <= b) {
    laz[now] = min(laz[now], v);
    push(now, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(a, b, v, l, mid, now*2); update(a, b, v, mid+1, r, now*2+1);
  seg[now] = min(seg[now*2], seg[now*2+1]);
}

int ask (int a, int l = 0, int r = n-1, int now = 1) {
  push(now, l, r);
  if (r < a or a < l) return 1e9;
  if (l == r) return seg[now];
  int mid = l+r>>1;
  return min(ask(a, l, mid, now*2), ask(a, mid+1, r, now*2+1));
}

int find_min_cost(int N, int M,vector<int>& s,vector<int>& t,vector<int>& c) {
  n=N; m=M;
  build(); update(0, 0, 0);
  for (int i = 0; i < M; i++) update(s[i], t[i], ask(s[i]) + c[i]);
  return ask(n-1)>=1e9?-1:ask(n-1);
}