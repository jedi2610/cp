#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1334/B */
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, flag[] = {0, 0, 0, 0};
    vector<pair<int, int>> res;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> s;
      if (s[0] == 'S') {
        flag[0] = (int)s[1] - 48;
      } else if (i == 1) {
        flag[1] = (int)s[0] - 48;
        if (n == 3)
          flag[2] = (int)s.back() - 48;
      } else if (i == n - 2) {
        flag[2] = (int)s.back() - 48;
      } else if (s.back() == 'F') {
        flag[3] = (int)s[s.length() - 2] - 48;
      }
    }

    if (flag[0] == flag[1]) {
      if (flag[2] == flag[0])
        res.push_back({n - 1, n});

      if (flag[3] == flag[1])
        res.push_back({n, n - 1});
    } else if (flag[2] == flag[3]) {
      if (flag[0] == flag[2])
        res.push_back({1, 2});

      if (flag[1] == flag[3])
        res.push_back({2, 1});
    } else {
      int chosen = flag[0];
      res.push_back({2, 1});
      if (flag[2] == chosen)
        res.push_back({n - 1, n});
      else if (flag[3] == chosen)
        res.push_back({n, n - 1});
    }

    cout << res.size() << endl;
    for (auto i : res)
      cout << i.first << " " << i.second << endl;
  }
  return 0;
}
