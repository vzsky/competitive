#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <cstdlib>
#include <iostream>
#include "messy.h"

using namespace std;

namespace helper {

    set<string> set_;
    bool compiled = false;
    int n;
    vector<int> p;
    int w;
    int r;

    int read_int() {
        int x;
        cin >> x;
        return x;
    }

}

using namespace helper;


// A convenience function.
int get_p(int i) {
    int ret = p[i];
    return ret;
}

void wa() {
    printf("WA\n");
    exit(0);
}

int main() {
    n = read_int();
    w = read_int();
    r = read_int();
    p = vector<int>(n);
    for (int i = 0; i < n; i++) {
        p[i] = read_int();
    }
    vector<int> answer = restore_permutation(n, w, r);
    
    if (answer.size() != n) wa();

    for (int i = 0; i < n; i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++) {
        if (p[i] != answer[i]) wa();
    }
    printf("OK");

    return 0;
}


bool check(const string& x) {
    if ((int)x.length() != n) {
        return false;
    }
    for (int i = 0; i < n; i++) {
        if (x[i] != '0' && x[i] != '1') {
            return false;
        }
    }
    return true;
}

void add_element(string x) {
    if (--w < 0 || compiled || !check(x)) {
        wa();
    }
    set_.insert(x);
}

bool check_element(string x) {
    if (--r < 0 || !compiled || !check(x)) {
        wa();
    }
    return set_.count(x);
}

void compile_set() {
    if (compiled) {
        wa();
    }
    compiled = true;
    set<string> compiledSet;
    string compiledElement = string(n, ' ');
    for (set<string>::iterator it = set_.begin(); it != set_.end(); it++) {
        string s = *it;
        for (int i = 0; i < n; i++) {
            compiledElement[i] = s[get_p(i)];
        }
        compiledSet.insert(compiledElement);
    }
    set_ = compiledSet;
}
