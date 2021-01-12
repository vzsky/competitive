#include<bits/stdc++.h>
using namespace std;

char a[1010], b[1010];

int main(){
	scanf(" %s %s", a, b);
	if (strlen(a) != strlen(b)) printf("%d", (int)max(strlen(a), strlen(b)));
	else {
		if (strcmp(a, b) == 0) printf("-1");
		else printf("%d", (int)strlen(a));
	}
	return 0;
}