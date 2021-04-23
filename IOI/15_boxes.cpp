#include "boxes.h"
#include <bits/stdc++.h>
using namespace std;
 
long long cwtour[10000100], cwwtour[10000100];
long long delivery(int N, int K, int L, int p[]) {
 
  for (int i = 0; i < N; i++) cwtour[i] = p[i] + (i<K? 0 : cwtour[i - K]);
  for (int i = N-1; i >= 0; i--) cwwtour[i] = L-p[i] + (i+K>=N? 0 : cwwtour[i + K]);
 
  long long ans = 1e18;
  ans = min(ans, 2 * cwtour[N - 1]);
  ans = min(ans, 2 * cwwtour[0]);
  for (int i = 0; i < N-1; i++) ans = min(ans, 2*cwtour[i]+2*cwwtour[i+1]);
  if (K < N) {
    ans = min(ans, L + 2 * cwwtour[K]);
    ans = min(ans, L + 2 * cwtour[N - K - 1]);
    for (int i = 1; i + K < N; i++) ans = min(ans, 2 * cwtour[i - 1] + L + 2 * cwwtour[i + K]);
  }
  if (K >= N) ans = min(ans, (long long) L);
 
  return ans;
}