#include<bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a+b+c != 100) {
		printf("BUG");
		return 0;
	}
	int m = max(a, max(b, c));
	if ((a==b&&b==m) || (a==c&&c==m) || (c==b&&b==m)){
		printf("I DON'T KNOW");
		return 0;
	}
	if (m == a) printf("PAPER");
	if (m == b) printf("SCISSORS");
	if (m == c) printf("ROCK");
	return 0;
}
