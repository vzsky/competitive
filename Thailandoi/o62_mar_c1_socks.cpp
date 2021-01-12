#include<bits/stdc++.h>
#include "sockslib.cpp"
using namespace std;

vector<int> v, a;
int matched[2010];

vector<int> preask( vector<int> A){
  // asking matched element lead to an error in the grader site due to the usage of map
  vector<int> b;
  for (auto x : A) if (!matched[x]) b.push_back(x);
  return b;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = num();
  for (int i = 1; i <= 2*n; i++) {
    v.push_back(i);
    
    auto b = preask(v);
    if (ask(b) == b.size()) continue;
    
    int l = 1, r = v.size()-1;
    while(l < r) {
      a.clear();
      int mid = (l+r)/2;
      for (int j = mid; j < v.size(); j++) a.push_back(v[j]);

      auto b = preask(a);
      if (ask(b) == b.size()) r = mid;
      else l = mid+1;
    }

    match(v[l-1], i);
    matched[v[l-1]] = matched[i] = 1;
    v.pop_back();
  }
  return 0;
}