#include<bits/stdc++.h>
using namespace std;

int a[100100], ans[100100];
vector<int> srt;
map<int,int> m, rev;
vector<int> h[100100];

set<pair<int,int>> s, thislevel;
void update (int ind) {
  auto ups = s.upper_bound({ind,ind});
  auto los = ups;
  int l = ind, r = ind;
  if (los != s.begin()) {
    los--;    
    if (los->second+1 == ind) {
      l = los->first;
      s.erase(los);
    }
  }
  if (ups != s.end()) {
    if (ups->first-1 == ind) {
      r = ups->second;
      s.erase(ups);
    }
  }
  s.insert({l, r});

  auto upt = thislevel.upper_bound({ind,ind});
  auto lot = upt;
  if (lot != thislevel.begin()) {
    lot--;    
    if (lot->second+1 == ind) {
      thislevel.erase(lot);
    }
  }
  if (upt != thislevel.end()) {
    if (upt->first-1 == ind) {
      thislevel.erase(upt);
    }
  }
  thislevel.insert({l, r});
}

int main(){
  int n, w; cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    srt.push_back(a[i]);
    ans[i] = -1;
  }
  sort(srt.begin(), srt.end());
  srt.resize(unique(srt.begin(), srt.end())-srt.begin());
  for (int i = 0; i < srt.size(); i++) {
    m[srt[i]] = i+1;
    rev[i+1] = srt[i];
  } 

  for (int i = 1; i <= n; i++) h[m[a[i]]].push_back(i);
  for (int i = srt.size(); i >= 1; i--) {
    thislevel.clear();
    for (auto ind : h[i]) update(ind);
    for (auto x : thislevel) {
      ans[x.second-x.first] = max(ans[x.second-x.first], rev[i]);
    }
  }
  
  if (w == -10) for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  else cout << ans[w];
  return 0;
}