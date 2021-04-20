#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;

string investivate_colors (int N) {

  int cntr = 1;
  int cntb = 0;
	
  string ans = "R";
  int old = use_device(0, 1);
  for (int i = 1; i < 2*(N-1); i+=2) {
    int now = use_device(i, i+1);

    if (now == old) {
      if ((ans[i-1] == 'R' and cntr-1 == cntb) or (ans[i-1] == 'B' and cntb-1 == cntr)) { 
        if (use_device(i-1, i+1) == old) {
          if (ans[i-1] == 'R') {ans += "RR"; cntr+=2; }
          if (ans[i-1] == 'B') {ans += "BB"; cntb+=2; }
        }
        else {
          if (ans[i-1] == 'R') {ans += "BB"; cntb+=2; }
          if (ans[i-1] == 'B') {ans += "RR"; cntr+=2; }
        }
      }
      else {
        if (use_device(i-1, i) == old) {
          if (ans[i-1] == 'R') {ans += "RR"; cntr+=2; }
          if (ans[i-1] == 'B') {ans += "BB"; cntb+=2; }
        }
        else {
          if (ans[i-1] == 'R') {ans += "BB"; cntb+=2; }
          if (ans[i-1] == 'B') {ans += "RR"; cntr+=2; }
        }
      }
    }

    else if (cntr > cntb and now > old) ans += "BR";
    else if (cntr > cntb and now < old) ans += "RB";
    else if (cntr < cntb and now > old) ans += "RB";
    else if (cntr < cntb and now < old) ans += "BR";
  }

  if (cntr > cntb) ans += "B";
  else ans += "R";

	return ans;
}