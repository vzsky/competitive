#include<bits/stdc++.h>	
using namespace std;		

int main () {		 
  int q; scanf("%d", &q);
  while (q--) {
    int n; cin >> n;
    printf("%.0Lf\n", powl(2, n));
  }
  return 0;	
}	
