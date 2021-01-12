#include <bits/stdc++.h>
#include "grader.h"
#include "memory.h"
using namespace std;
 
void play() {
   map<char, vector<int> > m;
 
   for (int i=1; i<=50; i+=2) {
      m[faceup(i)].push_back(i);
      m[faceup(i+1)].push_back(i+1);
   }
   for (auto x : m) {
      faceup(x.second[0]);
      faceup(x.second[1]);
   }
}