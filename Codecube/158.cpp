#include<bits/stdc++.h>
using namespace std;

vector<int> p;
int mark[1010];

int main(){
	for(int i = 2; i <= 1000; i++){
		if (mark[i]) continue;
		p.push_back(i*i);
		for(int j = 2*i; j <= 1000; j += i) mark[j] = 1;
	}
	
	int a, b;
	scanf("%d %d", &a, &b);
	bool check = false;
	for(auto x : p) {
		if (x < a || x > b) continue;
		printf("%d ", x); check = true;
	}
	if (not check) printf("-1");
	return 0;
}