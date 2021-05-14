#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

const int N = 100000;
long long a[100100], qs[100100], fw[100100], n, k;
vector<long long> s;

bool check (long long m) {
  memset(fw, 0, sizeof fw);
  long long ans = 0;
  for (int j = lower_bound(all(s), 0)-s.begin()+1; j <= N; j+=(j&-j)) fw[j]++;
  for (int i = 1; i <= n; i++) {
    for (int j = upper_bound(all(s), qs[i]-m)-s.begin(); j > 0; j-=(j&-j)) ans += fw[j];
    for (int j = lower_bound(all(s), qs[i])-s.begin()+1; j <= N; j+=(j&-j)) fw[j]++;
  }
  return ans >= k;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    qs[i] = qs[i-1]+a[i];
    s.push_back(qs[i]);
  } 
  s.push_back(0);
  sort(all(s)); s.resize(unique(all(s))-s.begin());
  long long l = -2e12, r = 2e12;
  while (l < r) {
    long long mid = (l+r+1)/2;
    if (check(mid)) l = mid;
    else r = mid-1;
  } 
  cout << l << endl;
  return 0;
}