#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1230/B */
int main() {

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  if (k == 0) {
    cout << s << endl;
    return 0;
  }
  if (s.size() == 1) {
    cout << "0" << endl;
    return 0;
  }

  if (s[0] != '1') {
    s[0] = '1';
    k--;
  }
  for (int i = 1; i < n && k; i++) {
    if (s[i] != '0') {
      s[i] = '0';
      k--;
    }
  }

  cout << s << endl;
  return 0;
}
