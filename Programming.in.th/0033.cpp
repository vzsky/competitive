#include<bits/stdc++.h>
using namespace std;

int like[10001];

int main () {
  int n; cin >> n;
  int highest_like = 0;

  for (int i = 0; i < n; i++) {
    int entry; cin >> entry; 
    like[entry]++;
    highest_like = max(highest_like, like[entry]);
  }

  for (int i = 1; i <= 10000; i++) {
    if (highest_like == like[i]) cout << i << ' ';
  }

  return 0;
}
