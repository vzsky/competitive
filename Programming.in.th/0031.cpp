#include<bits/stdc++.h>
using namespace std;

int cutting_times (int * sizes) {
  sort(sizes, sizes+3);
  if (sizes[2] == 1) return 0;
  sizes[2] = sizes[2] / 2;
  return 1 + cutting_times(sizes);
}

int main () {
  int sizes[3];
  for (int i = 0; i < 3; i++) cin >> sizes[i];
  cout << cutting_times(sizes);
  return 0;
}
