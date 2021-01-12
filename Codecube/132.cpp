#include<bits/stdc++.h>
using namespace std;

long long four (int n){
	if (n == 1) return 4;
	long long k = four(n/2)*four(n/2);
	if (n&1) return k*4;
	return k;

}

int main(){
	int n;
	scanf("%d", &n);
	printf("%lld", four(n));
	return 0;
}
