#include<bits/stdc++.h>
using namespace std;

int numbers[1000];

int main () {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
  }

  sort(numbers, numbers+n);

  for (int i = n-1; i >= 0; i--) {
    if (numbers[i] == 0) swap(numbers[i], numbers[i+1]);
  }

  for (int i = 0; i < n; i++) {
    cout << numbers[i];
  }

  return 0;
}
