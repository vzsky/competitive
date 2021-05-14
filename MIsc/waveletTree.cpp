#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int a[N];
vector<int> seg[N*4], lef[N*4];

// note that low and high is based on value
void build (int low = 1, int high = 1e5, int now = 1) {
  if (low == high) return;
  if (seg[now].size() == 0) return;
  int mid = (low+high)/2;

  for (auto x : seg[now]) {
    if (a[x] <= mid) { seg[now*2].push_back(x); lef[now].push_back(1); }
    else { seg[now*2+1].push_back(x); lef[now].push_back(0); }
  }
  // keep number of element in 1..i that'll be in the left's child
  for (int i = 1; i < lef[now].size(); i++) { lef[now][i] = lef[now][i-1]+lef[now][i]; }

  build(low, mid, now*2);
  build(mid+1, high, now*2+1);
}

int kth (int l, int r, int k, int low = 1, int high = 1e5, int now = 1) {
  // cerr << low << ' ' << high << endl;
  if (low == high) return low;
  int mid = (low+high)/2;

  int binl = (l?lef[now][l-1]:0);
  int inl = lef[now][r] - binl;
  int inr = r-l+1-inl;

  if (inl >= k) return kth (binl, binl+inl-1, k, low, mid, now*2);
  else return kth (l-binl, l-binl+inr-1, k-inl, mid+1, high, now*2+1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  // 0 indexed always! ;-;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    seg[1].push_back(i);
  }
  build();
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int k, l, r; cin >> k >> l >> r;
    if (r-l+1 < k) cout << -1 << endl;
    else cout << kth(l, r, k) << endl;
  }
  return 0;
}