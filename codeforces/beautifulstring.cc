#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1265/A */
int main() {

  int t, flag;
  cin >> t;
  while (t--) {

    string s;
    cin >> s;

    int flag = (s.find("aa") != -1);
    flag |= (s.find("bb") != -1);
    flag |= (s.find("cc") != -1);
    if (flag) {
      cout << "-1" << endl;
      continue;
    }

    for (int i = 0; i < s.size(); i++) {
      if (s[i] != '?')
        continue;

      char prev = i - 1 < 0 ? '?' : s[i - 1];
      char next = i + 1 == s.size() ? '?' : s[i + 1];
      for (char c : "abc") {
        if (c != prev && c != next) {
          s[i] = c;
          break;
        }
      }
    }

    cout << s << endl;
  }
  return 0;
}
