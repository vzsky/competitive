#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> v;
#define x first
#define y second

int main(){
	int n, a, b;
	scanf(" %d", &n);
   for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		v.push_back({a, b});
	}
	sort(v.begin(), v.end());
	int cnt = 1;
	for(int i = 0; i < n; i++){
		if (i == 0) continue;
		if (v[i].x == v[i-1].x && v[i].y == v[i-1].y) continue;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
