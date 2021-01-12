#include "colorblind.h"
#include <bits/stdc++.h>
using namespace std;

std::string investivate_colors(int N) {

  int cntr = 1;
  int cntb = 0;
	
  string ans = "R";
  int old = use_device(0, 1);
  for (int i = 1; i < 2*(N-1); i+=2) {
    int now = use_device(i, i+1);

    if (cntr > cntb) {
      if (now > old) {
        ans += "BR";
        cntb++;
        cntr++;
      }
      else if (now < old ) { 
        ans += "RB";
        cntr++;
        cntb++;
      }
      else {
        if (use_device(0, i+1) != old) {
          ans += "BB";
          cntb+=2;
        }
        else if (use_device(0, i) != old) {
          ans += "BB";
          cntb+=2;
        }
        else  {
          ans += "RR";
          cntr+=2;
        }
      }
    }

    else if (cntb > cntr) {
      if (now > old) {
        ans += "RB";
        cntb++;
        cntr++;
      }
      else if (now < old ) { 
        ans += "BR";
        cntr++;
        cntb++;
      }
      else {
        if (use_device(0, i+1) != old) {
          ans += "BB";
          cntb+=2;
        }
        else if (use_device(0, i) != old) {
          ans += "BB";
          cntb+=2;
        }
        else  {
          ans += "RR";
          cntr+=2;
        }
      }
    }
  }

  if (cntr == N) {
    ans += "B";
  }
  else ans += "R";

  

	return ans;
}