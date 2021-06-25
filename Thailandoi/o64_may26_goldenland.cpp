// THIS ONLY SCORED 64
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
#include "goldenland.h"
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int g[2][60100], h[2][60100], c[2][60100];
int n, m, tot[2] = {0, 0}, vers[2][60100], sz0, sz1, num[1000100], res[1000100];

struct node {
  int l, r, v;
} seg[2][1000100];

int clone (int w, int now) {
  if (now == -1) {
    ++tot[w];
    seg[w][tot[w]].l = seg[w][tot[w]].r = seg[w][tot[w]].v = 0;
    return tot[w];
  }
  seg[w][++tot[w]] = seg[w][now];
  return tot[w];
}

int update (int w, int v, int now, int l, int r)  {
  if (r < v or v < l) return now;
  if (l == r) {
    int nw = clone(w, now);
    seg[w][nw].v++;
    return nw;
  }
  int mid = l+r>>1;
  int nw = clone(w, now);
  seg[w][nw].l = update(w, v, seg[w][nw].l, l, mid);
  seg[w][nw].r = update(w, v, seg[w][nw].r, mid+1, r);
  seg[w][nw].v = seg[w][seg[w][nw].l].v + seg[w][seg[w][nw].r].v; 
  return nw;
}

int query (int w, int v, int now, int l, int r) {
  if (r < v or v < l) return 0;
  if (now == -1) return 0;
  if (l == r) return seg[w][now].v;
  int mid = l+r>>1;
  return query(w, v, seg[w][now].l, l, mid) + query(w, v, seg[w][now].r, mid+1, r);
}

vector<int> coord[2];
int get (int w, int x) {
  int ind = lower_bound(all(coord[w]), x)-coord[w].begin();
  if (coord[w][ind] != x) return -1;
  return ind;
}

void init_land(int N, int M, int P, vector<int> A, vector<int> B){
  n=N; m=M;

  for (int i = 0; i <= 1000000; i++) {
    res[i] = 1;
    num[i] = i;
  }

  for (int i = 2; i <= 1000000; i++) {
    if (num[i] == 1) continue;
    for (int j = i; j <= 1000000; j+=i) {
      while((num[j] % (i*i)) == 0) {
        num[j] /= (i*i);
      }
      if (num[j] % i == 0) {
        num[j] /= i; res[j] *= i;
      }
    }
  }

  for (int i = 0; i < n; i++) c[0][i] = res[A[i]];
  for (int i = 0; i < m; i++) c[1][i] = res[B[i]];


  for (int i = 0; i < n; i++) coord[0].push_back(c[0][i]);
  for (int i = 0; i < m; i++) coord[1].push_back(c[1][i]);
  sort(all(coord[0])); coord[0].resize(unique(all(coord[0]))-coord[0].begin());
  sort(all(coord[1])); coord[1].resize(unique(all(coord[1]))-coord[1].begin());
  sz0 = coord[0].size();
  sz1 = coord[1].size();

  for (int i = 0; i < n; i++) h[0][i] = get(0, c[0][i]);
  for (int i = 0; i < m; i++) h[1][i] = get(1, c[1][i]);

  vers[0][0] = update(0, h[0][0], -1, 0, sz0);
  vers[1][0] = update(1, h[1][0], -1, 0, sz1);
  for (int i = 1; i < n; i++) vers[0][i] = update(0, h[0][i], vers[0][i-1], 0, sz0);
  for (int i = 1; i < m; i++) vers[1][i] = update(1, h[1][i], vers[1][i-1], 0, sz1);

  for (int i = 0; i < n; i++) g[1][i] = get(1, c[0][i]);
  for (int i = 0; i < m; i++) g[0][i] = get(0, c[1][i]);

}

// ANSWER TOO SLOW, NEEDS min(dC, dR) (w/o log)
long long answer_query(int r1, int c1, int r2, int c2){
  long long ans = 0;
  if (c2-c1 > r2-r1) {
    for (int i = r1; i <= r2; i++) {
      if (g[1][i] == -1) continue;
      ans += query(1, g[1][i], vers[1][c2], 0, sz1) - query(1, g[1][i], vers[1][c1-1], 0, sz1);
    }
  }
  else {
    for (int i = c1; i <= c2; i++) {
      if (g[0][i] == -1) continue;
      ans += query(0, g[0][i], vers[0][r2], 0, sz0) - query(0, g[0][i], vers[0][r1-1], 0, sz0);
    }
  }
  return ans;
}
