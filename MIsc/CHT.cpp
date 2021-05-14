#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> line; 
#define m first
#define c second

ll x[1000100], qs[1000100], dp[1000100];
ll a, b, c;

line l[1000100];
int front = 0, back = 0;


/*
max envelope
adding increase monotonically
querying increase monotonically
*/

bool bad (line &a, line &b, line c) { return (a.c-c.c)*(b.m-a.m) < (a.c-b.c)*(c.m-a.m); }
void add (ll m, ll c) {
    while (back >= 2 and bad(l[back-2], l[back-1], {m, c})) back--;
    l[back++] = {m, c};
}

ll query (ll x) {
    if (front >= back) front = back-1;
    while (front < back-1 and l[front].m*x+l[front].c < l[front+1].m*x+l[front+1].c) front++;
    return l[front].m * x + l[front].c;
}