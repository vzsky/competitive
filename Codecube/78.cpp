#include<bits/stdc++.h>
using namespace std;

char str[1010];
char mark[1010];
char f[] = "sipa";

int main(){
	int ans = -1;
	int x, a[6];
	scanf("%d %d %d %d %d %d", &x, a, a+1, a+2, a+3, a+4);
	int sum = a[0]+a[1]+a[2]+a[3]+a[4];
	if (sum == x) {
		for(int i = 0; i < 5; i++){
			printf("%d ", a[i]);
		}
		return 0;
	}
	for(int i = 0; i < 5; i++){
		if (sum-a[i]==x) {
			ans = i;
			break;
		}
	}
	if (ans == -1){
		printf("-1");
		return 0;
	}
	else {
		for(int i = 0; i < 5; i++){
			if (i==ans) {printf("0 "); continue;}
			printf("%d ", a[i]);
		}
	}
}
