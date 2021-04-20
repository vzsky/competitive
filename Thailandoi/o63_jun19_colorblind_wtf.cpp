#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;

string investivate_colors (int N) {
  int delta = 1;
  string ans = "R";
  int old = use_device(0, 1);
  for (int i = 1; i < 2*(N-1); i+=2) {
    int now = use_device(i, i+1);
    int status2 = (delta > 0) ^ (now > old);
    if (now == old) {
      int s = (ans[i-1] == 'R' and delta-1 == 0) or (ans[i-1] == 'B' and 0 == delta+1);
      if ((((s and (use_device(i-1, i+1) == old)) or (!s and (use_device(i-1, i) == old)))?1:0) ^ (ans[i-1] == 'R')) { ans += "BB"; delta-=2; }
      else { ans += "RR"; delta+=2; }
    }
    else ans += ((delta > 0) ^ (now > old))?"RB":"BR";
  }
  ans += (delta > 0)?"B":"R";
	return ans;
}