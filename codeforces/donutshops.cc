#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1373/A */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << ((a < c) ? 1 : -1) << " ";
    cout << ((a * b <= c) ? -1 : b) << endl;
  }
  return 0;
}
