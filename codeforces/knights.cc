#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1221/B */
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ((i + j) % 2 ? "B" : "W");
    }
    cout << endl;
  }
  return 0;
}
