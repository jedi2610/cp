#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int getDigits(ll n) { return log10(n) + 1; }

/* https://codeforces.com/problemset/problem/1060/B */
int main() {
  ll n, ans = 0, count;
  cin >> n;
  count = getDigits(n) - 1;
  ll n1 = pow(10, count) - 1;
  ll n2 = n - n1;

  while (n2 > 0) {
    ans += (n2 % 10);
    n2 /= 10;
  }
  ans += (9 * count);

  cout << ans;
  return 0;
}
