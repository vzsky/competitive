#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

ordered_set<long long> t;
long long a[100100], qs[100100];
long long n, k; 

bool check (long long m) {
  t.clear();
  t.insert(0);
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += t.order_of_key(qs[i]-m+1);
    t.insert(qs[i]);
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
  }
  long long l = -2e11, r = 2e11;
  while (l < r) {
    long long mid = (l+r+1)/2;
    if (check(mid)) l = mid;
    else r = mid-1;
  }
  cout << l << endl;
  return 0;
}