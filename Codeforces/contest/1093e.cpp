#include<bits/stdc++.h>
using namespace std;

int pa[200100], pb[200100], a[200100], b[200100];

struct E { int t, x, y, v, i, sign; } e[1000100];
auto stime = [](E&a, E&b) { return a.t < b.t; };
auto sortx = [](E&a, E&b) { return a.x < b.x; };
vector<int> ans;

int fw[200100];
stack<pair<int,int>> h;
void add (int a, int v) {h.push({a, v}); for (int i = a; i <= 200000; i+=(i&-i)) fw[i]+=v;}
int query (int a) {int r = 0; for (int i = a; i > 0; i-=(i&-i)) r+=fw[i]; return r;}
void clear () {while(!h.empty()) {auto t = h.top(); h.pop(); add(t.first, -t.second); h.pop();}}

void CDQ (int l, int r) {
    if (l == r) return;
    int m = (l+r)/2;
    CDQ(l, m); CDQ(m+1, r);
    sort(e+l, e+m+1, sortx); sort(e+m+1, e+r+1, sortx);
    int i = l, j = m+1;
    while (i <= m and j <= r) {
        // sort x small - big
        // find value that y less than added element
        if (e[i].x <= e[j].x) {
            if (e[i].v == 0) {i++; continue;}
            add(e[i].y, e[i].v);
            i++;
        }
        else {
            if (e[j].i == -1) {j++; continue;}
            ans[e[j].i] += e[j].sign*query(e[j].y);
            j++;
        }
    }
    while (j <= r) {
        if (e[j].i == -1) {j++; continue;}
        ans[e[j].i] += e[j].sign*query(e[j].y);  
        j++;
    }
    clear();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) { cin >> a[i]; pa[a[i]] = i; }
    for (int i = 1; i <= n; i++) { cin >> b[i]; pb[b[i]] = i; }
    // add 1 to every point pa[i], pb[i] for i in [1, n]
    int cnt = 0;
    for (int i = 1; i <= n; i++) e[++cnt] = {0, pa[i], pb[i], 1, -1, 0};

    for (int i = 1; i <= m; i++) {
        int t; cin >> t;
        if (t == 1) {
            int la, ra, lb, rb; cin >> la >> ra >> lb >> rb;
            // add element of quicksum la ra, lb rb
            ans.push_back(0);
            int s = ans.size()-1;
            e[++cnt] = {i, ra, rb, 0, s, 1};
            e[++cnt] = {i, la-1, rb, 0, s, -1};
            e[++cnt] = {i, ra, lb-1, 0, s, -1};
            e[++cnt] = {i, la-1, lb-1, 0, s, 1};
        }
        if (t == 2) {
            int x, y; cin >> x >> y;
            int l = b[x], r = b[y];
            // swap l r means
            e[++cnt] = {i, pa[l], pb[l], -1, -1, 0};  // minus one at a[l], b[l]
            e[++cnt] = {i, pa[r], pb[r], -1, -1, 0};  // minus one at a[r], a[r]
            e[++cnt] = {i, pa[r], pb[l], 1, -1, 0};   // add one at a[r], b[l]
            e[++cnt] = {i, pa[l], pb[r], 1, -1, 0};   // add one at b[l], a[r]

            b[x] = r; b[y] = l;
            pb[b[x]] = x; pb[b[y]] = y;
            
        }
    }
    sort(e+1, e+cnt+1, stime);
    CDQ(1, cnt);
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
    return 0;
}