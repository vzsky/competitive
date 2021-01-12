#include<bits/stdc++.h>
using namespace std;

long long a[100][100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      long long b;
      cin >> b; cout << b+a[i][j] << ' ';
    }cout << endl;
  }
  return 0;
}