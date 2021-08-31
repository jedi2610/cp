#include <iostream>
#include <math.h>

using namespace std;
using ll = long long;

ll getNum(ll n) {
  if (n == 1)
    return n;

  ll i = 2;
  while (i <= sqrt(n)) {
    if (n % i == 0)
      return n / i;
    i++;
  }
  return 1;
}

int main() {
  ll n, ans;
  cin >> n;
  ans = n;
  while (n > 1) {
    ll temp = getNum(n);
    ans += temp;
    n = temp;
  }

  cout << ans << endl;
  return 0;
}
