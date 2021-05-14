#include "koala.h"
#include <bits/stdc++.h>
using namespace std;
int b[110], r[110];
 
void clear () {
  memset(b, 0, sizeof b);
  memset(r, 0, sizeof r);
}
 
int minValue(int N, int W) {
  clear();
  b[0] = 1; playRound(b, r);
  for (int i = 0; i < N; i++) if (r[i] == 0) return i;
  assert(false);
}
 
int maxValue(int N, int W) {
  vector<int> t;
  vector<int> xs = {1, 2, 4, 11};
  for (int i = 0; i < N; i++) t.push_back(i);
  for (int x : xs) {
    clear();
    for (auto i : t) b[i] = x;
    playRound(b, r);
    t.clear();
    for (int i = 0; i < N; i++) {
      if (r[i] > x) t.push_back(i);
    }
  }
  return t[0];
}
 
int solve (int aa, int bb, int x) {
  int n = 100, w = 100;
  vector<int> gr;
  clear();
  b[aa] = x, b[bb] = x; playRound(b, r);
  for (int i = 0; i < n; i++) if (r[i] > 1 and r[i] > b[i]) gr.push_back(i); 
  if (gr.size() == 1) {
    if (gr[0] == aa) return 0;
    else return 1;
  }
  if (gr.size() == 0) return -100;
  if (gr.size() == 2) return 100;
  assert(false);
}
 
bool compare(int aa, int bb) {
  int n = 100, w = 100;
  int s3 = solve(aa, bb, 3);
  if (s3 == 100) {
    int s6 = solve(aa, bb, 6);
    if (s6 == 100) return solve(aa, bb, 10);
    return s6;
  }
  else if (s3 == -100) {
    int mn = minValue(n, w);
    if (mn == aa) return 1;
    if (mn == bb) return 0;
    return solve(aa, bb, 2);
  }
  return s3;
}
 
bool compare2 (int aa, int bb) {
  int n = 100, w = 200;
  clear(); b[aa] = n; b[bb] = n;
  playRound(b, r);
  if (r[aa] > n) return 0;
  else return 1;
}
 
int greaterValue(int N, int W) { return compare(0, 1); }

void split(vector<int> v, int L, int R, int *P) {
  if (L == R) return void(P[v[0]] = L);
  clear();
  int num = min(100/(R-L+1), (int)pow(L, 0.5));
  for (auto x : v) b[x] = num;
  playRound(b, r);
  vector<int> m, n;
  for (int x : v) {
    if (r[x] > b[x]) m.push_back(x);
    else n.push_back(x);
  }
  int mid = (L+n.size()-1);
  split(m, mid+1, R, P);
  split(n, L, mid, P);
}
 
void allValues(int N, int W, int *P) {
  if (W == 2*N) {
    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);
    stable_sort(v.begin(), v.end(), compare2);
    for (int i = 0; i < v.size(); i++) {
      P[v[i]] = i+1;
    }
  } else {
    vector<int> v;
    for (int i = 0; i < N; i++) v.push_back(i);
    split(v, 1, N, P);
  }
  return;
}