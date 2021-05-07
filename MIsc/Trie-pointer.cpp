#include<bits/stdc++.h>
using namespace std;

struct node {
  node* a[26];
  int cnt;
};

int cnt (node* t) { return t?t->cnt:0; }

void insert (char* c, node* now) {
  if (*c == '\0') return void(now->cnt++);
  int ind = (*c)-'a';
  if (now->a[ind] == NULL) now->a[ind] = new node();
  insert(++c, now->a[ind]);
  now->cnt = 0;
  for (int i = 0; i < 26; i++) now->cnt += cnt(now->a[i]);
}

int query (char* c, node* now) {
  if (*c == '\0') return now->cnt;
  int ind = (*c)-'a';
  if (!now->a[ind]) return 0;
  return query(++c, now->a[ind]);
}

node * root = new node();

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    insert(&s[i], root);
  }
  int q; cin >> q;
  while (q--) {
    string p; cin >> p;
    cout << query(&p[0], root) << '\n';
  }
  return 0;
}