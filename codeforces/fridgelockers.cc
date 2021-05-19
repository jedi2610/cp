#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/blog/entry/71562?#comment-559266 */
/* https://codeforces.com/problemset/problem/1255/B */
/* https://codeforces.com/blog/entry/71562 */
int main() {

  int t, temp;
  cin >> t;
  while (t--) {
    int n, m, sum = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      sum += temp;
    }
    if (m < n || n == 2) {
      cout << "-1" << endl;
      continue;
    }
    cout << 2 * sum << endl;
    for (int i = 1; i < n; i++)
      cout << i << " " << i + 1 << endl;
    cout << n << " " << 1 << endl;
  }
  return 0;
}
