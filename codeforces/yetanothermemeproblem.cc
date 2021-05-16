#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int count_digits(ll number) { return int(log10(number) + 1); }

/* https://codeforces.com/problemset/problem/1288/B */
int main() {

  int t;
  cin >> t;
  while (t--) {
    ll a, b, total = 0;
    cin >> a >> b;
    for (ll x = 9; x <= b; x = 10 * x + 9)
      total += a;
    cout << total << endl;
  }
  return 0;
}
