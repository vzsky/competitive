#include<bits/stdc++.h>
using namespace std; 

int main () {

  string price; 
  cin >> price;

  int mod_03 = 0, mod_11 = 0;
  // for (int i = 0; i < price.size(); i++) {
  //   int digit = (price[i] - '0');
  //   mod_03 = ((mod_03 * 10) + digit) %  3;
  //   mod_11 = ((mod_11 * 10) + digit) % 11;
  // }
  // cout << mod_03 << ' ' << mod_11 << endl;


  for (int i = 0; i < price.size(); i++) {
    int digit = (price[i] - '0');
    mod_03 += digit;
    mod_11 = digit - mod_11;
  }

  mod_03 %=  3;
  mod_11 %= 11; mod_11 += 11; mod_11 %= 11;

  cout << mod_03 << ' ' << mod_11 << endl;

  return 0;
}
