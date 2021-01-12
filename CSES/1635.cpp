#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7, n, c[110], a[1000010], x;

int main(){
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; i++) scanf("%d",&c[i]);
  sort(c, c+n);

  a[0] = 1;

  for (int j = 1; j <= x; j++) {
    for (int i = 0; i < n; i++) {
      if (j-c[i] < 0) break;
      a[j] += a[j-c[i]];
      if (a[j] > mod) a[j]-=mod;
    }
  }

  printf("%d\n", a[x]);

  return 0;
}