#include "wall.h"
#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 2000100;
 
struct A {
  int mn, mx;
} seg[4*MAXN];
 
int* ans, N;
 
void tag (int now, int mn, int mx) {
  // cerr << "tag" << now << ' ' << mn << ' ' << mx << endl;
  seg[now].mn = min(mx, max(mn, seg[now].mn));
  seg[now].mx = max(mn, min(mx, seg[now].mx));
}
 
void push (int now, int l, int r) {
  if (l == r) {
    ans[l] = min(seg[now].mx, max(seg[now].mn, ans[l]));
  }
  else {
    tag(now*2, seg[now].mn, seg[now].mx);
    tag(now*2+1, seg[now].mn, seg[now].mx);
  }
  seg[now].mn = 0;
  seg[now].mx = 1e9;
}
 
void build (int now = 1, int l = 0, int r = N-1) {
  seg[now].mn = 0;
  seg[now].mx = 1e9;
  if (l == r) return;
  int mid = (l+r)/2;
  build(now*2, l, mid);
  build(now*2+1, mid+1, r);
}
 
void update (int a, int b, int mn, int mx, int now = 1, int l = 0, int r = N-1) {
  if (r < a or l > b) return;
  if (a <= l and r <= b) return tag(now, mn, mx);
  push(now, l, r);
  int mid = (l+r)/2;
  update(a, b, mn, mx, now*2, l, mid);
  update(a, b, mn, mx, now*2+1, mid+1, r);
}
 
void dfs (int now = 1, int l = 0, int r = N-1) {
  push(now, l, r);
  if (l == r) return;
  int mid = (l+r)/2;
  dfs(now*2, l, mid);
  dfs(now*2+1, mid+1, r);
}
 
void buildWall(int n, int k, int op[], int l[], int r[], int h[], int finalHeight[]){
	ans = finalHeight;
	N = n;
	build();
	for(int i = 0; i < k; i++) {
		if(op[i] == 1) update(l[i], r[i], h[i], 1e9);
		else if(op[i] == 2) update(l[i], r[i], 0, h[i]);
	}
	dfs();
}