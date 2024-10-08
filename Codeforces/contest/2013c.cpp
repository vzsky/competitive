#include<bits/stdc++.h>
using namespace std;


int main () {
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int r;
    
    string now = "";
    cout << "? 0" << endl; 
    cin >> r;
    if (r) {now += '0';}
    else {now += '1';}

    while (now.size() < n) {
      cout << "? " << now << 0 << endl;
      cin >> r;
      if (r) { now += '0'; continue; }
      
      cout << "? " << now << 1 << endl;
      cin >> r;
      if (r) {now += '1'; continue; }

      break;
    }


    while (now.size() < n){
      cout << "? " << 0 << now << endl;
      cin >> r;
      if (r) { now = '0' + now; continue; }
      
      now = '1' + now; continue; 
    }

    cout << "! " << now << endl;

  }

  return 0;
}
