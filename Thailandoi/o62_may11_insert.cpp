#include<bits/stdc++.h>
using namespace std;

int a[200100], mn[200100], mx[200100], qs[200100];
char s[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  cin >> a[1]; for (int i = 2; i <= n; i++) cin >> s[i] >> a[i];
  for (int i = 1; i <= n; i++) qs[i] = qs[i-1] + a[i];

  mx[n] = mn[n] = a[n];
  int l = n;
  for (int i = n; i >= 1; i--) if (s[i] == '-') { // O(n) in here is fine cus it amotize O(1)
    mn[i] = -qs[l-1]+qs[i-1]+min(mn[l], - mx[l]);
    mx[i] = max(-a[i]+qs[l-1]-qs[i]+mx[l], -qs[l-1]+qs[i-1]-mn[l]);
    l = i;
  }
  cout << qs[l-1]-qs[0]+mx[l];
  return 0;
}