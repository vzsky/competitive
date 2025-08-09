#include<bits/stdc++.h>	
using namespace std;		

int combo (int n, int r) {
  long long result = 1;
  for (int i = r+1; i <= n; i++) result *= i;
  for (int i = 2; i <= n-r; i++)  result /= i;
  return result;
}

int main () {		 
  int n; cin >> n;
  long long answer = combo(n, n/2);
  if (n % 2 == 1) answer *= 2;
  cout << answer;
  return 0;	
}	
