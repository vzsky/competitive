#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1; x <= t; x++){
		int a, b;
		int cnt = 0;
		scanf("%d %d", &a, &b);
		while (a < b) b-=20;
		b = min(a, b);
		// cout << b;
		while(b>=0){
			cnt++;
			b-=20;
		}
		printf("Case #%d: %d\n", x, cnt);
	}
}
