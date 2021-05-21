#include <bits/stdc++.h>

using namespace std;
using ll = long long;

/* https://codeforces.com/problemset/problem/1051/B */
int main() {
  ll l, r;
  cin >> l >> r;
  cout << "YES" << endl;
  for (ll i = l; i < r; i += 2) {
    cout << i << " " << i + 1 << endl;
  }
  return 0;
}
