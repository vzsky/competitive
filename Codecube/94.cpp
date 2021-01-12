#include<bits/stdc++.h>
using namespace std;

char str[100100];

int main(){
	int n;
	scanf("%d", &n);
	scanf(" %s", str);
	int l = strlen(str);
	for(int i = 1; i < l; i++){
		if(str[i]==str[i-1]) {
			printf("Wrong Answer");
			return 0;
		}
	}
	printf("Accepted");
	return 0;
}
