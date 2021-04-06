#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

bool isinteger(float k) { return floor(k) == k; }

bool issumofcubes(ll x) {

  for (ll a = 1; a <= cbrt(x); a++) {
    ll b = cbrt(x - pow(a, 3));
    if (b > 0 && ((b * b * b) + (a * a * a)) == x)
      return 1;
  }
  return 0;
}

int main() {

  ll x;
  int t;
  cin >> t;
  while (t--) {
    cin >> x;
    if (issumofcubes(x))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
