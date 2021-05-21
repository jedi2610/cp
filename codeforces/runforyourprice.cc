#include <bits/stdc++.h>

using namespace std;
using ll = long long;
int MID = 1e6 / 2;
int MAX = 1e6;

/* https://codeforces.com/problemset/problem/938/B */
int main() {

  int n, pos, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> pos;
    ans = max(ans, min(pos - 1, MAX - pos));
  }

  /* why is this not working? */
  /* https://codeforces.com/contest/938/submission/116910884 */
  cout << ans << endl;

  return 0;
}
