#include <bits/stdc++.h>
using namespace std;

int main () {
  int n; cin >> n;
  while (n--) {
    int m; cin >> m;

    int x = m / 5; 
    int y = m % 5;

    char v[10] = "aeiou";

    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < x; j++) printf("%c", v[i]);
      if (i < y) printf("%c", v[i]);
    }
    printf("\n");
  }
  return 0;
}

