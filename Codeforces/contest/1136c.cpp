#include<bits/stdc++.h>
using namespace std;

int mat[520][520];
vector<int> v;
vector<vector<int>> vec;

map <vector<vector<int>>,int> mp;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < m+n-1; i++){
        v.clear();
        for(int j = 0; j < m; j++){
            int x = i-j, y = j;
            //cout << i << ' ' << j << ' ' << x << ' ' << y << endl;
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            //cout << x << ' ' << y << ' ' << mat[x][y] << endl;
            v.push_back(mat[x][y]);
        }
        sort(v.begin(), v.end());
        vec.push_back(v);
        //for(auto i : v) cout << i;
    }

    // cout << endl << "VEC";
    // for (auto i : vec){
    //     for(auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    mp[vec] = 1;
    vec.clear();
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < m+n-1; i++){
        v.clear();
        for(int j = 0; j < m; j++){
            int x = i-j, y = j;
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            v.push_back(mat[x][y]);
        }
        sort(v.begin(), v.end());
        vec.push_back(v);
    }

    // cout << endl << "VEC";
    // for (auto i : vec){
    //     for(auto j : i){
    //         cout << j << ' ';
    //     }
    //     cout << endl;
    // }

    if (mp.count(vec)) printf("YES");
    else printf("NO");

    return 0;
}