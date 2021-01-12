#include<bits/stdc++.h>
using namespace std;

int main(){
  double a, b;
  scanf("%lf %lf", &a, &b);
  printf("%.6lf", pow(a*a+b*b, 0.5));
  return 0;
}