#include<bits/stdc++.h>
using namespace std;

const int N = 100000;
int tree[N][26], term[N];

int cnt = 0;
void insert (string s) {
  int cur = 0;
  for (auto c : s) {
    term[cur]++;
    if (tree[cur][c-'a'] == 0) cur = tree[cur][c-'a'] = ++cnt;
    else cur = tree[cur][c-'a'];
  }
  term[cur]++;
}

int query (string s) {
  int cur = 0;
  for (auto c : s) {
    if (tree[cur][c-'a'] == 0) return 0;
    else cur = tree[cur][c-'a'];
  }
  return term[cur];
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  string temp = "";
  for (int i = s.size()-1; i >= 0; i--) {
    temp = s[i]+temp;
    insert(temp);
  }
  int q; cin >> q;
  while (q--) {
    string p; cin >> p;
    cout << query(p) << '\n';
  }
  return 0;
}