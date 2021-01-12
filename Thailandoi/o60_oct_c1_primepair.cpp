#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pip;
int num[1000100], cnt[1000100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c, d; cin >> a >> b >> c >> d;
  pip mx = {0, {0, 0}};
  iota(num, num+d+1, 0);
  for (int i = 2; i <= d; i++) {
    if (num[i] != 1) {
      for (int j = 2*i; j <= d; j+=i) {
        num[j]/=num[i]; cnt[j]++;
      }
      num[i]=1; cnt[i]++;
    }

    int x = b-(b%i), y = d-(d%i);
    if (a <= x and c <= y) {
      pip sim = {cnt[i], {x+y, x}};
      if (sim > mx) mx = sim;
    }
  }

  cout << mx.second.second << ' ' << mx.second.first-mx.second.second << endl;
  return 0;
}