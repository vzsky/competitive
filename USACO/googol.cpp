#include<bits/stdc++.h>
using namespace std;

bool check (string now, string o) {
  string l, r;
  for (int i = 0; i < o.size()-1; i++) {
    cout << now << endl; cin >> l >> r;
    now = o[i]=='l'?l:r;
  }
  if (now == "0") return 0;
  return 1;
}

pair<int,string> solve (string now = "1") {
  string l, r; cout << now << endl; cin >> l >> r;
  if (l == "0") return {1,""};
  auto [sz, last] = solve(l);
  if (check(r, "r"+last)) return {2*sz+1, "r"+last};
  return {2*sz, "l"+last};
}

int main(){
  auto ans = solve().first;
  cout << "Answer " << ans << endl;
  return 0;
}
