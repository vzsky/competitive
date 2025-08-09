#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
const int mod = 1e9+7;
struct A {
  int sum, laz;
} seg[3][4000010];

void push (int i, int now, int l, int r) {
  if (l != r) {
    seg[i][now*2].laz += seg[i][now].laz;
    seg[i][now*2+1].laz += seg[i][now].laz;
    seg[i][now*2].laz %= mod;
    seg[i][now*2+1].laz %= mod;
  }
  seg[i][now].sum += (seg[i][now].laz * (r-l+1ll)) % mod;
  seg[i][now].sum %= mod;
  seg[i][now].laz = 0;
}

void update (int i, int a, int b, int val, int now = 1, int l = 1, int r = N) {
  push(i, now, l, r);
  if (b < l or r < a) return;
  if (a <= l and r <= b) {
    seg[i][now].laz += (val % mod);
    seg[i][now].laz %= mod;
    push(i, now, l, r);
    return;
  }
  int mid = (l+r)/2;
  update(i, a, b, val, now*2, l, mid);
  update(i, a, b, val, now*2+1, mid+1, r);
  seg[i][now].sum = seg[i][now*2].sum + seg[i][now*2+1].sum;
  seg[i][now].sum %= mod;
}

int query (int i, int a, int b, int now = 1, int l = 1, int r = N) {
  push(i, now, l, r);
  if (b < l or r < a) return 0;
  if (a <= l and r <= b) return seg[i][now].sum;
  int mid = (l+r)/2;
  return (query(i, a, b, now*2, l, mid) + query(i, a, b, now*2+1, mid+1, r)) % mod;
}


int main(){
  int l[3], t; 
  scanf("%d %d %d %d", &l[0], &l[1], &l[2], &t);

  while (t--) {
    int o; cin >> o;
    if (o == 0) {
      int f[3], s[3], v1, v2, w[3];
      scanf("%d %d %d %d %d %d %d %d", &f[0], &s[0], &f[1], &s[1], &f[2], &s[2], &v1, &v2);
      for (int i = 0; i < 3; i++) w[i] = s[i]-f[i]+1;

      for (int i = 0; i < 3; i++) {
        int V2 = v2 * ( (1ll*(l[(i+1)%3]-w[(i+1)%3])*(l[(i+2)%3]-w[(i+2)%3])) % mod) % mod;
        int V1 = v1 * ( (1ll*w[(i+1)%3]*w[(i+2)%3]) % mod) % mod;
        update(i, 1, l[i], V2);
        update (i, f[i], s[i],  (V1 - V2) % mod);
      }
    }
    if (o == 1) {
      int d, l, r;
      scanf("%d %d %d", &d, &l, &r);
      int answer = (query(d-1, l, r) + mod) % mod;
      printf("%d\n", answer);
    }
  }
  return 0;
}

