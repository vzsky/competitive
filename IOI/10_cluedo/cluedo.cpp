#include "grader.h"
#include "cluedo.h"

void Solve(){
   int r, m = 1, l = 1, w = 1;
   r = Theory(m, l, w);
   while (r != 0) {
      if (r == 1) m++;
      if (r == 2) l++;
      if (r == 3) w++;
      r = Theory(m, l, w);
   }
   return;
}