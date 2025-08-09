#include<bits/stdc++.h>
using namespace std;

long long f (int n) {
  long long answer = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n+i; j++) {
      for (int k = 1; k <= n+i+j; k++) {
        answer += (1ll * i * j * k) % (i + j + k);
      }
    }
  }
  return answer;
}

int main () {
  cout << "#include<bits/stdc++.h>\nusing namespace std;\n\n";
  cout << "vector<long long> answers = {";
  for (int n = 1; n <= 300; n++) {
    cout << f(n) << ", ";
  }
  cout << "};\n\n";
  cout << "int main () {\n\tint q; cin >> q;\n\twhile (q--) {\n";
  cout << "\t\tint n; cin >> n;\n\t\tcout << answers[n-1] << endl;\n\t}\n\treturn 0;\n}";
  return 0;
}

