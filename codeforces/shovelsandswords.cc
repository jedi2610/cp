#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1366/A */

/* it is important to realize that the grouping of diamonds and sticks doesn't
 * matter, which ofc i didn't */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll a, b, ans = 0;
    cin >> a >> b;
    ans = min(a, b);
    ans = min(ans, (a + b) / 3);
    cout << ans << endl;
  }
  return 0;
}
