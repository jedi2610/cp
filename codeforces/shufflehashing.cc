#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1278/A */
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s, h;
    cin >> s;
    cin >> h;
    int ss = s.size(), hs = h.size(), flag = 0;
    sort(s.begin(), s.end());

    for (int i = 0; i < hs; i++) {

      if (i + ss > hs)
        break;
      string st = h.substr(i, ss);
      sort(st.begin(), st.end());

      if (st == s) {
        cout << "YES" << endl;
        flag = 1;
        break;
      }
    }
    if (!flag)
      cout << "NO" << endl;
  }
  return 0;
}
