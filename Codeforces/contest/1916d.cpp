#include<bits/stdc++.h>
using namespace std;

void find (int n, int z) {

  if (n == 3) {
    cout << "169";
    for (int i = 0; i < z; i++) cout << "0";
    cout << "\n";
    cout << "196";
    for (int i = 0; i < z; i++) cout << "0";
    cout << "\n";
    cout << "961";
    for (int i = 0; i < z; i++) cout << "0";
    cout << "\n";
    return;
  }
  
  find(n-2, z+2);

  int m = (n-3)/2;
  cout << "1"; 
  for (int i = 0; i < m; i++) cout << "0";
  cout << "6"; 
  for (int i = 0; i < m; i++) cout << "0";
  cout << "9"; 
  for (int i = 0; i < z; i++) cout << "0";
  cout << "\n"; 
  cout << "9"; 
  for (int i = 0; i < m; i++) cout << "0";
  cout << "6"; 
  for (int i = 0; i < m; i++) cout << "0";
  cout << "1"; 
  for (int i = 0; i < z; i++) cout << "0";
  cout << "\n";
}

int main () {

  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    if (n == 1) {cout << "1\n"; continue;}
    find(n, 0);
  }

  return 0;
}
