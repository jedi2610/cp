/* such elegant and good taste of code from
 * https://codeforces.com/blog/entry/88344 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

bool solve() {
  string s;
  cin >> s;

  vector<int> d(3);
  int x = s[0] - 'A';
  int y = s.back() - 'A';
  if (x == y)
    return false;

  d[x] = 1;
  d[y] = -1;
  if (count(s.begin(), s.end(), 'A' + x) == s.length() / 2)
    d[3 ^ x ^ y] = -1;
  else
    d[3 ^ x ^ y] = 1;

  int bal = 0;
  for (char c : s) {
    bal += d[c - 'A'];
    if (bal < 0)
      return false;
  }
  return bal == 0;
}

int main() {

  int t;
  cin >> t;
  while (t--) {
    cout << (solve() ? "YES\n" : "NO\n");
  }
}
