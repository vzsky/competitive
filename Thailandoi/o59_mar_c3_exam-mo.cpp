#include<bits/stdc++.h>
using namespace std;

const int ROOT = 230;

struct Q {
  int l, r, i;
  bool operator < (const Q & o) const {
    return r < o.r;
  }
};

vector<Q> question[250];

int a[50100], cnt[50100], ans[500100];
map<int,int> m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q; cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    v.push_back(a[i]);
  }
  int sz = 0;
  sort(v.begin(), v.end());
  for(int i=0 ; i<n ; i++) if(!m.count(v[i])) m[v[i]] = ++sz;
  for(int i=0 ; i<n ; i++) a[i] = m[a[i]];
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l, r; cin >> l >> r;
    question[l/ROOT].push_back({l, r, i});
  }
  for (int i = 0; i <= ROOT; i++) {
    if (question[i].size() == 0) continue;
    sort(question[i].begin(), question[i].end());
    auto f = question[i][0];
    int cou = 0;
    for (int j = f.l; j <= f.r; j++) {
      cnt[a[j]]++;
      if (cnt[a[j]] >= 2) cou++;
    }
    int l = f.l, r = f.r;
    ans[f.i] = cou;

    for(int j=1 ; j<question[i].size() ; j++) {
      auto f = question[i][j];
      while(r < f.r) {
        r++;
        cnt[a[r]]++;
        if (cnt[a[r]] >= 2) cou++;
      }
      while(l > f.l) {
        l--;
        cnt[a[l]]++;
        if (cnt[a[l]] >= 2) cou++;
      }
      while(l < f.l) {
        cnt[a[l]]--;
        if (cnt[a[l]] >= 1) cou--;
        l++;
      }
      ans[f.i] = cou;
    }
    for(int j=1 ; j<=sz ; j++) cnt[j] = 0;
  }
  for(int i=0 ; i<q ; i++)
   cout << ans[i] << "\n";
  return 0;
}