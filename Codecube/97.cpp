#include<bits/stdc++.h>
using namespace std;

stack <int> s;

int main(){
	int n;
	scanf("%d", &n);
	int r = pow(n, 0.5);
	for(int i = 1; i <= r; i++){
		if (n%i==0 && n/i==i){ printf("%d ", i); continue; }
		if (n%i==0) {
			printf("%d ", i);
			s.push(n/i);
		}
	}
	while(!s.empty()){
		printf("%d ", s.top());
		s.pop();
	}
	return 0;
}
