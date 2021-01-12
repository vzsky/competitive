#include <bits/stdc++.h>
#include "cave.h"

void exploreCave(int n) {
    // ith switch connected to door d[i]
    // door i connected to s[i]
    // correct condition of switch i is cc[i]
    int d[n], s[n], cc[n];
    for (int i = 0; i < n; i++) d[i] = s[i] = cc[i] = -1;
    for (int i = 0; i < n; i++) {
        // find door i answer
        int c[n];
        for (int j = 0; j < n; j++) c[j] = 0;
        for (int j = 0; j < i; j++) c[s[j]] = cc[s[j]];
        // // cerr << "try cond "; for (int i = 0; i < n; i++) cerr << c[i]; cerr << " is " << tryCombination(c) << endl;
        int res = tryCombination(c);  assert(res >= i or res == -1);
        int cond = (res > i or res == -1) ? 0 : 1;
        // cerr << "open when " << cond << endl;
        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l+r)/2;
            for (int j = 0; j < n; j++) c[j] = 0;
            for (int j = l; j <= mid; j++) c[j] = cond;
            for (int j = mid+1; j <= r; j++) c[j] = cond^1;
            // cerr << "now we have "; for (int i = 0; i < n; i++) cerr << c[i]; cerr << endl;
            for (int j = 0; j < i; j++) c[s[j]] = cc[s[j]];
            // cerr << "result of "; for (int i = 0; i < n; i++) cerr << c[i]; cerr << " is " << tryCombination(c) << endl;
            int res = tryCombination(c);  assert(res >= i or res == -1);
            if (res > i or res == -1) r = mid;
            else l = mid+1;
        }
        // switch l control door i 
        // cerr << "switch " << l << " door " << i << endl;
        d[l] = i; s[i] = l; cc[l] = cond;
    }
    assert(tryCombination(cc) == -1);
    answer(cc, d);
}
