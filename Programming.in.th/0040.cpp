#include<bits/stdc++.h>	
using namespace std;		

int main () {		 
  int n; cin >> n;
  
  while (n--) {
    string number; cin >> number;
    int last_digit = number[number.size()-1] - '0';

    if (number == "2") cout << "T\n";
    else if (last_digit % 2 == 1) cout << "T\n"; 
    else cout << "F\n";
  }

  return 0;	
}	
