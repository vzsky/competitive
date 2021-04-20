#include "rumors.h"
#include <bits/stdc++.h>
using namespace std;

int around[2020][2020];
int d[2020], delta[2020], qs[2020];

vector<int> analyze_rumors(int N, int K, int Q, vector<int> D, vector<int> x, vector<int> j) {
  vector<int> ans;
  
  for (int i = 1; i <= N; i++) d[i] = D[i-1];
  for (int i = 2; i <= N; i++) {
    delta[i] = (d[i]-d[i-1]-1)/K; // delta[i] is i-1 -> i
    qs[i] = qs[i-1] + delta[i];
  }

  for (int k = 1; k < N; k++) {

    deque<pair<int,int>> sw;
    for (int i = 1; i <= N+1; i++) {
      if (i-1 >= 1) {
        while (sw.front().second < i-k-1) sw.pop_front();
        around[i-1][k] = sw.front().first;
      }
      if (i+k <= N) {
        int now = qs[i+k]-qs[i];
        while (!sw.empty() and now < sw.back().first) sw.pop_back();
        sw.push_back({qs[i+k]-qs[i], i});
      }
    }

  }

  for (int i = 0; i < Q; i++) {
    int l = 0, r = N-1; 
    while (l < r) {
      int mid = (l+r+1)/2;
      if (around[x[i]+1][mid] <= j[i]) l = mid;
      else r = mid-1;
    }
    ans.push_back(l+1);
  }

  return ans;
}
