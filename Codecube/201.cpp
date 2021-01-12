#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		long long r, p, s;
		scanf("%lld %lld %lld", &r, &s, &p);
		if ((r == 1 and p == 0) or (p == 1 and s == 0) or (s == 1 and r == 0)) printf("YES\n");
		else if (r == 0 or p == 0 or s == 0) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}