#include<bits/stdc++.h>
using namespace std;

int n, sum=0;
int a[500100], ans[500100], fw[500100], used[500100];
void add (int a) { for (int i = a; i <= n; i+=(i&-i)) fw[i]++; sum++; }
int query (int a) { int ans = 0; for (int i = a; i > 0; i-=(i&-i)) ans+=fw[i]; return ans; }
int find (int a) { return sum-query(a-1); }
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  
  for (int i = n; i >= 1; i--) {
    int l = 1, r = n;
    while (l < r) {
      int mid = (l+r)/2;
      if (n - mid - find(mid) > a[i]) l = mid+1;
      else if (n - mid - find(mid) < a[i]) r = mid-1;
      else if (used[mid]) l = mid+1;
      else l = r = mid;
    }
    ans[i] = l;
    add(ans[i]);
    used[ans[i]] = 1;
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
  return 0;
}