#include<bits/stdc++.h>
using namespace std;

char str[30];

int main(){
	int t;
	scanf("%d", &t);
	for(int x = 1; x <= t; x++){
		printf("Case #%d: ", x);
		scanf(" %s", str);
		int X=0, W=0, T=0;
		int l = strlen(str);
		for(int i = 0; i < l; i++){
			//cerr << str[i];
			if (str[i] == 'X') X = 1;
			if (str[i] == '-') W = 1;
			if (str[i] == 'T') T = 1;
		}
		if (X) { printf("No - Runtime error\n"); continue; }
		if (T) { printf("No - Time limit exceeded\n"); continue; }
		if (W) { printf("No - Wrong answer\n"); continue; }
		printf("Yes\n");
	}
}
