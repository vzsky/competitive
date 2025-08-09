#include<bits/stdc++.h>	
using namespace std;		

int main () {		 
  int A, B, C;
  cin >> A >> B >> C;

  for (int a = 1; a <= 100; a++) {
    int c = A / a;
    if (a * c != A) continue;
    for (int b = -100; b <= 100; b++) {
      if (b == 0) {
        if (C != 0) continue;
        int d = B / a;
        if (a * d == B) {
          cout << a << ' ' << b << ' ' << c << ' ' << d; 
          return 0;
        }
      }
      int d = C / b;
      if (b * d != C) continue;
      if (a * d + b * c == B) {
        cout << a << ' ' << b << ' ' << c << ' ' << d; 
        return 0;
      }
    }
  }

  cout << "No Solution";
  return 0;	
}	
