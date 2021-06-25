#include "requeue.h"
#include <bits/stdc++.h>
using namespace std;

int top[2500100];
int requeue(vector<int> Q, int k) {
  int ans = 0, n = Q.size();
  for (int i = 0; i < n; i++) top[i] = 1e9;
  for (int i = 0; i < n; i++) {
    int find = upper_bound(top, top+n, Q[i])-top;
    top[find] = Q[i];
    ans = max(ans, find);
  }
  return (int)ceil(log(ans+1)/log(k));
}