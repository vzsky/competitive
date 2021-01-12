#include<bits/stdc++.h>
using namespace std;

int a[10];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int sum = 0;
  for (int i = 0; i < 9; i++) {cin >> a[i]; sum += a[i];}
  
  pair<int,int> save;
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (a[i]+a[j]+100 == sum) {
        save = {i, j};
      }
    }
  }

  for (int i = 0; i < 9; i++) {
    if (i == save.first or i == save.second) continue;
    cout << a[i] << endl;
  }

  return 0;
}