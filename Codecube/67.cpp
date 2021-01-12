#include<bits/stdc++.h>
using namespace std;

char str[1010];
char mark[1010];
char f[] = "sipa";

int main(){
	int cnt = 0;
	scanf(" %s", str);
	int l = strlen(str);
	for(int i = 0; i < l; i++){
		int ch = 1;
		for(int j = 0; j < 4; j++){
			if (tolower(str[i+j]) != f[j]) ch = 0;
			else continue;
		}
		if (ch) { mark[i] = 1; cnt++; }
	}

	for(int i = 0; i < l; i++){
		if (mark[i]) printf("\"");
		if (mark[i-4]) printf("\"");
		printf("%c", str[i]);
	}
	if (mark[l-4]) printf("\"");
	printf("\n%d", cnt);

	return 0;
}
