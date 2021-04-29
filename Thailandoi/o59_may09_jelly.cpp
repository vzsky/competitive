#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
const int mod = 1e9+7;
struct A {
  long long sum, laz;
} seg[3][4000100];

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

void update (int i, int a, int b, long long val, int now = 1, int l = 1, int r = N) {
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

long long query (int i, int a, int b, int now = 1, int l = 1, int r = N) {
  push(i, now, l, r);
  if (b < l or r < a) return 0;
  if (a <= l and r <= b) return seg[i][now].sum;
  int mid = (l+r)/2;
  return (query(i, a, b, now*2, l, mid) + query(i, a, b, now*2+1, mid+1, r)) % mod;
}


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long l[3], t; cin >> l[0] >> l[1] >> l[2] >> t;
  while (t--) {
    int o; cin >> o;
    if (o == 0) {
      long long f[3], s[3], v1, v2;
      cin >> f[0] >> s[0] >> f[1] >> s[1] >> f[2] >> s[2] >> v1 >> v2;
      long long w[3];
      for (int i = 0; i < 3; i++) w[i] = s[i]-f[i]+1;

      for (int i = 0; i < 3; i++) {
        update (i, 1, f[i]-1, v2*(((l[(i+1)%3]-w[(i+1)%3])*(l[(i+2)%3]-w[(i+2)%3]))%mod));
        update (i, f[i], s[i], v1*((w[(i+1)%3]*w[(i+2)%3])%mod));
        update (i, s[i]+1, l[i], v2*(((l[(i+1)%3]-w[(i+1)%3])*(l[(i+2)%3]-w[(i+2)%3]))%mod));
      }
    }
    if (o == 1) {
      int d, l, r; cin >> d >> l >> r;
      cout << query(d-1, l, r) << '\n';
    }
  }
  return 0;
}