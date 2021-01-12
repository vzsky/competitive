#include<bits/stdc++.h>
using namespace std;

string a[100100];
int l[100100], r[100100];

int b = 0;
int e = 1;
int it = 1;
int c = 2;

int main(){

    // ios_base::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n;
    char o;

    l[e] = b;
    l[b] = b;
    r[e] = e; 
    r[b] = e;

    for(int i = 0; i < n; i++){
        cin >> o;
        if (it == b) it = r[b];
        if (o == 'i') {
            cin >> a[c];
            r[l[it]] = c;
            l[c] = l[it];
            r[c] = it;
            l[it] = c;
            c++;
            // it = r[it];
        }
        if (o == 'l') {
            it = l[it];
        }
        if (o == 'r') {
            it = r[it];
        }
        if (o == 'b') {
            it = l[it];
            if (it == b) { it = r[it]; continue;}
            r[l[it]] = r[it];
            l[r[it]] = l[it];
            it = r[it];
        }
        if (o == 'd') {
            if (it == e) continue;
            r[l[it]] = r[it];
            l[r[it]] = l[it];
            it = r[it];
        }

        // for(int i = r[b]; i != e; i=r[i]){
        //     cout << a[i] << ' ';
        // }
        // cout << " : " << (it==e?"end":a[it]) << endl;
        // cout << endl;

    }
    
    for(int i = b; i != e; i=r[i]){
        cout << a[i] << ' ';
    }

    return 0;
}