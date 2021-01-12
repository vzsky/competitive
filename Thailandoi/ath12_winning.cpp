#include<bits/stdc++.h>
using namespace std;

int a[30], qs[30], N, M, P, flag;
void permu (int n, int m) {
  if (m == 1) {
    a[1] = n+1; qs[1] = n+1 + qs[2];
    for (int j = 2; j <= M+1; j++)
      if (qs[1]-qs[j] == P) return;
    flag = 0;
    return;
  }
  for (int i = 1; i <= n+1; i++) {
    if (!flag) return;
    a[m] = i; qs[m] = i + qs[m+1];
    for (int j = m+1; j <= M+1; j++)
      if (qs[m]-qs[j] == P) goto nextLoop;
    permu(n-i+1, m-1);
    nextLoop : continue;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> N >> M >> P) {
    flag = 1;
    qs[M+1] = 0;
    permu(N-M, M);
    cout << (flag? "yes\n" : "no\n");
  }
  return 0;
}