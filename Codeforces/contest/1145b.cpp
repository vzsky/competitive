#include<bits/stdc++.h>
using namespace std;

bool kb[110];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<int> a = {1, 7, 9, 10, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 31, 37, 39, 41, 47, 49, 51, 57, 59, 61, 67, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 81, 87, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99};
    for (auto x : a) kb[x] = true;
    if (kb[n]) cout << "NO";
    else cout << "YES";
    return 0;
}